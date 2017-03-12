#include<bits/stdc++.h>
using namespace std;

struct Interval{
    int start;
    int end;
};

bool compareFunction(struct Interval a, struct Interval b){
    return a.start < b.start;
}

int main(){
    Interval arr[] =  {{6,8},{1,3},{2,4},{4,7}};
    int n = sizeof(arr) / sizeof(arr[0]);
    bool flag = false;

    sort(arr, arr+n, compareFunction);

    for(int i=0;i<n-1;i++){
        if(arr[i].end >= arr[i+1].start){
            flag = true;
            break;
        }
    }

    cout<<((flag) ? "YES\n" : "NO\n");
    return 0;
}
