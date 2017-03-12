#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[] = {1, -2, -3, 0, 7, -8, -2};
	int n = sizeof(arr)/sizeof(arr[0]);

	int max_so_far = 1;
	int min_so_far = 1;
	int total_max = 1;

	for(int i=0;i<n;i++){
		if(arr[i] > 0){
			max_so_far = max_so_far * arr[i];
			min_so_far = min(min_so_far * arr[i], 1);
		} else if(arr[i] == 0){
			max_so_far = 1;
			min_so_far = 1;
		} else {
			int temp = max_so_far;
			max_so_far = max(min_so_far * arr[i], 1);
			min_so_far = temp * arr[i];
		}

		if(total_max < max_so_far)
			total_max = max_so_far;
	}

	cout<<total_max;

	cout<<"\n";
	return 0;
}
