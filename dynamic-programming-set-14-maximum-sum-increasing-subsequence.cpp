#include <bits/stdc++.h>
using namespace std;

int maximun_increasing_subsequence_sum(int arr[], int n){
	int ans = INT_MIN;
	int dp[n];

	for(int i=0;i<n;i++)
		dp[i] = arr[i];

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i] > arr[j])
				dp[i] = max(dp[i], arr[i] + dp[j]);
		}
	}

	for(int i=0; i<n; i++)
		ans = max(ans, dp[i]);
	return ans;
}

int main(){
	int arr[] = {1, 101, 2, 3, 100, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);

	int ans = maximun_increasing_subsequence_sum(arr, n);
	cout<<ans<<"\n";

	return 0;
}
