#include <bits/stdc++.h>
using namespace std;


bool checkPartition(int arr[], int size, int sum){
	if(sum == 0)
		return true;

	if(sum != 0 && size == 0)
		return false;

	return checkPartition(arr, size-1, sum - arr[size - 1]) || checkPartition(arr, size-1, sum);
}

bool findPartiion(int arr[], int size){
	int sum=0;
	for(int i=0; i<size; i++)
		sum += arr[i];

	if(sum %2 != 0)
		return false;

	return checkPartition(arr, size, sum/2);
}


int main(){
	// int arr[] = {3, 1, 5, 9, 12};
	int arr[] = {1, 5, 11, 5, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<((findPartiion(arr, n)) ? "True":"False")<<"\n";
	
	return 0;
}
