#include <bits/stdc++.h>
using namespace std;

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
		printf("%d", i);
		for(it = adjlist[i].begin(); it != adjlist[i].end(); it++)
		{
			
			printf("->%d", *it);
			
		}
		
		printf("\n");
	}
	
	return 0;
}
