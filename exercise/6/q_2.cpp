#include <iostream>
#include <vector>
using namespace std;

#define VISITED 2
int cost[4] = { -1, -1, -3, 0 };
int dir[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };

class Maze
{
public:
	class MazePoint
	{
	public:
		MazePoint(int x, int y)
			: m_x(x)
			, m_y(y)
		{}
		int m_x;
		int m_y;
	};
public:
	void Result(std::vector<std::vector<int> >& maze, int m, int n, int p)
	{
		search(maze, 0, 0, m, n, p);
		if (final_P != -1000)
			PrintPath(minCostPath);
		else
			cout << "Can not escape!";
	}

	void PrintMaze(std::vector<std::vector<int> > maze, int m, int n)
	{
		system("cls");
		for (auto i = 0; i < m; i++)
		{
			for (auto j = 0; j < n; j++)
			{
				if (maze[i][j] == 0)
					cout << "■";
				if (maze[i][j] == 1)
					cout << "□";
				if (maze[i][j] == 2)
					cout << "♀";
				if (maze[i][j] == 3)
					cout << "×";
			}
			cout << endl;
		}
	}

	// 函数：打印路径
	void PrintPath(std::vector<MazePoint>& path) 
	{
		for (auto i = 0; i < path.size(); ++i) 
		{
			cout << "[" << path[i].m_x << "," << path[i].m_y << "]";
			if (i < path.size() - 1) 
			{
				cout << ",";
			}
		}
	}

	void search(std::vector<std::vector<int> >& maze, int x, int y, int m, int n, int cur_P)
	{
		pathStack.push_back(MazePoint(x, y));
		maze[x][y] = VISITED;
		PrintMaze(maze, m, n);
		if (x == 0 && y == n - 1 && cur_P >= 0) 
		{
			if (cur_P > final_P) 
			{
				final_P = cur_P;
				minCostPath = pathStack;
			}
			pathStack.pop_back();
			maze[x][y] = 1;
			return;
		}

		if (cur_P > 0) 
		{
			for (int i = 0; i < 4; ++i) 
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				int nP = cur_P + cost[i];
				if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == 1)
					search(maze, nx, ny, m, n, nP);
			}
		}
		pathStack.pop_back();
		maze[x][y] = 1;
		PrintMaze(maze, m, n);
	}

private:
	int final_P = -1000;
	std::vector<MazePoint> pathStack;
	std::vector<MazePoint> minCostPath;
};

int main()
{
	std::vector<std::vector<int> > maze;
	int m, n, p;
	cin >> m >> n >> p;
	maze.resize(m);
	for (auto& e : maze)
	{
		e.resize(n);
	}
	for (auto i = 0; i < m; i++)
	{
		for (auto j = 0; j < n; j++)
		{
			cin >> maze[i][j];
		}
	}
	Maze s;
	s.Result(maze, m, n, p);
	return 0;
}
