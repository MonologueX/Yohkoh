#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

///////////////////////////////////////////////
//  PrefixTable
///////////////////////////////////////////////
void PrefixTable(char parttern[], int prefix[], int n)
{
	prefix[0] = 0;
	int len = 0;
	int i = 1;
	while (i < n)
	{
		if (parttern[i] == parttern[len])
		{
			len++;
			prefix[i++] = len;
		}
		else
		{
			if ((len > 0))
				len = prefix[len - 1];
			else
				prefix[i++] = len;
		}
	}
}

void MovePrefix(int prefix[], int n)
{
	for (int i = n - 1; i > 0; i--)
		prefix[i] = prefix[i - 1];
	prefix[0] = -1;
}

///////////////////////////////////////////////
//  KMP
///////////////////////////////////////////////
void KmpSearch(char text[], char parttern[])
{
	int n = strlen(parttern);
	int m = strlen(text);
	int* prefix = (int *)malloc(sizeof(int)*n);
	PrefixTable(parttern, prefix, n);
	MovePrefix(prefix, n);
	int i = 0, j = 0;
	while (i < m)
	{
		if (j == n - 1 && text[i] == parttern[j])
		{
			printf("Found parttern at : %d\n",i - j);
			j = prefix[j];
		}
		if (text[i] == parttern[j])
		{
			i++, j++;
		}
		else
		{
			j = prefix[j];
			if (j == -1)
				i++, j++;
		}
	}
}

int main()
{
	char parttern[] = "ABABCABAA";
	char text[] = "ABABABCABAAGJHFR";
	KmpSearch(text, parttern);
	return 0;
}
