#include <bits/stdc++.h>
using namespace std;

void bfsTraversal(vector<list<int>> adjlist, int parent[], int level[], int start)
{
	list<int> queue; // queue which is basically a list used for bfs
	level[start] = 0;
	list<int>:: iterator it;
	
	queue.push_back(start);
	
	while(!queue.empty())
	{
		int currfront = queue.front();
		list<int>:: iterator it;
		it = adjlist[currfront].begin();
		
		printf("%d ", currfront);
		
		while(it!=adjlist[currfront].end())
		{
			if(parent[*it] == 0)
			{
				queue.push_back(*it);
				parent[*it] = currfront;
				it++;
			}
			
		}
		
		queue.pop_front();
	}
}
int main()
{
	printf("Enter Number of Vertices..\n");
	int v;
	scanf("%d", &v);
	printf("Enter Number of Edges\n");
	int e;
	scanf("%d", &e);
	
	vector<list<int>> adjlist(v+1); // v+1 because, this is 1-based vector or the no start from 1 ...we leave 0 unfilled.
	
	int i;
	for(i=0; i<e; i++)
	{
		printf("enter v1 and v2\n");
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		adjlist[v1].push_back(v2);
	}
	
	for(i=1; i<=v; i++)
	{
		list<int>:: iterator it;
		//printf("%d", i);
		for(it = adjlist[i].begin(); it != adjlist[i].end(); it++)
		{
			
		//	printf("->%d", *it);
			
		}
		
		//printf("\n");
	}
	
	int parent[v+1];
	int level[v+1];
	
	for(i=0; i<=v; i++)
	{
		parent[i] = 0; // as  0 is not valid node in 1-based indexing
		level[i] = -1;
	}
	
	printf("Enter starting vertex");
	int start;
	scanf("%d", &start);
	
	bfsTraversal(adjlist, parent, level, start);
	
	return 0;
}
