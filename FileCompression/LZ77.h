#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "HashTable.h"
#include <iostream>
#include <string>
#include <assert.h>

class LZ77
{
public:
	LZ77()
		:m_pWin(new unsigned char[W_SIZE * 2])
		,m_HTable(W_SIZE)
		, m_start(0)
	{}

	~LZ77()
	{
		if (m_pWin)
		{
			delete[] m_pWin;
			m_pWin = nullptr;
		}
	}

public:
	void LZ77Compress(const std::string &Name);
	void LZ77UnCompress(const std::string &Name);
	std::string GetFileExtensio(const std::string& Name);
	std::string GetFilepath(const std::string& Name);

private:
	unsigned char LongMatch(unsigned short MatchHead, unsigned char &MatchDist);

private:
	unsigned char *m_pWin;
	unsigned short m_start;
	HashTable m_HTable;
};

std::string LZ77::GetFileExtensio(const std::string& Name)
{
	size_t pos = Name.find_last_of('.');
	return Name.substr(pos);
}

std::string LZ77::GetFilepath(const std::string& Name)
{
	size_t pos = Name.find_last_of('.');
	return Name.substr(0, pos);
}

unsigned char LZ77::LongMatch(unsigned short MatchHead, unsigned char &MatchDist)
{
	unsigned char MatchLen = 0;
	unsigned char MaxLen = 0;
	unsigned short pos = 0;
	do
	{
		MatchLen = 0;
		unsigned char *sStart = m_pWin + m_start;
		unsigned char *cStart = m_pWin + MatchHead;
		unsigned char *cEnd = cStart + MAX_MATCH;

		while ((cStart < cEnd) && (*sStart  == *cStart))
		{
			sStart++;
			cStart++;
			MatchLen++;
		}
		if (MatchLen > MaxLen)
		{
			MaxLen = MatchLen;
			pos = MatchHead;
		}
	} while (MatchHead = m_HTable.GetNext(MatchHead));
	MatchDist = m_start - pos;
	return MaxLen;
}

void LZ77::LZ77Compress(const std::string &Name)
{
	FILE *fin = fopen(Name.c_str(), "rb");
	if (nullptr == fin)
	{
		std::cout << "打开文件失败" << std::endl;
		return;
	}
	std::cout << "打开文件成功" << std::endl;

	// 获取文件大小
	fseek(fin, 0, SEEK_END);
	unsigned long long CompressSize = ftell(fin);
	fseek(fin, 0, SEEK_SET);
	if (CompressSize < 3)
		return;

	size_t ReadSize = fread(m_pWin, 1, 2 * W_SIZE, fin);

	unsigned short HashAddr = 0;
	for (size_t i = 0; i < MIN_MATCH; ++i)
	{
		m_HTable.HashFunc(HashAddr, m_pWin[i]);
	}

	// 后缀
	FILE *foutD = fopen("first.lzp", "wb");
	assert(foutD);
	std::string FileExtensio = GetFileExtensio(Name);
	FileExtensio += '\n';
	fwrite(FileExtensio.c_str(), 1, FileExtensio.size(), foutD);
		
	FILE *foutB = fopen("second.lzp", "wb");
	assert(foutB);

	unsigned short MatchHead = 0;
	unsigned char flag = 0;
	unsigned char count = 0;

	while (ReadSize)
	{
		m_HTable.Insert(HashAddr, m_pWin[m_start + 2], m_start, MatchHead);
		if (0 == MatchHead)
		{
			fputc(m_pWin[m_start], foutD);
			++m_start;
			--ReadSize;

			flag <<= 1;
			count++;
			if (8 == count)
			{
				fputc(flag, foutB);
				flag = 0;
				count = 0;
			}
		}
		else
		{
			//////////////////////////////////////////////////////////////
			unsigned char MatchDist = 0;
			unsigned char MatchLen = LongMatch(MatchHead, MatchDist);
			fputc(MatchDist, foutD);
			fputc(MatchLen, foutD);
			flag <<= 1;
			flag |= 1;
			count++;
			if (8 == count)
			{
				fputc(flag, foutB);
				flag = 0;
				count = 0;
			}

			ReadSize -= MatchLen;

			MatchLen -= 1;
			while (MatchLen)
			{
				++m_start;
				m_HTable.Insert(HashAddr, m_pWin[m_start + 2], m_start, MatchHead);
				MatchLen--;
			}
			++m_start;
		}
	}
	if (count > 0 && count < 8)
	{
		flag <<= (8 - count);
		fputc(flag, foutB);
	}
	fclose(fin);
	fclose(foutB);
	// 把 rb 写成了 wb
	FILE *finB = fopen("second.lzp", "rb");
	assert(finB);
	unsigned char *ReadBuff = new unsigned char[1024];
	size_t FlagSize = 0;
	while (true)
	{
		size_t ReadSize = fread(ReadBuff, 1, 1024, finB);
		if (0 == ReadSize)
		{
			std::cout << "读取完毕" << std::endl;
			break;
		}
		FlagSize += ReadSize;
		fwrite(ReadBuff, 1, ReadSize, foutD);
	}
	fclose(foutB);
	fwrite(&CompressSize, sizeof(CompressSize), 1, foutD);
	fwrite(&FlagSize, sizeof(FlagSize), 1, foutD);

	fclose(foutD);
	remove("second.lzp");
}

