#include <bits/stdc++.h>
using namespace std;


int max_bitonic(int arr[], int n){
	int lis[n], lds[n];

	for(int i=0; i<n;i++){
		lis[i] = 1;
		lds[i] = 1;
	}

	for(int i=1; i<n;i++){
		for(int j=0; j<i; j++){
			if(arr[i] > arr[j])
				lis[i] = max(lis[j]+1, lis[i]);
		}
	}


	for(int i=n-2; i>=0;i--){
		for(int j=n-1; j>i; j--){
			if(arr[i] > arr[j])
				lds[i] = max(lds[j]+1, lds[i]);
		}
	}

	int ans = INT_MIN;
	for(int i=0; i<n; i++)
		ans = max(ans, lis[i] + lds[i]);

	return ans-1;
}


int main(){
	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int n = sizeof(arr)/sizeof(arr[0]);

	int ans = max_bitonic(arr, n);
	cout<<ans<<"\n";

	return 0;
}
