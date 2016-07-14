#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

const int maxn = 100;
//g is ÁÚ½Ó¾ØÕó
bool g[maxn][maxn], visited[maxn];
int n;
queue<int> q;

using namespace std;

void init()
{
	memset(g, false, sizeof(g));
	memset(visited, false, sizeof(visited));
}

bool route(int src , int dst)
{
	q.push(src);
	visited[src] = true;
	
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		
		if (t == dst)
		{
			return true;
		}
		for (int i = 0; i < n; i++)
		{
			if (g[t][i] && !visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return false;
}

int main()
{
	freopen("4.2.in", "r", stdin);
	
	init();
	int m, u, v;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		g[u][v] = true;
	}

	cout << route(0, 6) << endl;
	fclose(stdin);
}