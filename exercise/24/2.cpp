#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

#define VISITED 2
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
	void Result(std::vector<std::vector<int> >& maze, int m, int n)
	{
		m_min = m*n+1;
		search(maze, 0, 0, m, n);
		PrintPath(minPath);
	}

	void PrintMaze(std::vector<std::vector<int> > maze, int m, int n)
	{
		system("clear");
		for (auto i = 0; i < m; i++)
		{
			for (auto j = 0; j < n; j++)
			{
				if (maze[i][j] == 0)
					cout << "□";
				if (maze[i][j] == 1)
					cout << "■";
				if (maze[i][j] == 2)
					cout << "♀";
			}
			cout << endl;
		}
		sleep(1);
	}

	// 函数：打印路径
	void PrintPath(std::vector<MazePoint>& path)
	{
		for (size_t i = 0; i < path.size(); ++i)
		{
			cout << "(" << path[i].m_x << "," << path[i].m_y << ")" << endl;
		}
	}

	void search(std::vector<std::vector<int> >& maze, int x, int y, int m, int n)
	{
		/*  0 1 0 0 0
			0 1 0 1 0
			0 0 0 0 0
			0 1 1 1 0
			0 0 0 1 0*/
		pathStack.push_back(MazePoint(x, y));
		maze[x][y] = VISITED;
		// PrintMaze(maze, m, n);
		if (x == m - 1 && y == n - 1)
		{
			if (m_min > pathStack.size())
			{
				minPath = pathStack;
				m_min = minPath.size();
			}
			pathStack.pop_back();
			maze[x][y] = 0;
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == 0)
				search(maze, nx, ny, m, n);
		}

		pathStack.pop_back();
		maze[x][y] = 0;
		PrintMaze(maze, m, n);
	}
private:
	int m_min;
	std::vector<MazePoint> pathStack;
	std::vector<MazePoint> minPath;
};

int main()
{
	std::vector<std::vector<int> > maze;
	int m, n;
	while (cin >> m >> n)
	{
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
		s.Result(maze, m, n);
	}
	return 0;
}
