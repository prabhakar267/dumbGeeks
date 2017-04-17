#include <bits/stdc++.h>
using namespace std;


long long int get_ugly_number(int n){
	long long int ans[n];
	int i2=0,i3=0,i5=0;
	ans[0]=1;

	long long int next_multiple_2 = 2;
	long long int next_multiple_3 = 3;
	long long int next_multiple_5 = 5;
	long long int next_ugly_number;

	for(int i=1;i<n;i++){
		next_ugly_number = min(next_multiple_2, min(next_multiple_3, next_multiple_5));
		ans[i] = next_ugly_number;

		if(next_ugly_number == next_multiple_2){
			i2++;
			next_multiple_2 = ans[i2] * 2; 
		}

		if(next_ugly_number == next_multiple_3){
			i3++;
			next_multiple_3 = ans[i3] * 3; 
		}

		if(next_ugly_number == next_multiple_5){
			i5++;
			next_multiple_5 = ans[i5] * 5; 
		}
	}

	return next_ugly_number;
}


int main(){
	int n = 150;	
	long long int ans = get_ugly_number(n);
	cout<<ans<<"\n";

	return 0;
}
