#pragma once
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class ConsoleGame
{
public:
    ConsoleGame()
    {
	    memset(board, '+', 15*15*sizeof(char));
    }

    void Play()
    {
        while (1)
        {
            int choice = 0;
            Menu();
            cin >> choice;
            if (choice == 0)
            {
                break;
            }
            else if (choice == 1)
            {
                Game();
            }
            else 
            {
                continue;
            }
        }
    }
    void Game()
    {
        while (1)
        {
            system("clear");
            Print();
            if (result != 'N')
            {
                IsWin();
                break;
            }
            PlayMove();
            if (result != 'N')
            {
                IsWin();
                break;
            }
            ComputerMove();
        }
    }

private:
    void Menu()
    {
        printf("==============欢迎进入五子棋小游戏==============\n");
        printf("\t=======请选择功能列表=======\n");
        printf("\t\t1.开始游戏\n");
        printf("\t\t0.退出游戏\n");
        printf("请选择>");
    }

    void Print()
    {
    	int i = 0, j = 0, k = 0;
    	printf("    Y--------------------------->\n");
    	printf("    ");
    	for (k = 0; k < 15; k++)
    	{
    		if (k >= 0 && k <= 8)
    			printf("%d ", k + 1);
    		else
    			printf("%d", k + 1);
    	}
    	putchar('\n');
    	for (i = 0; i < 15; i++)
    	{
    		printf("X");
    		if (i >= 0 && i <= 8)
    			printf("0%d ", i + 1);
    		else
    			printf("%d ", i + 1);
    		for (j = 0; j < 15; j++)
    		{
    			putchar(board[i][j]);
    			if (j<(15 - 1))
    				putchar('-');
    		}
    		putchar('\n');
    	}
    }
    
    int Row(char board[15][15], int row, int col, char whoFlag)
    {
    	int spaceNum = 0;//空白数
    	int count = 1;//几连，包含当前要下的子
    	int leftHad = 0;//左边是否有同子
    	int x = row;
    	int y = col;
    	int liveLeft = 0;
    	int liveRight = 0;
    	if (board[row][col] != '+')
    	{
    		return 0;
    	}
    	while (y>0 && (board[x][y - 1] == '+' || board[x][y - 1] == whoFlag))
    	{
    		if (board[x][y - 1] == '+' && spaceNum < 1)
    		{
    			//第一个空白
    			if (board[x][y - 2] != whoFlag)
    			{
    				liveLeft = 1;
    				break;
    			}
    			spaceNum++;
    			y--;
    		}
    		else if (board[x][y - 1] == whoFlag)
    		{
    			leftHad = 1;
    			y--;
    			count++;
    		}
    		else
    		{
    			//第2个空白
    			liveLeft = 1;
    			break;
    		}
    	}
    	//如果左边没有同色子，设置空白数为0
    	if (!leftHad)
    	{
    		spaceNum = 0;
    	}
    	y = col;
    	while (y<14 && (board[x][y + 1] == '+' || board[x][y + 1] == whoFlag))
    	{
    		if (board[x][y + 1] == '+' && spaceNum < 1)
    		{
    			//第一个空白
    			if (board[x][y + 2] != whoFlag)
    			{
    				liveRight = 1;
    				break;
    			}
    			spaceNum++;
    			y++;
    		}
    		else if (board[x][y + 1] == '+' && spaceNum > 0)
    		{
    			//第2个空白
    			liveRight = 1;
    			break;
    		}
    		else
    		{
    			y++;
    			count++;
    		}
    	}
    	return Result(liveLeft, liveRight, count, spaceNum, whoFlag);
    }
    
    int Col(char board[15][15], int row, int col, char whoFlag)
    {
    	int spaceNum = 0;//空白数
    	int count = 1;//几连，包含当前要下的子
    	int topHad = 0;//上边是否有同子
    	int x = row;
    	int y = col;
    	int liveLeft = 0;
    	int liveRight = 0;
    	if (board[row][col] != '+')
    	{
    		return 0;
    	}
    	while (x > 0 && (board[x - 1][y] == '+' || board[x - 1][y] == whoFlag))
    	{
    		if (board[x - 1][y] == '+' && spaceNum < 1)
    		{
    			//第一个空白 
    			if (board[x - 2][y] != whoFlag)
    			{
    				liveLeft = 1;
    				break;
    			}
    			spaceNum++;
    			x--;
    		}
    		else if (board[x - 1][y] == whoFlag)
    		{
    			topHad = 1;
    			x--;
    			count++;
    		}
    		else
    		{
    			//第2个空白 
    			liveLeft = 1;
    			break;
    		}
    	}
    	//如果左边没有同色子，设置空白数为0
    	if (!topHad)
    	{
    		spaceNum = 0;
    	}
    	x = row;
    	while (x < 14 && (board[x + 1][y] == '+' || board[x + 1][y] == whoFlag))
    	{
    		if (board[x + 1][y] == '+' && spaceNum < 1)
    		{
    			//第一个空白
    			if (board[x + 2][y] != whoFlag)
    			{
    				liveRight = 1;
    				break;
    			}
    			spaceNum++;
    			x++;
    		}
    		else if (board[x + 1][y] == '+' && spaceNum > 0)
    		{
    			//第2个空白
    			liveRight = 1;
    			break;
    		}
    		else
    		{
    			x++;
    			count++;
    		}
    	}
    	return Result(liveLeft, liveRight, count, spaceNum, whoFlag);
    }
    
    int zuoxie(char board[15][15], int row, int col, char whoFlag)
    {
    	int spaceNum = 0;//空白数
    	int count = 1;//几连，包含当前要下的子
    	int topHad = 0;//上边是否有同子
    	int x = row;
    	int y = col;
    	int liveLeft = 0;
    	int liveRight = 0;
    	if (board[row][col] != '+')
    	{
    		return 0;
    	}
    	//向下
    	while (x < 14 && y>0 && (board[x + 1][y - 1] == '+' || board[x + 1][y - 1] == whoFlag))
    	{
    		if (board[x + 1][y - 1] == '+' && spaceNum < 1)
    		{
    			//第一个空白
    			if (board[x + 2][y - 2] != whoFlag)
    			{
    				liveLeft = 1;
    				break;
    			}
    			spaceNum++;
    			x++;
    			y--;
    		}
    		else if (board[x + 1][y - 1] == whoFlag)
    		{
    			topHad = 1;
    			x++;
    			y--;
    			count++;
    		}
    		else
    		{
    			//第2个空白 
    			liveLeft = 1;
    			break;
    		}
    	}
    	//如果上边没有同色子，设置空白数为0 
    	if (!topHad)
    	{
    		spaceNum = 0;
    	}
    	x = row;
    	y = col;
    	//向上 
    	while (x > 0 && y < 14 && (board[x - 1][y + 1] == '+' || board[x - 1][y + 1] == whoFlag))
    	{
    		if (board[x - 1][y + 1] == '+' && spaceNum < 1)
    		{
    			//第一个空白
    			if (board[x - 2][y + 2] != whoFlag)
    			{
    				liveRight = 1;
    				break;
    			}
    			spaceNum++;
    			x--;
    			y++;
    		}
    		else if (board[x - 1][y + 1] == '+' && spaceNum > 0)
    		{
    			//第2个空白
    			liveRight = 1;
    			break;
    		}
    		else
    		{
    			x--;
    			y++;
    			count++;
    		}
    	}
    	return Result(liveLeft, liveRight, count, spaceNum, whoFlag);
    }

    int youxie(char board[15][15], int row, int col, char whoFlag)
    {
    	int spaceNum = 0;//空白数 
    	int count = 1;//几连，包含当前要下的子 
    	int topHad = 0;//上边是否有同子 
    	int x = row;
    	int y = col;
    	int liveLeft = 0;
    	int liveRight = 0;
    	if (board[row][col] != '+')
    	{
    		return 0;
    	}
    	//向上
    	while (x > 0 && y > 0 && (board[x - 1][y - 1] == '+' || board[x - 1][y - 1] == whoFlag))
    	{
    		if (board[x - 1][y - 1] == '+' && spaceNum < 1)
    		{
    			//第一个空白
    			if (board[x - 2][y - 2] != whoFlag)
    			{
    				liveLeft = 1;
    				break;
    			}
    			spaceNum++;
    			x--;
    			y--;
    		}
    		else if (board[x - 1][y - 1] == whoFlag)
    		{
    			topHad = 1;
    			x--;
    			y--;
    			count++;
    		}
    		else
    		{
    			//第2个空白
    			liveLeft = 1;
    			break;
    		}
    	}
    	//如果上边没有同色子，设置空白数为0
    	if (!topHad)
    	{
    		spaceNum = 0;
    	}
    	x = row;
    	y = col;
    	//向下
    	while (x < 14 && y < 14 && (board[x + 1][y + 1] == '+' || board[x + 1][y + 1] == whoFlag))
    	{
    		if (board[x + 1][y + 1] == '+' && spaceNum < 1)
    		{
    			//第一个空白
    			if (board[x + 2][y + 2] != whoFlag)
    			{
    				liveRight = 1;
    				break;
    			}
    			spaceNum++;
    			x++;
    			y++;
    		}
    		else if (board[x + 1][y + 1] == '+' && spaceNum > 0)
    		{
    			//第2个空白
    			liveRight = 1;
    			break;
    		}
    		else
    		{
    			x++;
    			y++;
    			count++;
    		}
    	}
    	return Result(liveLeft, liveRight, count, spaceNum, whoFlag);
    }
    
    int Result(int left, int right, int count, int k, char num)
    {
    	if (count == 1)
    	{
    		return 1;
    	}
    	else if (count == 2)
    	{
    		if (left && right)
    		{
    			//左右两边都是空的
    			if (k == 0)
    			{
    				//电脑60
    				return num == WHITE_FLAG ? 60 : 50;
    			}
    			else
    			{
    				return num == WHITE_FLAG ? 40 : 35;
    			}
    		}
    		else if (!left && !right)
    		{
    			return 1;
    		}
    		else
    		{
    			return 10;
    		}
    	}
    	else if (count == 3)
    	{
    		if (left && right)
    		{
    			//左右两边都是空的
    			if (k == 0)
    			{
    				//电脑950
    				return num == WHITE_FLAG ? 950 : 700;
    			}
    			else
    			{
    				return num == WHITE_FLAG ? 900 : 650;
    			}
    		}
    		else if (!left && !right)
    		{
    			return 1;
    		}
    		else
    		{
    			return 100;
    		}
    	}
    	else if (count == 4)
    	{
    		if (left && right)
    		{
    			//左右两边都是空的
    			if (k == 0)
    			{
    				return num == WHITE_FLAG ? 6000 : 3500;
    			}
    			else
    			{
    				return num == WHITE_FLAG ? 5000 : 3000;
    			}
    		}
    		else if (!left && !right)
    		{
    			return 1;
    		}
    		else
    		{
    			if (k == 0)
    			{
    				return num == WHITE_FLAG ? 4000 : 800;
    			}
    			else{
    				return num == WHITE_FLAG ? 3600 : 750;
    			}
    		}
    	}
    	else
    	{
    		if (k == 0)
    		{
    			return num == WHITE_FLAG ? 20000 : 15000;
    		}
    		else
    		{
    			return num == WHITE_FLAG ? 10000 : 3300;
    		}
    	}
    }
    
    void Score(char board[15][15])
    {
    	int n = 0;
    	int m = 0;
    	for (n = 0; n < 15; n++)
    	{
    		for (m = 0; m < 15; m++)
    		{
    			ComputerScore[n][m] = Row(board, n, m, WHITE_FLAG) + Col(board, n, m, WHITE_FLAG) + zuoxie(board, n, m, WHITE_FLAG) + youxie(board, n, m, WHITE_FLAG);
    			PlayScore[n][m] = Row(board, n, m, BLACK_FLAG) + Col(board, n, m, BLACK_FLAG) + zuoxie(board, n, m, BLACK_FLAG) + youxie(board, n, m, BLACK_FLAG);
    		}
    	}
    }
    
    void ComputerMove()
    {
    	Score(board);
    	int count = 0;
    	int row = 0;
    	int col = 0;
    	int i = 0;
    	int j = 0;
    	for (i = 0; i < 15; i++)
    	{
    		for (j = 0; j < 15; j++)
    		{
    			if (ComputerScore[i][j] > count)
    			{
    				count = ComputerScore[i][j];
    				row = i;
    				col = j;
    			}
    			if (PlayScore[i][j] > count)
    			{
    				count = PlayScore[i][j];
    				row = i;
    				col = j;
    			}
    		}
    	}
    	if (board[row][col] == '+')
    	{
    		board[row][col] = WHITE_FLAG;
            result = Judge();
    	}
    }
    
    int PlayMove()
    {
    	int x, y;
    	int res;
    	printf("输入x, y:");
    	scanf("%d %d", &x, &y);
    	if (x<0 || y<0 || x>15 || y>15)
    	{
    		printf("输入错误，请重新输入\n");
    		while ((getchar()) != '\n');
    		res = PlayMove();
    		if (res == 1)
            {
                result = Judge();
    			return 1;
            }
    	}
    	x--;
    	y--;
    	if (board[x][y] == '+')
    	{
    		board[x][y] = BLACK_FLAG;
    	}
    	else
    	{
    		printf("输入错误，请重新输入\n");
    		while ((getchar()) != '\n');
    		Play();
    		if (res == 1)
            {
                result = Judge();
    			return 1;
            }
    	}
    	return 1;
    }

    char Judge()
    {
        int row = 15;
        int col = 15;
        for (auto i = 0; i < row; i++)
        {
            for (auto j = 0; j < col-4; j++)
            {
                if (board[i][j+0] != '+' && \
                    board[i][j+0] == board[i][j+1] && \
                    board[i][j+1] == board[i][j+2] && \
                    board[i][j+2] == board[i][j+3] && \
                    board[i][j+3] == board[i][j+4])
                {
                    return board[i][j];
                }
            }
        }
        for (auto j = 0; j < col; j++)
        {
            for (auto i = 0; i < row-4; i++)
            {
                if (board[i+0][j] != '+' && \
                    board[i+0][j] == board[i+1][j] && \
                    board[i+1][j] == board[i+2][j] && \
                    board[i+2][j] == board[i+3][j] && \
                    board[i+3][j] == board[i+4][j])
                {
                    return board[i][j];
                }
            }
        }
        for (auto i = 0; i < row-4; i++)
        {
            if (board[i+0][i+0] != '+' && \
                board[i+0][i+0] == board[i+1][i+1] && \
                board[i+1][i+1] == board[i+2][i+2] && \
                board[i+2][i+2] == board[i+3][i+3] && \
                board[i+3][i+3] == board[i+4][i+4])
            {
                return board[i][i];
            }
        }
        for (auto i = 0; i < row-4; i++)
        {
            if (board[i+0][col-i-1] != '+' && \
                board[i+0][col-i-1] == board[i+1][col-i-2] && \
                board[i+1][col-i-2] == board[i+2][col-i-3] && \
                board[i+2][col-i-3] == board[i+3][col-i-4] && \
                board[i+3][col-i-4] == board[i+4][col-i-5])
            {
                return board[i][col-i-1];
            }
        }
        for (auto i = 0; i < row; i++)
        {
            for (auto j = 0; j < col; j++)
            {
                if ('+' == board[i][j])
                {
                    return 'N';
                }
            }
        }
        return 'E';
    }

    void IsWin()
    {
        if (result == 'E')
        {
            cout << "平局" << endl;
        }
        else if (result == 'O')
        {
            cout << "恭喜你，你赢了！" << endl; 
        }
        else
        {
            cout << "很遗憾，你输了！" << endl; 
        }
    }
private:
    char board[15][15];
    int ComputerScore[15][15];
    int PlayScore[15][15];
    char BLACK_FLAG = 'O';
    char WHITE_FLAG = 'X';
    char result = 'N';
};
