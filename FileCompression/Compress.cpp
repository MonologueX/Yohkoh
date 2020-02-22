#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "Compress.h"
#include <iostream>
#include <assert.h>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define READ_MAXSIZE 1024*1024

std::string Compress::GetFileExtensio(const std::string& CompressName)
{
	size_t pos = CompressName.find_last_of('.');
	return CompressName.substr(pos);
}

std::string Compress::GetFilepath(const std::string& CompressName)
{
	size_t pos = CompressName.find_last_of('.');
	return CompressName.substr(0, pos);
}

int Compress::GetHuffmanCode(Node root)
{
	if (nullptr == root)
	{
		return -1;
	}
	GetHuffmanCode(root->m_left);
	GetHuffmanCode(root->m_right);
	if (nullptr == root->m_left && nullptr == root->m_right)
	{
		Node cur = root;
		Node Parent = cur->m_parent;
		std::string& code = m_informations[cur->m_weight.m_ch].m_code;
		while (Parent)
		{
			if (Parent->m_left == cur)
			{
				code += '0';
			}
			else
			{
				code += '1';
			}
			cur = Parent;
			Parent = cur->m_parent;
		}
		reverse(code.begin(), code.end());
	}
	return 0;
}

void Compress::WriteHead(FILE *fout, const std::string& CompressName)
{
	std::string HeadInformation;
	HeadInformation += GetFileExtensio(CompressName);
	HeadInformation += '\n';
	std::string CodeInformation;
	char StrCount[32];
	size_t LineCount = 0;
	for (size_t i = 0; i < 256; i++)
	{
		if (m_informations[i].m_count != 0)
		{
			CodeInformation += m_informations[i].m_ch;
			CodeInformation += ',';
			// itoa((int)m_informations[i].m_count, head.StrCount, 10);
			// Windows 可以用 itoa
			sprintf(StrCount, "%d", (int)m_informations[i].m_count);
			CodeInformation += StrCount;
			CodeInformation += '\n';
			LineCount++;
		}
	}
	sprintf(StrCount, "%d", LineCount);
	std::cout << "Code 获取完毕" << std::endl;
	HeadInformation += StrCount;
	HeadInformation += '\n';
	HeadInformation += CodeInformation;
	fwrite(HeadInformation.c_str(), 1, HeadInformation.size(), fout);
}

int Compress::compress(const std::string& CompressName)
{
	///////////////////////////////////////////////
	//  1.获取源字符出现次数
	///////////////////////////////////////////////

	// 要加 b ,否则解压时可能读不完就解压结束
	FILE *fin = fopen(CompressName.c_str(), "rb");
	if (nullptr == fin)
	{
		std::cout << "打开文件失败" << std::endl;
		return -1;
	}
	std::cout << "打开文件成功" << std::endl;

	unsigned char *ReadBuff = new unsigned char[READ_MAXSIZE];
	size_t SourceCount = 0;
	while (1)
	{
		size_t ReadSize = fread(ReadBuff, 1, 1024, fin);
		if (0 == ReadSize)
		{
			//std::cout << "读取完毕" << std::endl;
			break;
		}
		//std::cout << "读取成功：[ReadSize] = " << ReadSize << std::endl;

		for (size_t i = 0; i < ReadSize; i++)
		{
			m_informations[ReadBuff[i]].m_count++;
			SourceCount++;
		}
	}
	std::cout << "源文件出现字符总数" << SourceCount << std::endl;
	

	///////////////////////////////////////////////
	//  2.创建哈夫曼树
	///////////////////////////////////////////////

	HuffmanTree<CharInformation> hf((m_informations));

	//////////////////////////////////////////////
	//  3.根据Huffman树来获取Huffman编码
	///////////////////////////////////////////////

	GetHuffmanCode(hf.GetRoot());
	std::cout << "哈夫曼编码获取成功" << std::endl;

	///////////////////////////////////////////////
	//  4.用每个字符的编码改写源文件
	///////////////////////////////////////////////

	std::string compressfile = GetFilepath(CompressName);//获取文件前缀
	compressfile += ".ggzip";//然后在前缀后面加上压缩之后的后缀
	std::cout << "压缩名" << compressfile << std::endl;

	// 打开文件
	FILE* fout = fopen(compressfile.c_str(), "wb");
	assert(fout);

	WriteHead(fout, CompressName);
	char pos = 0;
	char ptr = 0;
	// 特别重要
	fseek(fin, 0, SEEK_SET);

	int CompreeCount = 0;
	size_t WriteSize = 0;
	char* WriteBuff = new char[READ_MAXSIZE];
	while (true)
	{
		size_t ReadSize = fread(ReadBuff, 1, READ_MAXSIZE, fin);
		if (0 == ReadSize)
		{
			//std::cout << "读取完毕" << std::endl;
			break;
		}
		for (size_t i = 0; i < ReadSize; ++i)
		{
			std::string& code = m_informations[ReadBuff[i]].m_code;
			for (size_t j = 0; j < code.size(); ++j)
			{
				ptr <<= 1;
				if ('1' == code[j])
				{
					ptr |= 1;
				}
				pos++;
				if (pos == 8)
				{
					WriteBuff[WriteSize++] = ptr;
					if (READ_MAXSIZE == WriteSize)
					{
						fwrite(WriteBuff, 1, READ_MAXSIZE, fout);
						WriteSize = 0;//写完一次置0
					}
					//fputc(ptr, fout);
					CompreeCount++;
					pos = 0;
				}
			}
		}
	}

	//如果没满8个比特位
	if (pos > 0 && pos < 8)
	{
		WriteBuff[WriteSize++] = ptr <<= (8 - pos);
		fwrite(WriteBuff, 1, WriteSize, fout);
		//fputc(ptr, fout);
		CompreeCount++;
	}
	std::cout << "压缩了的字符个数：" << CompreeCount << std::endl;
	delete[]ReadBuff;
	delete[]WriteBuff;
	fclose(fin);
	fclose(fout);
	return 1;
}

