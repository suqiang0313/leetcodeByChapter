//this is a demo for dfs in graph 
//http://www.cnblogs.com/yanlingyin/archive/2011/12/26/Depth-firstsearch.html
//邻接表
//http://www.cnblogs.com/yanlingyin/archive/2011/12/26/Depth-firstsearch.html
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int vertex;
	struct node * nextnode;
};
typedef struct node * graph;
struct node head[9];
int visited[9];
void creatgraph(int node[20][2],int num)
{
	graph newnode;
	graph ptr;
	int from;
	int to;
	int i;
	for(int i=0;i<num;i++)
	{
		from =node[i][0];
		to=node[i][1];
		newnode=(graph)malloc(sizeof(struct node));
		newnode->vertex=to;
		newnode->nextnode=NULL;
		ptr=&(head[from]);
		while(ptr->nextnode!=NULL)
		{
			ptr=ptr->nextnode;
		}
		ptr->nextnode=newnode;
	}
}
void dfs(int current)
{
	graph ptr;
	visited[current]=1;
	printf("vertex[%d]\n",current );
	ptr=head[current].nextnode;
	while(ptr!=NULL)
	{
		if(visited[ptr->vertex]==0)
		{
			dfs(ptr->vertex);
		}
		ptr=ptr->nextnode;
	}
}
int main()
{
	graph ptr;
	int node[20][2] = { {1, 2}, {2, 1},  /* 边线数组     */  
                       {1, 3}, {3, 1},  
                       {1, 4}, {4, 1},  
                       {2, 5}, {5, 2},  
                       {2, 6}, {6, 2},  
                       {3, 7}, {7, 3},  
                       {4, 7}, {4, 4},  
                       {5, 8}, {8, 5},  
                       {6, 7}, {7, 6},  
                       {7, 8}, {8, 7} 
                      };
     int i;
     for(i=1;i<=8;i++)
     {
     	head[i].vertex=i;
     	head[i].nextnode=NULL;
     	visited[i]=0;
     }
     creatgraph(node,20);
     printf("Content of the graph's ADlist is:\n");
     for(i=1;i<=8;i++)
     {
     	printf("vertex%d->",head[i].vertex);
     	ptr=head[i].nextnode;
     	while(ptr!=NULL)
     	{
     		printf(" %d ", ptr->vertex);
     		ptr=ptr->nextnode;
     	}
     	printf("\n");
     }
     printf(" \nThe end of the dfs are:\n");
     dfs(1);
     printf("\n");
     printf("Press any key to quit ...");

}
