#include <bits/stdc++.h>
using namespace std;

int isCycleUtil(vector<list<int>> adjlist, int* visited, int recstack[], int pos)
{
	if(visited[pos] == 0)
	{
		visited[pos] = 1;
		recstack[pos] = 1;
		
		list<int>:: iterator it;
		
		for(it=adjlist[pos].begin(); it!=adjlist[pos].end(); it++)
		{
			if(!visited[*it] && isCycleUtil(adjlist, visited, recstack, *it))
				return true;
			else if(recstack[*it])
				return true;
		}
	}
	
	recstack[pos] = 0;
	return false;
}

int isCycle(vector<list<int>> adjlist, int v)
{
	int visited[v+1];
	int recstack[v+1];
	int i;
	for(i=0; i<=v; i++)
	{
		visited[i] = 0;
		recstack[i] = 0;
	}
	
	
	for(i=1; i<=v; i++)
	{
		if(isCycleUtil(adjlist, visited, recstack, i))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
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
