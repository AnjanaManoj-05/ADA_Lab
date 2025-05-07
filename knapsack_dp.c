#include <stdio.h>
#include <stdlib.h>
int max(int a,int b){
return(a>b)?a:b;
}
int dp(int capacity,int weight[],int values[],int n){
int dp[n+1][capacity+1];
printf("Knapsack table:\n");
for(int i=0;i<=n;i++){
    for(int w=0;w<=capacity;w++){
        if(i==0||w==0){
            dp[i][w]=0;
        }
        else if(weight[i-1]<=w){
            dp[i][w]=max(values[i-1]+dp[i-1][w-weight[i-1]],dp[i-1][w]);
        }
        else{
            dp[i][w]=dp[i-1][w];
        }
        printf("%d\t",dp[i][w]);
    }
    printf("\n");
}

return dp[n][capacity];
}
void main(){
int n,capacity;
 printf("Enter the number of items:");
 scanf("%d",&n);
 int values[n],weight[n];
 printf("Enter value and weight:\n");
 for(int i=0;i<n;i++){
    printf("Item: %d\n",(i+1));
    printf("--------------\n");
    printf("Weight:");
    scanf("%d",&weight[i]);
    printf("Values:");
    scanf("%d",&values[i]);
 }
 printf("Enter capacity:");
 scanf("%d",&capacity);
 int maxVal=dp(capacity,weight,values,n);
 printf("\nMaximum value in knapsack: %d",maxVal);
}

