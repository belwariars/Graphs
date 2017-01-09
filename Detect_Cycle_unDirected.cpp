#include <bits/stdc++.h>
using namespace std;

int isCycleUtil(vector<list<int>> adjlist, int visited[], int pos, int parent)
{
	visited[pos] = true;
	
	list<int>:: iterator it;
	
	for(it=adjlist[pos].begin(); it!=adjlist[pos].end(); it++)
	{
		if(!visited[*it])
		{
			if(isCycleUtil(adjlist, visited, *it, pos))
				return 1;
		}
		else
			{
				if((*it)!= parent)
				{
					return 1;
				}
			}
	}
	
	return 0;
}

int isCycle(vector<list<int>> adjlist, int v)
{
	int visited[v+1];
	int i;
	
	for(i=0; i<=v; i++)
	{
		visited[i] = 0;
	}
	
	for(i=0; i<=v; i++)
	{
		if(!visited[i])
		{
			if(isCycleUtil(adjlist, visited, i, -1))
			{
				return 1;
			}
		}
		
	}
	return 0;
}

int main()
{
	int e,v;
	printf("Enter no. of vertices: \n");
	scanf("%d", &v);
	printf("Enter no. of Edges: \n");
	scanf("%d", &e);
	
	int i;
	int v1, v2;
	
	vector<list<int>> adjlist(v+1);
	for(i=0; i<e; i++)
	{
		printf("Enter v1 & v2: \n");
		scanf("%d %d", &v1, &v2);
		
		adjlist[v1].push_back(v2);
		adjlist[v2].push_back(v1);
	}
	
	list<int>:: iterator it;
	
	for(i=0; i<=v; i++)
	{
		printf("adjlist[%d]", i);
		
		for(it=adjlist[i].begin(); it!=adjlist[i].end(); it++)
		{
			printf("->%d", *it);
		}
		
		printf("\n");
	}
	
	
	if(isCycle(adjlist, v))
	{
		printf("Cycle EXISTS!!\n");
	}
	else
	{
		printf("Cycle DOESN'T EXISTS\n");
	}
	return 0;
}
