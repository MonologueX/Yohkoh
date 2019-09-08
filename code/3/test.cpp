#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
	int part[2];
	int value;
};

int x, y, z;

struct Node path[1000][1000];

void Fun(int curX, int curY, int curZ)
{
	int cur_x, cur_y, cur_z;
	if (curX != x)
	{
		if (curX + curY > x)
		{
			cur_x = x;
			cur_y = curX + curY - cur_x;
			cur_z = curZ;
			if (path[cur_y][cur_z].value == -1 || (path[cur_y][cur_z].value > path[curY][curZ].value + 1))
			{
				path[cur_y][cur_z].part[0] = curY;
				path[cur_y][cur_z].part[1] = curZ;
				path[cur_y][cur_z].value = path[curY][curZ].value + 1;
				Fun(cur_x, cur_y, cur_z);
			}
		}
		else
		{
			cur_x = curY + curY;
			cur_y = 0;
			cur_z = curZ;
			if (path[cur_y][cur_z].value == -1 || (path[cur_y][cur_z].value > path[curY][curZ].value + 1))
			{
				path[cur_y][cur_z].part[0] = curY;
				path[cur_y][cur_z].part[1] = curZ;
				path[cur_y][cur_z].value = path[curY][curZ].value + 1;
				Fun(cur_x, cur_y, cur_z);
			}
		}

		if (curX + curZ > x)
		{
			cur_x = x;
			cur_y = curY;
			cur_z = curX + curZ - cur_x;
			if (path[cur_y][cur_z].value == -1 || (path[cur_y][cur_z].value > path[curY][curZ].value + 1))
			{
				path[cur_y][cur_z].part[0] = curY;
				path[cur_y][cur_z].part[1] = curZ;
				path[cur_y][cur_z].value = path[curY][curZ].value + 1;
				Fun(cur_x, cur_y, cur_z);
			}
		}
		else
		{
			cur_x = curX + curY;
			cur_y = curY;
			cur_z = 0;
			if (path[cur_y][cur_z].value == -1 || (path[cur_y][cur_z].value > path[curY][curZ].value + 1))
			{
				path[cur_y][cur_z].part[0] = curY;
				path[cur_y][cur_z].part[1] = curZ;
				path[cur_y][cur_z].value = path[curY][curZ].value + 1;
				Fun(cur_x, cur_y, cur_z);
			}
		}
	}

	// Y
	if (curY != y)
	{
		if (curX + curY > y)
		{
			cur_x = curX + curY - y;
			cur_y = y;
			cur_z = curZ;
			if (path[cur_y][cur_z].value == -1 || (path[cur_y][cur_z].value > path[curY][curZ].value + 1))
			{
				path[cur_y][cur_z].part[0] = curY;
				path[cur_y][cur_z].part[1] = curZ;
				path[cur_y][cur_z].value = path[curY][curZ].value + 1;
				Fun(cur_x, cur_y, cur_z);
			}
		}
		else
		{
			cur_x = 0;
			cur_y = curX + curY;
			cur_z = curZ;
			if (path[cur_y][cur_z].value == -1 || (path[cur_y][cur_z].value > path[curY][curZ].value + 1))
			{
				path[cur_y][cur_z].part[0] = curY;
				path[cur_y][cur_z].part[1] = curZ;
				Fun(cur_x, cur_y, cur_z);
			}
		}
		if (curX + curZ > x)
		{
			cur_x = curX + curZ - z;
			cur_y = curY;
			cur_z = z;
			if (path[cur_y][cur_z].value == -1 || (path[cur_y][cur_z].value > path[curY][curZ].value + 1))
			{
				path[cur_y][cur_z].part[0] = curY;
				path[cur_y][cur_z].part[1] = curZ;
				path[cur_y][cur_z].value = path[curY][curZ].value + 1;
				Fun(cur_x, cur_y, cur_z);
			}
		}
		else
		{
			cur_x = 0;
			cur_y = curY;
			cur_z = curX + curZ;
			if (path[cur_y][cur_z].value == -1 || (path[cur_y][cur_z].value > path[curY][curZ].value + 1))
			{
				path[cur_y][cur_z].part[0] = curY;
				path[cur_y][cur_z].part[1] = curZ;
				path[cur_y][cur_z].value = path[curY][curZ].value + 1;
				Fun(cur_x, cur_y, cur_z);
			}
		}
	}

	// Z
	if (curZ != z)
	{
		if (curX + curZ > z)
		{
			cur_x = curX + curY - z;
			cur_y = curY;
			cur_z = z;
			if (path[cur_y][cur_z].value == -1 || (path[cur_y][cur_z].value > path[curY][curZ].value + 1))
			{
				path[cur_y][cur_z].part[0] = curY;
				path[cur_y][cur_z].part[1] = curZ;
				path[cur_y][cur_z].value = path[curY][curZ].value + 1;
				Fun(cur_x, cur_y, cur_z);
			}
		}
		else
		{
			cur_x = 0;
			cur_y = curY;
			cur_z = curX + curZ;
			if (path[cur_y][cur_z].value == -1 || (path[cur_y][cur_z].value > path[curY][curZ].value + 1))
			{
				path[cur_y][cur_z].part[0] = curY;
				path[cur_y][cur_z].part[1] = curZ;
				Fun(cur_x, cur_y, cur_z);
			}
		}
		if (curX + curZ > x)
		{
			cur_x = curX;
			cur_y = curY + curZ - z;
			cur_z = z;
			if (path[cur_y][cur_z].value == -1 || (path[cur_y][cur_z].value > path[curY][curZ].value + 1))
			{
				path[cur_y][cur_z].part[0] = curY;
				path[cur_y][cur_z].part[1] = curZ;
				path[cur_y][cur_z].value = path[curY][curZ].value + 1;
				Fun(cur_x, cur_y, cur_z);
			}
		}
		else
		{
			cur_x = curX;
			cur_y = 0;
			cur_z = curY + curZ;
			if (path[cur_y][cur_z].value == -1 || (path[cur_y][cur_z].value > path[curY][curZ].value + 1))
			{
				path[cur_y][cur_z].part[0] = curY;
				path[cur_y][cur_z].part[1] = curZ;
				path[cur_y][cur_z].value = path[curY][curZ].value + 1;
				Fun(cur_x, cur_y, cur_z);
			}
		}
	}
}


