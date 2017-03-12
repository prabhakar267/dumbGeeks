#include <bits/stdc++.h>
using namespace std;


void printReverse(int arr[], int start, int end){
	if(end <= start)
		return;
	int temp;
	temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;

	printReverse(arr, start + 1, end-1);
	return;
}

int main(){
	// int a[] = {-2, -3, 4, -1, -2, 1, 5, -3, 0};
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(a)/sizeof(a[0]);
	int d = 2;
	
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";

	printReverse(a, 0, d-1);
	printReverse(a, d, n-1);
	printReverse(a, 0, n-1);
	
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	return 0;
}