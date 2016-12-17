#include <bits/stdc++.h>
using namespace std;

int main()
{
	printf("Enter number of vertices\n");
	int v;
	scanf("%d", &v);
	printf("Enter number of edges\n");
	int e;
	scanf("%d", &e);
	
	vector<list<int>> adjlist(v + 1); 
	int i;
	for(i=0; i<e; i++)
	{
		printf("Enter v1 and v2\n");
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		
		adjlist[v1].push_back(v2);
		adjlist[v2].push_back(v1);
	}
	
	for(i=1; i<=e; i++)
	{
		list<int>:: iterator it;
		printf("adjlist[%d]", i);
		for(it=adjlist[i].begin(); it!=adjlist[i].end(); it++)
		{
			printf("->%d", *it);
		}
		printf("\n");
	}
	
	return 0;
}
