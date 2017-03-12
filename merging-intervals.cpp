#include<bits/stdc++.h>
using namespace std;

struct interval{
    int start, end;
};

bool compare(interval a, interval b){
    return a.end > b.end;
}

int main(){
    interval arr[] = {{1,20}, {4,6}, {29,41}};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr+n, compare);

    int curr_end = arr[0].end;
    int curr_start = arr[0].start;

    for(int i=1;i<n;i++){
        if(curr_start <= arr[i].end){
            curr_start = min(arr[i].start, curr_start);
        } else {
            cout<<curr_start<<" "<<curr_end<<"\n";
            curr_start = arr[i].start;            
            curr_end = arr[i].end;            
        }
    }
    cout<<curr_start<<" "<<curr_end<<"\n";

    return 0;
}
