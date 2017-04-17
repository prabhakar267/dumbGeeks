#include <bits/stdc++.h>
using namespace std;

#define ROW 4
#define COL 5


int kadane(int arr[], int size, int *start, int *end){
	int sum_so_far = 0; 
	int sum_ending_here = 0;
	int temp_start = 0;

	for(int i=0; i<size; i++){
		sum_ending_here += arr[i];

		if(sum_ending_here < 0){
			sum_ending_here = 0;
			temp_start = i+1;
		}

		if(sum_so_far < sum_ending_here){
			sum_so_far = sum_ending_here;
			*start = temp_start;
			*end = i;
		}
	}
	return sum_so_far;
}


void find_max_sum(int arr[ROW][COL]){
	int ans_left = -1;
	int ans_right = -1;
	int ans_top = -1;
	int ans_bottom = -1;
	int max_sum = INT_MIN;
	int start=-1, end=-1;

	int temp[ROW];

	for(int left=0; left<COL; left++){
		
		memset(temp, 0, sizeof(temp));

		for(int right=left; right<COL; right++){
			for(int i=0;i<ROW;i++)
				temp[i] += arr[i][right];

			int sum;
			sum = kadane(temp, ROW, &start, &end);

			if(sum > max_sum){
				ans_left = left;
				ans_right = right;
				ans_top = start;
				ans_bottom = end;
				max_sum = sum;
			}
		}
	}
	cout<<ans_left<<" "<<ans_top<<"\n";
	cout<<ans_right<<" "<<ans_bottom<<"\n";
	cout<<max_sum<<"\n";
}


int main(){
	int M[ROW][COL] = {{1, 2, -1, -4, -20},
					   {-8, -3, 4, 2, 1},
					   {3, 8, 10, 1, 3},
					   {-4, -1, 1, 7, -6}
					  };	

	find_max_sum(M);
	cout<<"\n";
	
	return 0;
}
