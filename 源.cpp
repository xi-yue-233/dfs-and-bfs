#include <iostream>
#include <queue>

using namespace std;

int map[10][10] = { 0,1,1,0,0,1,2,0,1,1,
					1,1,0,0,0,1,0,1,0,1,
					0,1,1,0,1,1,1,0,0,1,
					1,1,0,1,0,1,0,1,0,1,
					1,1,0,1,1,1,0,1,0,1,
					0,1,1,1,0,1,0,1,1,1,
					1,1,0,1,1,0,1,1,0,1,
					0,1,1,1,1,1,1,1,1,1,
					1,1,0,1,0,1,1,1,0,1,
					1,1,0,0,0,1,0,1,0,3
				};
int step = 0;
int visited[10][10] = { 0, };
char show[10][10];
int flag = 1;

void DFS(int x, int y)
{
	if (flag == 0)
	{
		return;
	}
	if (x < 0 || x>9 || y < 0 || y>9 )
	{
		return;
	}
	else if (visited[x][y] == 1 || map[x][y] == 0)
	{
		if (map[x][y] == 0)
		{
			show[x][y] = 'x';
		}
		visited[x][y] = 1;
		return;
	}
	else if (map[x][y] == 3)
	{
		step++;
		cout << "到达终点,终点是:" << x + 1 << " " << y + 1 << " 使用步数:" << step << endl;
		show[x][y] = '3';
		for (int i = 0; i < 10; i++)
		{
			cout << "		";
			for (int j = 0; j < 10; j++)
			{
				cout << show[i][j] << " ";
			}
			cout << endl;
		}
		flag = 0;
		return;
	}
	else if (map[x][y] == 2 || map[x][y] == 1)
	{
		if (map[x][y] == 2)
		{
			cout << "找到起点,起点是:" << x + 1 << " " << y + 1 << endl;
			show[x][y] = '2';
			for (int i = 0; i < 10; i++)
			{
				cout << "		";
				for (int j = 0; j < 10; j++)
				{
					cout << show[i][j] << " ";
				}
				cout << endl;
			}
		}
		else
		{
			step++;
			cout << "下一个点，下点为" << x + 1 << " " << y + 1 << endl;
			show[x][y] = '1';
			for (int i = 0; i < 10; i++)
			{
				cout << "		";
				for (int j = 0; j < 10; j++)
				{
					cout << show[i][j] << " ";
				}
				cout << endl;
			}
		}
		visited[x][y] = 1;
		DFS(x + 1, y);
		DFS(x, y + 1);
		DFS(x - 1, y);
		DFS(x, y - 1);
	}
}

void findorigin()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j] == 2)
			{
				DFS(i, j);
				break;
			}
		}
	}
		
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			show[i][j] = '0';
		}
	}
	findorigin();
	return 0;
}