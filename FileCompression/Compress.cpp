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
			// Windows ������ itoa
			sprintf(StrCount, "%d", (int)m_informations[i].m_count);
			CodeInformation += StrCount;
			CodeInformation += '\n';
			LineCount++;
		}
	}
	sprintf(StrCount, "%d", LineCount);
	std::cout << "Code ��ȡ���" << std::endl;
	HeadInformation += StrCount;
	HeadInformation += '\n';
	HeadInformation += CodeInformation;
	fwrite(HeadInformation.c_str(), 1, HeadInformation.size(), fout);
}

int Compress::compress(const std::string& CompressName)
{
	///////////////////////////////////////////////
	//  1.��ȡԴ�ַ����ִ���
	///////////////////////////////////////////////

	// Ҫ�� b ,�����ѹʱ���ܶ�����ͽ�ѹ����
	FILE *fin = fopen(CompressName.c_str(), "rb");
	if (nullptr == fin)
	{
		std::cout << "���ļ�ʧ��" << std::endl;
		return -1;
	}
	std::cout << "���ļ��ɹ�" << std::endl;

	unsigned char *ReadBuff = new unsigned char[READ_MAXSIZE];
	size_t SourceCount = 0;
	while (1)
	{
		size_t ReadSize = fread(ReadBuff, 1, 1024, fin);
		if (0 == ReadSize)
		{
			//std::cout << "��ȡ���" << std::endl;
			break;
		}
		//std::cout << "��ȡ�ɹ���[ReadSize] = " << ReadSize << std::endl;

		for (size_t i = 0; i < ReadSize; i++)
		{
			m_informations[ReadBuff[i]].m_count++;
			SourceCount++;
		}
	}
	std::cout << "Դ�ļ������ַ�����" << SourceCount << std::endl;
	

	///////////////////////////////////////////////
	//  2.������������
	///////////////////////////////////////////////

	HuffmanTree<CharInformation> hf((m_informations));

	//////////////////////////////////////////////
	//  3.����Huffman������ȡHuffman����
	///////////////////////////////////////////////

	GetHuffmanCode(hf.GetRoot());
	std::cout << "�����������ȡ�ɹ�" << std::endl;

	///////////////////////////////////////////////
	//  4.��ÿ���ַ��ı����дԴ�ļ�
	///////////////////////////////////////////////

	std::string compressfile = GetFilepath(CompressName);//��ȡ�ļ�ǰ׺
	compressfile += ".ggzip";//Ȼ����ǰ׺�������ѹ��֮��ĺ�׺
	std::cout << "ѹ����" << compressfile << std::endl;

	// ���ļ�
	FILE* fout = fopen(compressfile.c_str(), "wb");
	assert(fout);

	WriteHead(fout, CompressName);
	char pos = 0;
	char ptr = 0;
	// �ر���Ҫ
	fseek(fin, 0, SEEK_SET);

	int CompreeCount = 0;
	size_t WriteSize = 0;
	char* WriteBuff = new char[READ_MAXSIZE];
	while (true)
	{
		size_t ReadSize = fread(ReadBuff, 1, READ_MAXSIZE, fin);
		if (0 == ReadSize)
		{
			//std::cout << "��ȡ���" << std::endl;
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
						WriteSize = 0;//д��һ����0
					}
					//fputc(ptr, fout);
					CompreeCount++;
					pos = 0;
				}
			}
		}
	}

	//���û��8������λ
	if (pos > 0 && pos < 8)
	{
		WriteBuff[WriteSize++] = ptr <<= (8 - pos);
		fwrite(WriteBuff, 1, WriteSize, fout);
		//fputc(ptr, fout);
		CompreeCount++;
	}
	std::cout << "ѹ���˵��ַ�������" << CompreeCount << std::endl;
	delete[]ReadBuff;
	delete[]WriteBuff;
	fclose(fin);
	fclose(fout);
	return 1;
}

/////////////////////////////////////////////////////////////
// ��ѹ��
/////////////////////////////////////////////////////////////
void ReadLine(FILE*fin, std::string& StrInformation)
{
	char c = fgetc(fin);
	while (c != '\n')
	{
		if (feof(fin))//������β
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

	// ��ȡ��׺
	std::string StrInformation;
	StrInformation = '1';
	ReadLine(fin, StrInformation);
	std::string compressFilepath = GetFilepath(CompressName);
	compressFilepath += StrInformation;
	
	// ��ȡ����
	std::string StrLineCount;
	ReadLine(fin, StrLineCount);
	size_t LineCount = atoi(StrLineCount.c_str());

	// ��ȡ�ַ���Ϣ
	std::string strcodeinformation;
	char ctemp = 0;
	int count = 0;

	//��ÿ���ַ����ֵĴ���
	for (size_t i = 0; i < LineCount; i++)
	{
		strcodeinformation.clear();
		ReadLine(fin, strcodeinformation);
		// ���г���
		if (strcodeinformation.empty())
		{
			strcodeinformation += '\n';
			ReadLine(fin, strcodeinformation);
		}
		count = atoi(strcodeinformation.c_str() + 2);
		m_informations[(unsigned char)strcodeinformation[0]].m_count = count;
	}

	//��ԭHuffman��
	HuffmanTree<CharInformation> ht(m_informations);

	//��ѹ��
	//FILE* fout = fopen(compressFilepath.c_str(), "wb");
	FILE* fout = fopen("test.kux", "wb");
	assert(fout);
	size_t WriteSize = 0;
	size_t pos = 8;

	//Դ�ļ�һ���ж��ٸ��ַ�
	Node cur = ht.GetRoot();
	// ��ֹ���һ���ַ�����
	CountType FileSize = cur->m_weight.m_count;

	size_t UnCompressCount = 0;

	char* ReadBuff = new char[READ_MAXSIZE];
	char* WriteBuff = new char[READ_MAXSIZE];
	while (true)
	{
		size_t ReadSize = fread(ReadBuff, 1, READ_MAXSIZE, fin);
		if (0 == ReadSize)
		{
			//std::cout << "��ȡ���" << std::endl;
			break;
		}
		for (size_t i = 0; i < ReadSize; ++i)
		{
			pos = 8;
			while (pos--)
			{
				//Ҷ�ӽ��
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
				if (ReadBuff[i] & (1 << pos))//=1����ʾ�ñ���λΪ1
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
	std::cout << "��ѹ�˵��ַ�������" << UnCompressCount << std::endl;
	delete[]WriteBuff;
	delete[]ReadBuff;
	fclose(fin);
	fclose(fout);
	return 1;
}