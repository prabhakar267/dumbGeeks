#include <bits/stdc++.h>
using namespace std;

int main(){
	// int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3, 0};
	// int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	// int arr[] = {5,  5, 10, 40, 50, 35};
	// int arr[] = {16, 17, 4, 3, 5, 2};
	int arr[] = {1, 60, -10, 70, -80, 85};

	int n = sizeof(arr)/sizeof(arr[0]);

	int min_sum = arr[0] + arr[1];
	int sum;
	sort(arr, arr+n);

	int l = 0, r = n-1;
	int min_l = 0, min_r = 1;
	while(l < r){
		sum = arr[l] + arr[r];
		if(abs(min_sum) > abs(sum)){
			min_sum = sum;
			min_r = r;
			min_l = l;
		}

		if(sum > 0){
			r--;
		} else {
			l++;
		}
	}

	cout<<arr[min_l]<<" "<<arr[min_r];

	// for(int i=0;i<n;i++)
	// 	cout<<arr[i]<<" ";
	cout<<"\n";
	return 0;
}