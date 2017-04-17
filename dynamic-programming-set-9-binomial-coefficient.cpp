#include <bits/stdc++.h>
using namespace std;


/** Space Optimized **/
int binomial_coeff(int n, int k){
	int C[k+1];

	memset(C, 0, sizeof(C));

	C[0] = 1;

	for(int i=1; i<=n; i++){
		for(int j = min(i,k); j>0; j--){
			C[j] = C[j] + C[j-1];
		}
	}
	return C[k];
}


/** Memoization **/
// int binomial_coeff(int n, int k){
// 	int dp[n+1][k+1];

// 	for(int i=0; i<=n; i++){
// 		for(int j=0; j<= min(i,k); j++){
// 			if(j == 0 || j == i)
// 				dp[i][j] = 1;
// 			else 
// 				dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
// 		}
// 	}
// 	return dp[n][k];
// }


/** Overlapping Subproblems **/
// int binomial_coeff(int n, int k){
// 	if(k == 0 || k == n)
// 		return 1;
// 	return binomial_coeff(n-1, k) + binomial_coeff(n-1, k-1);
// }

int main(){
	int n = 5, k = 2;

	int ans = binomial_coeff(n, k);
	cout<<ans<<"\n";
	return 0;
}