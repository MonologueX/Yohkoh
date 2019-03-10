//#define _CRT_SECURE_NO_WARNINGS
//
//
//#include<stdio.h>
//#include<string.h> 
//#define MAX 1000    // 大数的最大位数 
//
///*
//函数SubStract功能：
//用长度为len1的大整数p1减去长度为len2的大整数p2
//结果存在p1中，返回值代表结果的长度
//不够减：返回-1 ， 正好够：返回0
//*/
//
//int SubStract(int *p1, int len1, int *p2, int len2)
//{
//	int i;
//	if (len1 < len2)
//		return -1;
//	if (len1 == len2)
//	{                        // 判断p1 > p2
//		for (i = len1 - 1; i >= 0; i--)
//		{
//			if (p1[i] > p2[i])   // 若大，则满足条件，可做减法
//				break;
//			else if (p1[i] < p2[i]) // 否则返回-1
//				return -1;
//		}
//	}
//	for (i = 0; i <= len1 - 1; i++)  // 从低位开始做减法
//	{
//		p1[i] -= p2[i];         // 相减 
//		if (p1[i] < 0)           // 若是否需要借位
//		{   // 借位 
//			p1[i] += 10;
//			p1[i + 1]--;
//		}
//	}
//	for (i = len1 - 1; i >= 0; i--)  // 查找结果的最高位
//	{
//		if (p1[i])             //最高位第一个不为0
//			return (i + 1);       //得到位数并返回
//	}
//	return 0;                   //两数相等的时候返回0
//}
//
//
///*
//大数除法---结果不包括小数点
//num1 被除数
//num2 除数
//sum  商，存放计算的结果，即：num1/num2=sum
//返回数组sum的有效长度，即商的位数
//*/
//
//int Division(char num1[], char num2[], char sum[])
//{
//	int i, j;
//	int len1, len2, len = 0;     //大数位数
//	int dValue;                //两大数相差位数
//	int nTemp;                 //Subtract函数返回值
//	int num_a[MAX] = { 0 };      //被除数
//	int num_b[MAX] = { 0 };      //除数
//	int num_c[MAX] = { 0 };      //商 
//
//	len1 = strlen(num1);       //获得大数的位数
//	len2 = strlen(num2);
//
//	//将数字字符转换成整型数，且翻转保存在整型数组中 
//	for (j = 0, i = len1 - 1; i >= 0; j++, i--)
//		num_a[j] = num1[i] - '0';
//	for (j = 0, i = len2 - 1; i >= 0; j++, i--)
//		num_b[j] = num2[i] - '0';
//
//	if (len1 < len2)          //如果被除数小于除数，直接返回-1，表示结果为0
//	{
//		return -1;
//	}
//	dValue = len1 - len2;      //相差位数
//	for (i = len1 - 1; i >= 0; i--)    //将除数扩大，使得除数和被除数位数相等
//	{
//		if (i >= dValue)
//			num_b[i] = num_b[i - dValue];
//		else                         //低位置0
//			num_b[i] = 0;
//	}
//	len2 = len1;
//	for (j = 0; j <= dValue; j++)    //重复调用，同时记录减成功的次数，即为商
//	{
//		while ((nTemp = SubStract(num_a, len1, num_b + j, len2 - j)) >= 0)
//		{
//			len1 = nTemp;            //结果长度
//			num_c[dValue - j]++;       //每成功减一次，将商的相应位加1
//		}
//	}
//	// 计算商的位数，并将商放在sum字符数组中 
//	for (i = MAX - 1; num_c[i] == 0 && i >= 0; i--);  //跳过高位0，获取商的位数 
//	if (i >= 0)
//		len = i + 1; // 保存位数 
//	for (j = 0; i >= 0; i--, j++)     // 将结果复制到sum数组中 
//		sum[j] = num_c[i] + '0';
//	sum[j] = '\0';   // sum字符数组结尾置0 
//	return len;      // 返回商的位数 
//}
//
//
//int main()
//{
//	int i;
//	int len;                // 商的位数
//	char num1[MAX] = "1234567899876543210";   // 第一个大数
//	char num2[MAX] = "20160415123025";              // 第二个大数
//	char sum[MAX] = { 0 };    // 计算结果 
//
//	scanf("%s", num1);      //以字符串形式读入大数
//	scanf("%s", num2);
//
//	len = Division(num1, num2, sum);
//
//	//输出结果
//	printf("%s\n  ÷\n%s\n  =\n", num1, num2);
//	if (len >= 0)
//	{
//		for (i = 0; i < len; i++)
//			printf("%c", sum[i]);
//	}
//	else
//	{
//		printf("0");
//	}
//	printf("\n");
//
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include<stdio.h>
#include<string.h>
using namespace std;
#define MAX 1000    // 大数的最大位数 

