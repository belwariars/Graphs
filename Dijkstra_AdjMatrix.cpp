#include <bits/stdc++.h>
using namespace std;

#define v 9

int minDistance(int dist[], bool sptset[])
{
	int i;
	int min = INT_MAX;
	int minindex;
	for(i=0; i<v; i++)
	{
		if(dist[i] < min && !sptset[i])
		{
			min = dist[i];
			minindex = i;
		}
	}
	
	return minindex;
}

void printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < v; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[v][v], int source)
{
	int dist[v]; // will hold shortest distance from source to i
	bool sptset[v]; // shortest path tree set...will be true if the vertex is included in stp
	
	int i;
	for(i=0; i<v; i++)
	{
		dist[i] = INT_MAX;
		sptset[i] = false;
	}
	dist[source] = 0;
	
	int count;
	for(count =0; count<v-1; count++)
	{
		int u = minDistance(dist, sptset);
		sptset[u] = true;
		
		for(i=0; i<v; i++)
		{
			if(!sptset[i] && graph[u][i] && dist[u]!=INT_MAX && dist[u]+graph[u][i] < dist[i])
			{
				dist[i] = dist[u]+graph[u][i];
			}
		}
	}
	
	printSolution(dist, v);
}

int main()
{
	int graph[v][v] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
                     
    dijkstra(graph, 0);
	return 0;
}