void LZ77::LZ77UnCompress(const std::string &Name)
{
	FILE *finD = fopen(Name.c_str(), "rb");
	if (nullptr == finD)
	{
		std::cout << "打开文件失败" << std::endl;
		return;
	}
	std::cout << "打开文件成功" << std::endl;

	// 标记大小
	size_t FlagSize = 0;
	int offset = 0 - sizeof(FlagSize);
	fseek(finD, offset, SEEK_END);
	fread(&FlagSize, sizeof(FlagSize), 1, finD);

	// 源文件大小
	unsigned long long FileSize = 0;
	offset = 0 - sizeof(FlagSize) - sizeof(FileSize);
	fseek(finD, offset, SEEK_END);
	fread(&FileSize, sizeof(FileSize), 1, finD);

	FILE *finB = fopen(Name.c_str(), "rb");
	assert(finB);

	//////////////////////////////////////////////////////////////
	offset = 0 - (sizeof(FlagSize)+sizeof(FileSize) + FlagSize);

	fseek(finB, offset, SEEK_END);

	// 解压名
	std::string StrInformation;
	StrInformation.clear();
	fseek(finD, 0, SEEK_SET);
	ReadLine(finD, StrInformation);
	std::string compressFilepath = GetFilepath(Name);
	compressFilepath += StrInformation;

	//解压缩
	//FILE* fout = fopen(compressFilepath.c_str(), "wb");
	FILE* fout = fopen("test.txt", "wb");
	assert(fout);

	//FILE* fwin = fopen(compressFilepath.c_str(), "rb");
	FILE* fwin = fopen("test.txt", "rb");
	assert(fwin);

	unsigned char CharFlag = 0;
	char count = -1;
	while (FileSize)
	{
		if (count < 0)
		{
			CharFlag = fgetc(finB);
			count = 7;
		}

		if (CharFlag & (1 << count))
		{
			unsigned char dist = fgetc(finD);
			unsigned char len = fgetc(finD);
			// 重要
			fflush(fout);
			fseek(fwin, 0 - dist, SEEK_END);
			FileSize -= len;
			while (len)
			{
				unsigned char ch = fgetc(fwin);
				fputc(ch, fout);
				len--;
			}
		}
		else
		{
			unsigned char ch = fgetc(finD);
			fputc(ch, fout);
			FileSize -= 1;
		}
		count--;
	}
	fclose(finD);
	fclose(finB);
	fclose(fwin);
	fclose(fout);
}
