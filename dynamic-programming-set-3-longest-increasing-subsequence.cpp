#include <bits/stdc++.h>
using namespace std;

int main(){
	// int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int arr[] = {50, 3, 10, 7, 40, 80};
	int n = sizeof(arr) / sizeof(arr[0]);

	int dp[n];

	for(int i=0;i<n;i++)
		dp[i] = 1;

	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i] > arr[j])
				dp[i] = max(dp[i] , dp[j] + 1);
		}
	}

	int lis_len = 0;
	for(int i=0;i<n;i++)
		lis_len = max(lis_len, dp[i]);

	cout<<lis_len<<"\n";
	return 0;
}