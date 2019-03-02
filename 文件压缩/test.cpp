#define CRTDBG_MAP_ALLOC
#pragma once
#include "Compress.h"
#include<windows.h>
#include<time.h>

using namespace std;
void Text1()
{
	DWORD start_time = GetTickCount();
	Compress c;
	c.compress("小说.txt");
	DWORD end_time = GetTickCount();
	cout << "压缩文档时间:" << (end_time - start_time) << "ms!" << endl;
	DWORD start1_time = GetTickCount();
	c.uncompress("小说.ggzip");
	DWORD end1_time = GetTickCount();
	cout << "解压文档时间:" << (end1_time - start1_time) << "ms!" << endl;
}

void Text2()
{
	DWORD start_time = GetTickCount();
	Compress c;
	c.compress("图片.jpg");
	DWORD end_time = GetTickCount();
	cout << "压缩图片时间:" << (end_time - start_time) << "ms!" << endl;
	DWORD start1_time = GetTickCount();
	c.uncompress("图片.ggzip");
	DWORD end1_time = GetTickCount();
	cout << "解压图片时间:" << (end1_time - start1_time) << "ms!" << endl;
}

void Text3()
{
	DWORD start_time = GetTickCount();
	Compress c;
	c.compress("倚天屠龙记.kux");
	DWORD end_time = GetTickCount();
	cout << "压缩视频时间:" << (end_time - start_time) << "ms!" << endl;
	DWORD start1_time = GetTickCount();
	c.uncompress("倚天屠龙记.ggzip");
	DWORD end1_time = GetTickCount();
	cout << "解压视频时间:" << (end1_time - start1_time) << "ms!" << endl;
}
int main()
{
	//Text1();
	//Text2();
	Text3();
	system("pause");
	return 0;
}
