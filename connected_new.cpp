#include <bits/stdc++.h>
using namespace std;

void BFS(vector<list<int>> adjlist, int mark[], int start)
{
	list<int> queue;
	queue.push_back(start);
	list<int>:: iterator it;
	
	while(!queue.empty())
	{
		int newItem = queue.front();
	//	printf("%d ", newItem);
	
	if(mark[newItem]!=1)
 			{
 				mark[newItem]=1;
 				printf("%d ",newItem);
 			}
		
		it = adjlist[newItem].begin();
		
		while(it != adjlist[newItem].end())
		{
			if(mark[*it] == -1)
			{
				mark[*it] = 1;
				queue.push_back(*it);
				printf("%d ", *it);
			}
			it++;
		}
		queue.pop_front();
	}
	printf("\n");
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
		adjlist[v2].push_back(v1);
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
	int mark[v+1];
	for(i=0; i<=v; i++)
	{
		mark[i] = -1;
	}
	
	int conn = 0;
	for(i=1; i<=v; i++) // A lopp that will cover all vertices as in one time BFS, because the graph might be not connected, it won't traverse through all vertex...
	{
		if(mark[i] == -1)
		{
			BFS(adjlist, mark, i);
			conn++;
		}
	} 
	
	printf("mark[1]= %d\n", mark[1]);
	
	printf("connected components = %d", conn);
	
//	BFS(adjlist, mark, )
	return 0;
}