int main()
{
	int x, y, z, k;
	while (cin >> x >> y >> z >> k)
	{
		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 1000; j++)
			{
				path[i][j].part[0] = path[i][j].part[1] = path[i][j].value = -1;
			}
		}
		path[0][0].value = 0;
		Fun(x, 0, 0);
		int min = 1000;
		for (int i = 0; i <= x - k; i++)
		{
			if (path[i][x - k - i].value != -1 && path[i][x - k - i].value < min)
			{
				min = path[i][x - k - i].value;
			}
		}

		if (min != 1000)
			cout << min << endl;
	}
	return 0;
}

//int main()
//{
//	long long num;
//	long long index = 0;
//	std::vector<long long> array;
//	while (cin >> num)
//	{
//		array.resize(num);
//		for (long long i = 0; i < num; i++)
//			cin >> array[i];
//		std::vector<long long> count(num, 0);
//		for (long long i = num - 1; i >= 0; i--)
//		{
//			index = 1;
//			while (index <= i && array[i - index] < array[i])
//				index++;
//			if (index <= i && array[i - index] > array[i])
//				count[i - index]++;
//		}
//		long long max = 0;
//		for (long long i = num - 1; i >= 0; i--)
//		{
//			if (count[i] > max)
//			{
//				index = i;
//				max = count[i];
//			}
//		}
//		cout << array[index] << endl;
//	}
//	return 0;
//}
