#include <bits/stdc++.h>
using namespace std;


/** Memoization **/
int egg_drop(int n, int k){
	int dp[n+1][k+1];
	for(int i=0; i<=n; i++){
		dp[i][0] = 0;
		dp[i][1] = 1;
	}

	for(int i=0; i<=k; i++){
		dp[0][i] = 0;
		dp[1][i] = i;
	}

	for(int i=2; i<=n; i++){
		for(int j=2; j<=k; j++){
			dp[i][j] = INT_MAX;
			for(int x=1; x<=j; x++){
				int temp = 1 + max(dp[i-1][x-1], dp[i][j-x]);
				dp[i][j] = min(dp[i][j], temp);
			}
		}
	}
	return dp[n][k];
}

/** Overlapping Subproblems **/
// int egg_drop(int n, int k){
// 	if(k == 0 || k == 1 || n == 1)
// 		return k;

// 	int ans = INT_MAX;
// 	for(int i=1;i<=k;i++){
// 		int temp = max(egg_drop(n-1, i-1), egg_drop(n, k-i));
// 		ans = min(ans, temp);
// 	}
// 	return ans + 1;
// }


int main(){
	int n = 2, k = 36;

	int ans = egg_drop(n, k);
	cout<<ans<<"\n";
	return 0;
}