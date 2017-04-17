#include <bits/stdc++.h>
using namespace std;


void fill0X(int row, int col){
	int top=0, bottom=row, left=0, right=col;
	int arr[row][col];

	int flag = 1;
	while(top < bottom && left < right){
		for(int i=left; i<right; i++)
			arr[top][i] = flag;

		top++;

		for(int i=top; i<bottom; i++)
			arr[i][right-1] = flag;

		right--;

		if(bottom > top){
			for(int i=right; i>=left; i--)
				arr[bottom-1][i] = flag;

			bottom--;
		}

		if(left < right){
			for(int i=bottom; i>=top; i--)
				arr[i][left] = flag;

			left++;
		}

		flag = ((flag) ? 0 : 1);
	}

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cout<<(arr[i][j] ? "1" : "-")<<" ";
		}
		cout<<"\n";
	}
	// cout<<"\n";
}


int main(){
	fill0X(10, 16);
	return 0;
}
