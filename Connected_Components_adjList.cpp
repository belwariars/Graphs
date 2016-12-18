#include <bits/stdc++.h>
using namespace std;

void BFS(vector<list<int>> adjlist, bool visited[], int start)
{
	list<int> queue;
	list<int>:: iterator it;
	
	queue.push_back(start);
	while(!queue.empty())
	{
		
	int front = queue.front();

	visited[front] = true;
	printf("%d ", front);
	
	
	it = adjlist[front].begin();
	
	while(it!=adjlist[front].end())
	{
		if(!visited[*it])
		{
			queue.push_back(*it);
			visited[*it] = true;
		}
		it++;
	}	
	
	queue.pop_front();
}
}

int main()
{
	printf("Enter numver of vertices");
	int v;
	scanf("%d", &v);
	printf("Enter number of Edges");
	int e;
	scanf("%d", &e);
	
	vector<list<int>> adjlist(v+1);
	int i;
	for(i=0;i<e;i++)
	{
		printf("Enter V1 and V2");
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		
		adjlist[v1].push_back(v2);
		adjlist[v2].push_back(v1);
	}
	
	//let's print the adjList created.....
	list<int>:: iterator it;
	for(i=1; i<v+1; i++)
	{
		it = adjlist[i].begin();
		printf("adjlist[%d]", i);
		while(it!=adjlist[i].end())
		{
			printf("->%d", *it);
			it++;
		}
		
		printf("\n");
	}
	
//	int i;
	bool visited[v+1];
	for(i=0; i<v+1; i++)
	{
		visited[i] = false;
	}
	int noconnected = 0;
	for(i=1; i<=v; i++)
	{
		if(!visited[i])
		{
			BFS(adjlist, visited, i);
			noconnected++;
			printf("\n");
		}
	}
	
	printf("Total no. of components : %d", noconnected);
	return 0;
}
