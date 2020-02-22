#include <iostream>
using namespace std;

#define VERTICES 6

void initialise(int parent[], int _rank[])
{
	for (int i = 0; i < VERTICES; i++)
	{
		parent[i] = -1;
        _rank[i] = 0;
	}
}

int find_root(int x, int parent[])
{
	int x_root = x;
	while (parent[x_root] != -1)
	{
		x_root = parent[x_root];
	}
	return x_root;
}

int union_vertices(int x, int y, int parent[], int _rank[])
{
	int x_root = find_root(x, parent);
	int y_root = find_root(y, parent);
	if (x_root == y_root)
	{
		return 0;
	}
	else
	{
        if (_rank[x_root] > _rank[y_root])
            parent[y_root] = x_root;
        else if (_rank[x_root] < _rank[y_root])
            parent[x_root] = y_root;
        else 
        {
            parent[x_root] = y_root;
            _rank[y_root]++;
        }
		return 1;
	}
}

void Test1()
{
	int parent[VERTICES] = { 0 };
	int _rank[VERTICES] = { 0 };
	int edges[6][2] = {
		{ 0, 1 },
		{ 1, 2 },
		{ 1, 3 },
        { 2, 4 },
		{ 3, 4 },
		{ 2, 5 }
	};
	initialise(parent, _rank);
	for (int i = 0; i < 6; i++)
	{
		int x = edges[i][0];
		int y = edges[i][1];
		if (union_vertices(x, y, parent, _rank) == 0)
		{
			cout << "Cycle detected" << endl;
			return;
		}
	}
	cout << "No cycle found!" << endl;

}

void Test2()
{
	int edges[5][2] = {
		{ 0, 1 },
		{ 1, 2 },
		{ 1, 3 },
		{ 3, 4 },
		{ 2, 5 }
	};
	int parent[VERTICES] = { 0 };
	int _rank[VERTICES] = { 0 };
	initialise(parent, _rank);
	for (int i = 0; i < 5; i++)
	{
		int x = edges[i][0];
		int y = edges[i][1];
		if (union_vertices(x, y, parent, _rank) == 0)
		{
			cout << "Cycle detected" << endl;
			return;
		}
	}
	cout << "No cycle found!" << endl;
}


int main()
{
    Test1();
    Test2();
	return 0;
}
