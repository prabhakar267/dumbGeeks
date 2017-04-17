#include <bits/stdc++.h>
using namespace std;


/** Memoization **/
int knapsack(int W, int weight[], int values[], int n){
	int dp[W+1][n+1];

	for(int i=0;i<=W;i++){
		for(int j=0; j<=n; j++){
			if(j == 0 || i == 0)
				dp[i][j] = 0;
			else if(weight[j-1] > i){
				dp[i][j] = dp[i][j-1];
			} else {
				dp[i][j] = max(dp[i][j-1], values[j] + dp[i-weight[j-1]][j-1]);
			}
		}
	}
	return dp[W][n];
}


/** Overlapping Subproblems **/
// int knapsack(int W, int weight[], int values[], int n){
// 	if(n == 0 || W == 0)
// 		return 0;
// 	if(weight[n-1] > W)
// 		return knapsack(W, weight, values, n-1);
// 	else
// 		return max(knapsack(W, weight, values, n-1), knapsack(W - weight[n-1], weight, values, n-1) + values[n-1]);
// }


int main(){
	int values[] = {60, 100, 120};
	int weight[] = {10, 20, 30};
	int W = 50;
	int n = sizeof(values)/sizeof(values[0]);

	int ans = knapsack(W, weight, values, n);
	cout<<ans<<"\n";
	return 0;
}