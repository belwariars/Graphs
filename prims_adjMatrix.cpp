#include <bits/stdc++.h>
using namespace std;

#define v 9

int minDist(int key[], bool mst[])
{
	int i;
	int min = INT_MAX;
	int minindex;
	for(i=0; i<v; i++)
	{
		if(key[i]<min && !mst[i])
		{
			min = key[i];
			minindex = i;
		}
	}
	
	return minindex;
}

int printMST(int parent[], int n, int graph[v][v])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < v; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[v][v])
{
	int parent[v];
	bool mst[v];
	int key[v];
	
	int i;
	for(i=0; i<v; i++)
	{
		mst[i] = false;
		key[i] = INT_MAX;
	}
	
	key[0] = 0;
	parent[0] = -1;
	for(i=0; i<v-1; i++)
	{
		int u = minDist(key, mst);
		mst[u] = true;
		
		int j;
		
		for(j=0; j<v; j++)
		{
			if(graph[u][j] && !mst[j] && graph[u][j] < key[j])
			{
				key[j] = graph[u][j];
				parent[j] = u;
			}
		}
	}
	
	printMST(parent, v, graph);
}

int main()
{
	int graph[v][v] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
    
    primMST(graph);
	return 0;
}
