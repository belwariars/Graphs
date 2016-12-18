#include <bits/stdc++.h>
using namespace std;

#define v 4
#define INF 99999

void printSolution(int dist[v][v])
{
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[v][v])
{
	int i,j,k;
	
	for(k=0; k<v; k++)
	{
		for(i=0; i<v; i++)
		{
			for(j=0; j<v; j++)
			{
				if(graph[i][k] + graph[k][j] < graph[i][j])
				{
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
	
	printSolution(graph);
}

int main()
{
	 int graph[v][v] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
                      
    floydWarshall(graph);
	return 0;
}
