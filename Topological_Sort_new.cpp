#include <bits/stdc++.h>
using namespace std;

void TPGutil(vector<list<int>> adjlist, int pos, int* visited, stack<int> &st)
{
	visited[pos] = 1;
	
	list<int>:: iterator it;
	
	for(it = adjlist[pos].begin(); it!= adjlist[pos].end(); it++)  // REMEMBER!!! here we need loop...as we don't have to leave covering any node adjacent to pos.
	{
		if(!visited[*it])
		{
			TPGutil(adjlist, *it, visited, st);
		}
	}
	
	st.push(pos);
}

void TPG(vector<list<int>> adjlist, int v)
{
	int visited[v+1];
	int i;
	for(i=0; i<=v; i++)
	{
		visited[i] = 0;
	}
	stack<int> st;
	
	for(i=1; i<=v; i++)
	{
		if(!visited[i])
		{
			TPGutil(adjlist, i, visited, st);
		}
	}
	
	while(!st.empty())
	{
		printf("%d ", st.top());
		
		st.pop();
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

	
	TPG(adjlist,vertices); //No need of starting vertex as we are going to traverse the whole graph(even the disconnected ones also)


return(0);

}
