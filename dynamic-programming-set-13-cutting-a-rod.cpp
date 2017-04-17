#include <bits/stdc++.h>
using namespace std;


int cut_rod(int price[], int n){
	int value[n+1];
	value[0] = 0;

	for(int i=1;i<=n;i++){
		int max_value = INT_MIN;
		for(int j=0; j<i; j++)
			max_value = max(max_value, value[i-j-1] + price[j]);
		value[i] = max_value;
	}
	return value[n];
}


// int cut_rod(int price[], int n){
// 	if(n <= 0)
// 		return 0;

// 	int max_value = 0;
// 	for(int i=0; i<n; i++){
// 		max_value = max(max_value, price[i] + cut_rod(price, n-(i+1)));
// 	}

// 	return max_value;
// }

int main(){
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int size = sizeof(arr)/sizeof(arr[0]);

	int ans = cut_rod(arr, size);
	cout<<ans<<"\n";

	return 0;
}
