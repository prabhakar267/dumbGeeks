#include <bits/stdc++.h>
using namespace std;


int longest_palindrome_substring(char *str){
	int max_length = 1;
	int start_index = 0;
	int n = strlen(str);

	bool dp[n][n];
	memset(dp, false, sizeof(dp));

	for(int i=0;i<n;i++)
		dp[i][i] = true;

	for(int i=0;i<n-1;i++){
		if(str[i] == str[i+1]){
			dp[i][i+1] = true;
			max_length = 2;
			start_index = i;			
		}
	}

	for(int k=3;k<=n;k++){
		for(int i=0;i<n-k+1;i++){
			int j = i+k-1;
			if(dp[i+1][j-1] && str[i] == str[j]){
				dp[i][j] = true;
				if(k > max_length){
					max_length = k;
					start_index = i;
				}
			}
		}
	}
	for(int i=0;i<max_length;i++){
		cout<<str[i + start_index];
	}
	cout<<"\n";
	return max_length;
}


int main(){
	char str[] = "forgeeksskeegfor";
	int ans = longest_palindrome_substring(str);
	cout<<ans<<"\n";

	return 0;
}