/////////////////////////////////////////////////////////////
// 解压缩
/////////////////////////////////////////////////////////////
void ReadLine(FILE*fin, std::string& StrInformation)
{
	char c = fgetc(fin);
	while (c != '\n')
	{
		if (feof(fin))//读到结尾
		{
			return;
		}
		StrInformation += c;
		c = fgetc(fin);
	}
}

int Compress::uncompress(const std::string& CompressName)
{
	FILE* fin = fopen(CompressName.c_str(), "rb");
	assert(fin);

	// 获取后缀
	std::string StrInformation;
	StrInformation = '1';
	ReadLine(fin, StrInformation);
	std::string compressFilepath = GetFilepath(CompressName);
	compressFilepath += StrInformation;
	
	// 获取行数
	std::string StrLineCount;
	ReadLine(fin, StrLineCount);
	size_t LineCount = atoi(StrLineCount.c_str());

	// 获取字符信息
	std::string strcodeinformation;
	char ctemp = 0;
	int count = 0;

	//读每个字符出现的次数
	for (size_t i = 0; i < LineCount; i++)
	{
		strcodeinformation.clear();
		ReadLine(fin, strcodeinformation);
		// 换行出错
		if (strcodeinformation.empty())
		{
			strcodeinformation += '\n';
			ReadLine(fin, strcodeinformation);
		}
		count = atoi(strcodeinformation.c_str() + 2);
		m_informations[(unsigned char)strcodeinformation[0]].m_count = count;
	}

	//还原Huffman树
	HuffmanTree<CharInformation> ht(m_informations);

	//解压缩
	//FILE* fout = fopen(compressFilepath.c_str(), "wb");
	FILE* fout = fopen("test.kux", "wb");
	assert(fout);
	size_t WriteSize = 0;
	size_t pos = 8;

	//源文件一共有多少个字符
	Node cur = ht.GetRoot();
	// 防止最后一个字符出错
	CountType FileSize = cur->m_weight.m_count;

	size_t UnCompressCount = 0;

	char* ReadBuff = new char[READ_MAXSIZE];
	char* WriteBuff = new char[READ_MAXSIZE];
	while (true)
	{
		size_t ReadSize = fread(ReadBuff, 1, READ_MAXSIZE, fin);
		if (0 == ReadSize)
		{
			//std::cout << "读取完毕" << std::endl;
			break;
		}
		for (size_t i = 0; i < ReadSize; ++i)
		{
			pos = 8;
			while (pos--)
			{
				//叶子结点
				if (nullptr == cur->m_left && nullptr == cur->m_right)
				{
					WriteBuff[WriteSize++] = cur->m_weight.m_ch;
					if (WriteSize == READ_MAXSIZE)
					{
						fwrite(WriteBuff, 1, READ_MAXSIZE, fout);
						WriteSize = 0;
					}
					if (--FileSize == 0)
					{
						fwrite(WriteBuff, 1, WriteSize, fout);
						break;
					}
					cur = ht.GetRoot();
				}
				if (ReadBuff[i] & (1 << pos))//=1，表示该比特位为1
				{
					cur = cur->m_right;
				}
				else
				{
					cur = cur->m_left;
				}
			}
			UnCompressCount++;
		}
	}
	std::cout << "解压了的字符个数：" << UnCompressCount << std::endl;
	delete[]WriteBuff;
	delete[]ReadBuff;
	fclose(fin);
	fclose(fout);
	return 1;
}