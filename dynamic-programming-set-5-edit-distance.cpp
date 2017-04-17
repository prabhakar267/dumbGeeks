#include <bits/stdc++.h>
using namespace std;


/** Memoization **/
// int edit_distance(string x, string y, int m, int n){
// 	int dp[m+1][n+1];
// 	for(int i=0; i<=m; i++){
// 		for(int j=0; j<=n; j++){
// 			if(i == 0){
// 				dp[i][j] = j;
// 			} else if(j == 0){
// 				dp[i][j] = i;
// 			} else if(x[i-1] == y[j-1]){
// 				dp[i][j] = dp[i-1][j-1];
// 			} else {
// 				// insert, remove, replace
// 				dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
// 			}
// 		}
// 	}
// 	return dp[m][n];
// }

/** Overlapping Subproblems **/
int edit_distance(string x, string y, int m, int n){
	if(m == 0)
		return n;
	if(n == 0)
		return m;
	
	if(x[m-1] == y[n-1])
		return edit_distance(x, y, m-1, n-1);
	else
		return 1 + min(edit_distance(x, y, m-1, n-1), min(edit_distance(x, y, m, n-1), edit_distance(x, y, m-1, n)));
}

int main(){
	string X = "sunday";
	string Y = "saturday";

	int ans = edit_distance(X, Y, X.length(), Y.length());
	cout<<ans<<"\n";
	return 0;
}