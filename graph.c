#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}graph;

void read_graph(graph *ad[],int no_of_nodes);
void print_graph(graph *ad[],int no_of_nodes);


int main()
{
    int i,j,k,nodes;
    printf("Enter the nodes:");
    scanf("%d",&nodes);
    
    graph *ad[nodes];
    for(i=0;i<nodes;i++)
    {
        ad[i]=NULL;
    }
    read_graph(ad,nodes);
    print_graph(ad,nodes);
    
    int a = 0;
    return 0;
    
}

void read_graph(graph *ad[],int no_of_nodes)
{
    graph *new;
    int i,j,k,val;
    
    for(i=0; i < no_of_nodes;i++)
    {
        graph *last = NULL;
        printf("\n Enter the number of neighbours of %d:",i+1);
        scanf("%d",&k);
        for(j=0;j<k;j++)
        {
            printf("Enter the value of %d neighbour of %d:",j+1,i+1);
            scanf("%d",&val);
            new=(graph *)malloc(sizeof(graph));
            new->data=val;
            new->link=NULL;
            if(ad[i]==NULL)
            {
                ad[i]=new;
            }
            else
            {
                last->link=new;
            }
            last=new;
        }
    }
}

void print_graph(graph *ad[],int no_of_nodes)
{
    graph *ptr=NULL;
    int i,j;
    for(i = 0; i< no_of_nodes; i++)
    {
        ptr = ad[i];
        printf("\n The neighbours of %d are : ", i+1);
        while(ptr != NULL)
        {
            printf("%d\t",ptr->data);
            ptr = ptr->link;
        }
    }
    
}
