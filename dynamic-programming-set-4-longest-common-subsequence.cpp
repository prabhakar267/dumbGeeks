#include <bits/stdc++.h>
using namespace std;


/** Overlapping Subproblems **/
// int lcs(char *x, char *y, int m, int n){
// 	if(m == 0 || n == 0)
// 		return 0;
// 	if(x[m-1] == y[n-1])
// 		return 1 + lcs(x, y, m-1, n-1);
// 	else
// 		return max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));
// }


/** Memoization **/
int lcs(char *x, char *y, int m, int n){
	int len[m+1][n+1];

	for(int i=0; i<=m; i++){
		for(int j=0; j<=n; j++){
			if(i == 0 || j == 0)
				len[i][j] = 0;
			else if(x[i] == y[j]){
				len[i][j] = 1 + len[i-1][j-1];
			} else {
				len[i][j] = max(len[i-1][j], len[i][j-1]);
			}
		}
	}
	return len[m][n];
}

int main(){
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int ans = lcs(X, Y, strlen(X), strlen(Y));
	cout<<ans<<"\n";
	return 0;
}