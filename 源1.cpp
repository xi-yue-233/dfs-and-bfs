#include <iostream>
#include <queue>

using namespace std;

struct point
{
	int posx;
	int posy;
};

int map[10][10] = { 0,1,1,0,0,1,2,0,1,1,
					1,1,0,0,0,1,0,1,0,1,
					0,1,1,0,1,1,1,0,0,1,
					1,1,0,1,0,1,0,1,0,1,
					1,1,0,1,1,1,0,1,0,1,
					0,1,1,1,0,1,0,1,1,1,
					1,1,0,1,1,0,1,1,0,1,
					0,1,1,1,1,1,1,1,1,1,
					1,1,0,1,0,1,1,1,0,1,
					1,1,0,0,0,1,0,1,3,1
};
int visited[10][10] = { 0, };
int step = 0;
char show[10][10] = {};
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int flag = 0;
queue<point> q;

void BFS(int x, int y)
{
	point p;
	p.posx = x;
	p.posy = y;
	q.push(p);
	visited[x][y] = 1;
	if (map[x][y] == 2)
	{
		cout << "找到起点,起点是:" ;
		show[x][y] = '2';
	}
	while (!q.empty())
	{
		cout << q.front().posx + 1 << "	" << q.front().posy + 1 << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << "		";
			for (int j = 0; j < 10; j++)
			{
				cout << show[i][j] << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < 4; i++)
		{
			int tx, ty;
			tx = q.front().posx + dx[i];
			ty = q.front().posy + dy[i];
			if (map[tx][ty] == 1 && visited[tx][ty] == 0)
			{
				step++;
				point temp;
				temp.posx = tx;
				temp.posy = ty;
				q.push(temp);
				visited[tx][ty] = 1;
				show[tx][ty] = '1';
			}
			if (map[tx][ty] == 0 && visited[tx][ty] == 0)
			{
				visited[tx][ty] = 1;
				show[tx][ty] = 'x';
			}
			if (map[tx][ty] == 3)
			{
				cout << "到达终点,终点是:" << tx + 1 << "	" << ty + 1 << " 使用步数:" << step << endl;
				show[tx][ty] = '3';
				for (int i = 0; i < 10; i++)
				{
					cout << "		";
					for (int j = 0; j < 10; j++)
					{
						cout << show[i][j] << " ";
					}
					cout << endl;
				}
				flag = 1;
			}
		}
		if (flag == 1)
		{
			break;
		}
		q.pop();
		cout << "下一个点,下点为:";
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
				BFS(i, j);
				break;
			}
		}
	}

}

int main()
{
	memset(show, '0', sizeof(show));
	findorigin();
	return 0;
}