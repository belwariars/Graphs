#include <bits/stdc++.h>
using namespace std;

void DFSUtil(vector<list<int>> adjlist, int visited[], int start)
{
	list<int>:: iterator it;
	visited[start] = 1;
	printf("%d ", start);
	
	for(it=adjlist[start].begin(); it!=adjlist[start].end(); it++)
	{
		//printf("%d ", *it);
		if(visited[*it]==0)
		{
			DFSUtil(adjlist, visited, *it);
		}
	}
}

void DFS(vector<list<int>> adjlist, int v)
{
	int visited[v+1];
	int i;
	for(i=0;i<=v;i++)
	{
		visited[i] = 0;
	}
	
	for(i=1; i<=v; i++)
	{
		if(visited[i]==0)
		{
			DFSUtil(adjlist, visited, i);
		}
	}
}


int main()
{

	
	int i,vertices,edges,v1,v2;
	   	
	printf("Enter the number of vertices\n");
	scanf("%d",&vertices);
     
 	printf("Enter the number of edges\n");//Enter the number of distinct edges....i.e-don't include (3,1) if (1,3) already included(for undirected only)..Refer to Fig-10-1 of 
	scanf("%d",&edges);					  //Yashavant Kanetkar's "Data Structures thorugh C" 
	    
	vector<list<int>> adjlist(vertices+1);//We are considering 1-based indexing
		
    list< int >::iterator itr;
     
    for (i = 0; i <= edges-1; i++)
	 {
	 	printf("Enter v1 and v2\n");
        scanf("%d %d", &v1, &v2);
         
        // Adding Edge to the Directed Graph
        adjlist[v1].push_back(v2);
        adjlist[v1].push_back(v2);
    }			
    
         
    printf("\nThe Adjacency List-\n");
    // Printing Adjacency List
    for (i = 1; i < adjlist.size(); i++)
	 {
        printf("adjlist[%d] ", i);
         
        for (itr=adjlist[i].begin();itr != adjlist[i].end();itr++)
		 {
            printf(" -> %d", *itr);
         }
         
        printf("\n");
    }

	
	DFS(adjlist,vertices); //No need of starting vertex as we are going to traverse the whole graph(even the disconnected ones also)


return(0);

}
