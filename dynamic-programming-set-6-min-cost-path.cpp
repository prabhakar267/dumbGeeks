#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

/** Memoization **/
int minCost(int cost[R][C], int m, int n){
	int dp[R][C];
	int i,j;
	dp[0][0] = cost[0][0];
	
	for(i=1; i<=m; i++)
		dp[i][0] = dp[i-1][0] + cost[i][0];
	
	for(j=1; j<=n; j++)
		dp[0][j] = dp[0][j-1] + cost[0][j];

	for(i=1; i<=m; i++){
		for(j=1; j<=n; j++){
			dp[i][j] = cost[i][j] + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
		}
	}
	return dp[m][n];
}

/** Overlapping Subproblems **/
// int minCost(int cost[R][C], int m, int n){
// 	if(m == 0 && n == 0)
// 		return cost[0][0];

// 	if(m == 0)
// 		return cost[0][n] + minCost(cost, 0, n-1);

// 	if(n == 0)
// 		return cost[m][0] + minCost(cost, m-1, 0);

// 	return cost[m][n] + min(minCost(cost, m-1, n-1), min(minCost(cost, m, n-1), minCost(cost, m-1, n)));
// }


int main(){
	int cost[R][C] = { {1, 2, 2, 9},
                      {4, 8, 2, 6},
                      {1, 5, 8, 1},
                      {4, 7, 8, 3} };

	int ans = minCost(cost, 2, 2);
	cout<<ans<<"\n";
	return 0;
}