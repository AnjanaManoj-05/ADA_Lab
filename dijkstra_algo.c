#include <stdio.h>
#include <time.h>
#include <limits.h>
#define MAX 100
#define INF INT_MAX
clock_t start,end;
void dijkstra(int graph[MAX][MAX],int n,int start1){
   int dst[MAX],visited[MAX]={0};
   for(int i=0;i<n;i++){
    dst[i]=INF;
   }
   dst[start1]=0;
   for(int count=0;count<n-1;count++){
    int min=INF,u;
    for(int v=0;v<n;v++){
        if(!visited[v] && dst[v]<=min){
            min=dst[v];
            u=v;
        }
        visited[u]=1;
    }
    for(int v=0;v<n;v++){
        if(!visited[v]&& graph[u][v] && dst[u]!=INF && dst[u]+graph[u][v]<dst[v])
        dst[v]= dst[u]+graph[u][v];
    }

   }
   printf("Vertex\tDistance from source %d\n",start1);
   for(int i=0;i<n;i++){
    printf("%d\t\t%d\n",i,dst[i]);
   }
}
void main(){
  int n,graph[MAX][MAX],start1;

  double t;
  printf("Enter the number of vertices:");
  scanf("%d",&n);
  printf("Enter the adjacency matrix:");
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&graph[i][j]);
        if(graph[i][j]==0 && i!=j){
            graph[i][j]=INF;
        }
    }
  }
  printf("Enter the source vertex:");
  scanf("%d",&start1);
  start=clock();
  dijkstra(graph,n,start1);
  end=clock();
  t=(double)(end-start)/CLOCKS_PER_SEC;
  printf("The time taken: %lf",t);
}
