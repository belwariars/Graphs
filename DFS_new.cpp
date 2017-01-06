#include <bits/stdc++.h>
using namespace std;

void DFSutil(vector<list<int>> adjlist, int mark[], int start)
{
	if(mark[start] == -1)
	{
		printf("%d ", start);
		mark[start] = 1;
	}
	
	list<int>:: iterator it;
	
	for(it=adjlist[start].begin(); it!=adjlist[start].end(); it++)
	{
		if(mark[*it] == -1)
		{
			DFSutil(adjlist, mark, *it);
		}
	}
}

void DFS(vector<list<int>> adjlist, int mark[], int v)
{
	int i;
	for(i=1; i<=v; i++)
	{
		if(mark[i] == -1)
		{
			DFSutil(adjlist, mark, i);
		}
	}
}

int main()
{
	int v,e;
	printf("Enter no. of vertices\n");
	scanf("%d", &v);
	printf("Enter no. of edges\n");
	scanf("%d", &e);
	
	vector<list<int>> adjlist(v+1);
	
	int i;
	int v1, v2;
	for(i=0; i<e; i++)
	{
		printf("Enter v1 & v2\n");
		scanf("%d %d", &v1, &v2);
		adjlist[v1].push_back(v2); // in DFS, there has to be DIRECTED GRAPH...
		adjlist[v2].push_back(v1);
	}
	
	list<int>:: iterator it;
	
	for(i=0; i<adjlist.size(); i++)
	{
		printf("adjlist[%d]", i);
		
		for(it=adjlist[i].begin(); it!=adjlist[i].end(); it++)
		{
			printf("->%d", *it);
		}
		
		printf("\n");
	}
	
	int mark[v+1];
	for(i=0; i<=v; i++)
	{
		mark[i] = -1;
	}
	
	DFS(adjlist, mark, v);
	
	return 0;
}
