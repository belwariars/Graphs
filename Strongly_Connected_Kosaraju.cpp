#include <bits/stdc++.h>
using namespace std;

void transpose(vector<list<int>> adjlist, vector<list<int>> &transadj)
{
	int i;
	list<int>:: iterator it;
	
	for(i=1; i<adjlist.size(); i++)
	{
		it = adjlist[i].begin();
		while(it!=adjlist[i].end())
		{
			transadj[*it].push_back(i); // reverse
			it++;
		}
	}
}

void secondDFSUtil(vector<list<int> > transadj,int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
 
 	printf("%d ",v);	
    // Recur for all the vertices adjacent to this vertex firstly and then push the original vertex into the stack...In this way we are sorting the graph 
    //topologically
    list<int>::iterator i;
    for (i = transadj[v].begin(); i != transadj[v].end(); ++i)
        if (!visited[*i])
            secondDFSUtil(transadj,*i, visited);
            
}

void DFSUtil(vector<list<int>> adjlist, bool visited[], int start, stack<int> &st)
{
	list<int>:: iterator it;
	it = adjlist[start].begin();
	visited[start] = true;
	while(it!=adjlist[start].end())
	{
		if(!visited[*it])
		{
			DFSUtil(adjlist, visited, *it, st);
		}
		it++;
	}
	
	st.push(start);
}

void SSC(vector<list<int>> adjlist, int v)
{
	bool visited[v+1];
	int i;
	for(i=1; i<v+1; i++)
	{
		visited[i] = false;
	}
	
	stack<int> st;
	
	for(i=1; i<v+1; i++)
	{
		if(!visited[i])
		{
			DFSUtil(adjlist, visited, i, st);
		}
	}
	
	vector<list<int>> transadj(v+1); // it will contain reverse of the order of adjlist
	
	transpose(adjlist, transadj); // method called to reverse
	
	for(i=1; i<v+1; i++)
	{
		visited[i] = false;
	}
	
	int u;
   while(!st.empty())
   	{
   		u=st.top();
   		st.pop();
   		
   		if(!visited[u])
   			{
   				secondDFSUtil(transadj,u,visited);
   				printf("\n");
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

	
	SSC(adjlist,vertices); //No need of starting vertex as we are going to traverse the whole graph(even the disconnected ones also)


return(0);

}