/*
函数SubStract功能：
用长度为len1的大整数p1减去长度为len2的大整数p2
结果存在p1中，返回值代表结果的长度
不够减：返回-1 ， 正好够：返回0
*/

int SubStract(vector<int>& p1, int len1, vector<int>& p2, int len2)
{
	int i;
	if (len1 < len2)
		return -1;
	if (len1 == len2)
	{                        // 判断p1 > p2
		for (i = len1 - 1; i >= 0; i--)
		{
			if (p1[i] > p2[i])   // 若大，则满足条件，可做减法
				break;
			else if (p1[i] < p2[i]) // 否则返回-1
				return -1;
		}
	}
	for (i = 0; i <= len1 - 1; i++)  // 从低位开始做减法
	{
		p1[i] -= p2[i];         // 相减 
		if (p1[i] < 0)           // 若是否需要借位
		{   // 借位 
			p1[i] += 10;
			p1[i + 1]--;
		}
	}
	for (i = len1 - 1; i >= 0; i--)  // 查找结果的最高位
	{
		if (p1[i])             //最高位第一个不为0
			return (i + 1);       //得到位数并返回
	}
	return 0;                   //两数相等的时候返回0
}


/*
大数除法---结果不包括小数点
num1 被除数
num2 除数
sum  商，存放计算的结果，即：num1/num2=sum
返回数组sum的有效长度，即商的位数
*/

int Division(vector<int> num1, vector<int> num2, char sum[])
{
	int i, j;
	int len1, len2, len = 0;     //大数位数
	int dValue;                //两大数相差位数
	int nTemp;                 //Subtract函数返回值
	vector<int> num_a(num1);
	//int num_a[MAX] = { 0 };      //被除数
	vector<int> num_b(num2);
	//int num_b[MAX] = { 0 };      //除数
	int num_c[MAX] = { 0 };      //商 

	len1 = num1.size();       //获得大数的位数
	len2 = num2.size();

	//将数字字符转换成整型数，且翻转保存在整型数组中 
	/*for (j = 0, i = len1 - 1; i >= 0; j++, i--)
		num_a[j] = num1[i];
	for (j = 0, i = len2 - 1; i >= 0; j++, i--)
		num_b[j] = num2[i];*/
	reverse(num_a.begin(), num_a.end());
	reverse(num_b.begin(), num_b.end());

	if (len1 < len2)          //如果被除数小于除数，直接返回-1，表示结果为0
	{
		return -1;
	}
	dValue = len1 - len2;      //相差位数
	for (i = len1 - 1; i >= 0; i--)    //将除数扩大，使得除数和被除数位数相等
	{
		if (i >= dValue)
			num_b[i] = num_b[i - dValue];
		else                         //低位置0
			num_b[i] = 0;
	}
	len2 = len1;
	for (j = 0; j <= dValue; j++)    //重复调用，同时记录减成功的次数，即为商
	{
		while ((nTemp = SubStract(num_a, len1, num_b + j, len2 - j)) >= 0)
		{
			len1 = nTemp;            //结果长度
			num_c[dValue - j]++;       //每成功减一次，将商的相应位加1
		}
	}
	// 计算商的位数，并将商放在sum字符数组中 
	for (i = MAX - 1; num_c[i] == 0 && i >= 0; i--);  //跳过高位0，获取商的位数 
	if (i >= 0)
		len = i + 1; // 保存位数 
	for (j = 0; i >= 0; i--, j++)     // 将结果复制到sum数组中 
		sum[j] = num_c[i] + '0';
	sum[j] = '\0';   // sum字符数组结尾置0 
	return len;      // 返回商的位数 
}


int main()
{
	int i;
	int len;                // 商的位数
	vector<int> num1(10, 9);
	vector<int> num2(10, 1);
	char sum[MAX] = { 0 };    // 计算结果 

	len = Division(num1, num2, sum);

	//输出结果
	printf("shang:");
	if (len >= 0)
	{
		for (i = 0; i < len; i++)
			printf("%c", sum[i]);
	}
	else
	{
		printf("0");
	}
	printf("\n");

	return 0;
}
