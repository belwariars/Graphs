#include <bits/stdc++.h>
using namespace std;

void BFS(vector<list<int>> adjlist, int parent[], int level[], int start)
{
	list<int> queue;
	queue.push_back(start);
	
	list<int>:: iterator it;
	while(!queue.empty())
	{
		int start = queue.front();
		printf("%d ", start);
		level[start] = 0;
		it = adjlist[start].begin();
		
		while(it!=adjlist[start].end())
		{
			if(level[*it] == -1)
			{
				level[*it] = level[start]+1;
				queue.push_back(*it);
			}
			it++;
		}
		queue.pop_front();
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
	int v1,v2;
	for(i=0; i<e; i++)
	{
		printf("Enter v1 & v2\n");
		scanf("%d %d", &v1, &v2);
		adjlist[v1].push_back(v2);
	}
	
	list<int>:: iterator it;
	
	for(i=0; i< adjlist.size(); i++)
	{
		printf("adjlist[%d]", i);
		
		for(it=adjlist[i].begin(); it!=adjlist[i].end(); it++)
		{
			printf("->%d", *it);
		}
		
		printf("\n");
	}
	
	int parent[v+1];
	int level[v+1];
	
	for(i=0; i<=v; i++)
	{
		parent[i] = 0;
		level[i] = -1;
	}
	
	int start;
	printf("Enter start vertex\n");
	scanf("%d", &start);
	
	
	BFS(adjlist, parent, level, start);
	return 0;
}
