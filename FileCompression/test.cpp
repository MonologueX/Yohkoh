#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "Compress.h"
#include "LZ77.h"
#include<windows.h>
#include<time.h>

using namespace std;
void Text1()
{
	DWORD start_time = GetTickCount();
	Compress c;
	c.compress("С˵.txt");
	DWORD end_time = GetTickCount();
	cout << "ѹ���ĵ�ʱ��:" << (end_time - start_time) << "ms!" << endl;
	DWORD start1_time = GetTickCount();
	c.uncompress("С˵.ggzip");
	DWORD end1_time = GetTickCount();
	cout << "��ѹ�ĵ�ʱ��:" << (end1_time - start1_time) << "ms!" << endl;
}

void Text2()
{
	DWORD start_time = GetTickCount();
	Compress c;
	c.compress("ͼƬ.jpg");
	DWORD end_time = GetTickCount();
	cout << "ѹ��ͼƬʱ��:" << (end_time - start_time) << "ms!" << endl;
	DWORD start1_time = GetTickCount();
	c.uncompress("ͼƬ.ggzip");
	DWORD end1_time = GetTickCount();
	cout << "��ѹͼƬʱ��:" << (end1_time - start1_time) << "ms!" << endl;
}

void Text3()
{
	DWORD start_time = GetTickCount();
	Compress c;
	c.compress("����������.kux");
	DWORD end_time = GetTickCount();
	cout << "ѹ����Ƶʱ��:" << (end_time - start_time) << "ms!" << endl;
	DWORD start1_time = GetTickCount();
	c.uncompress("����������.ggzip");
	DWORD end1_time = GetTickCount();
	cout << "��ѹ��Ƶʱ��:" << (end1_time - start1_time) << "ms!" << endl;
}

void Text4()
{}
int main()
{
	//Text1();
	//Text2();
	Text3();
	/*LZ77 lz;
	lz.LZ77Compress("lz.txt");
	lz.LZ77UnCompress("first.lzp");*/
	system("pause");
	return 0;
}