#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[] = {12, 11, 10, 5, 6, 2, 30};
	int n = sizeof(arr)/sizeof(arr[0]);

	int greater[n]; // right
	int smaller[n]; // left
	
	int smallest_so_far = 0;
	smaller[0] = -1;
	for(int i=0;i<n;i++){
		if(arr[i] > arr[smallest_so_far]){
			smaller[i] = smallest_so_far;
		} else {
			smallest_so_far = i;
			smaller[i] = -1;
		}
	}
	
	int greatest_so_far = n-1;
	greater[n-1] = -1;
	for(int i=n-2;i>=0;i--){
		if(arr[i] < arr[greatest_so_far]){
			greater[i] = greatest_so_far;
		} else {
			greatest_so_far = i;
			greater[i] = -1;
		}
	}
	
	for(int i=1;i<n-1;i++){
		if(greater[i] != -1 && smaller[i] != -1){
			cout<<arr[smaller[i]]<<" "<<arr[i]<<" "<<arr[greater[i]];
			break;
		}
	}

	cout<<"\n";
	return 0;
}
