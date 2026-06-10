#include<stdio.h>
int max( int a , int b){
if (a>b) return a ;
return b;
}
int knapsack( int W, int wt[], int val[], int n){
int K[n+1][W+1];
for ( int i=0;i<=n;i++){
    for (int w=0;w<=W;w++){
        if (i==0 || w==0){
            K[i][w]=0;
        }
        else if(wt[i - 1] <= w)
            {
            int include = val[i - 1] + K[i - 1][w - wt[i - 1]];
            int exclude = K[i - 1][w];

            K[i][w] = max(include, exclude);
            }
else
    {
    K[i][w] = K[i - 1][w];
    }
    }
}
    return K[n][W];
}
int main()
{
int n, W;
printf("Enter number of items: ");
scanf("%d", &n);
int wt[n], val[n];
printf("Enter weights of items:\n");
for(int i = 0; i < n; i++)
{
scanf("%d", &wt[i]);
}
printf("Enter profits of items:\n");
for(int i = 0; i < n; i++)
{
scanf("%d", &val[i]);
}
printf("Enter knapsack capacity: ");
scanf("%d", &W);
int result = knapsack(W, wt, val, n);
printf("Maximum Profit = %d\n", result);
return 0;
}
