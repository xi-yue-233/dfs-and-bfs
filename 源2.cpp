#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class DFS_BFS
{
public:
	void origin(int **map,int mapx,int mapy,bool isshow)
	{
		

	}

private:
	vector<vector<int>> map1;

	class point
	{
	private:
		int posx;
		int posy;
	};
	queue<point> q;
	
	int** visited1;
	int** visited2;

	int flag1;
	int flag2;
};