#include <iostream>
#include <cstring>

#define MAXVEX 100

using namespace std;

typedef struct graph
{
	char vertex[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertex, numEdges;
}graph;

bool visited[MAXVEX];

void init(graph *g)
{
	memset(g->vertex, '0', sizeof(g->vertex));
	memset(g->arc, 0, sizeof(g->arc));
	memset(visited, false, sizeof(visited));
	g->numVertex = 0;
	g->numEdges = 0;

}

void createGraph(graph *g)
{
	int i, j;
	int u, v;
	cout << "input num vertex and edges is :" << endl;
	cin >> g->numVertex >> g->numEdges;
	//test
	//cout << g->numVertex << " " << g->numEdges << endl;
	for (i = 0; i < g->numEdges; i++)
	{
		cin >> u >> v;
		g->arc[u][v] = 1;
		g->arc[v][u] = g->arc[u][v];	
	}
}

void printGraph(graph g)
{
	int i, j;
	for (i = 0; i < g.numVertex; i++)
	{
		for (j = 0; j < g.numVertex; j++)
		{
			cout << g.arc[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	graph g;
	
	init(&g);
	createGraph(&g);
	printGraph(g);
	
	system("pause");
	return 0;
}