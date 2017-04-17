#include <bits/stdc++.h>
using namespace std;


/** Memoization **/
int coin_change(int arr[], int size, int n){
	int dp[n+1][size];

	for(int i=0; i<size; i++){
		dp[0][i] = 1;
	}

	for(int i=1; i<n+1; i++){
		for(int j=0;j<size;j++){
			int excl, incl;
			// if(j>=1)
			// 	excl = dp[i][j-1];
			// else
			// 	excl = 0;
			excl = (j >= 1) ? dp[i][j-1] : 0;

			// if(arr[j] <= i)
			// 	incl = dp[i-arr[j]][j];
			// else
			// 	incl = 0;
			incl = (i >= arr[j]) ? dp[i-arr[j]][j] : 0;

			dp[i][j] = incl + excl;
		}
	}
	return dp[n][size-1];
}

/** Overlapping Subproblems **/
// int coin_change(int arr[], int size, int n){
// 	if(n < 0 || size <= 0)
// 		return 0;
// 	if(n == 0)
// 		return 1;

// 	return coin_change(arr, size, n-arr[size-1]) + coin_change(arr, size-1, n);
// }	


int main(){
	int N = 4;
	int arr[] = {1, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);

	int ans = coin_change(arr, n, N);
	cout<<ans<<"\n";
	return 0;
}