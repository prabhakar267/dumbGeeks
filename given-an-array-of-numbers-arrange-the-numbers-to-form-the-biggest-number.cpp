#include<bits/stdc++.h>
using namespace std;

int compare(string a, string b){
	string ab = a.append(b);
	string ba = b.append(a);

	return (ab > ba) ? 1 : 0;
}

int main(){
	vector <string> arr;

	arr.push_back("54");
    arr.push_back("546");
    arr.push_back("548");
    arr.push_back("60");

    sort(arr.begin(), arr.end(), compare);
    // cout<<compare(arr[0], arr[1]);

    for(int i=0;i<arr.size();i++){
    	cout<<arr[i];
    }
    cout<<"\n";
    return 0;
}
