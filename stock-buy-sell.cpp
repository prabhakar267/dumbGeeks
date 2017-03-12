#include<bits/stdc++.h>
using namespace std;

struct interval{
    int buy, sell;
};

int main(){
    int arr[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct interval solution[n/2 + 1];

    int count=0, i=0;
    while(i < n-1){
        while((i < n-1) && arr[i+1]<=arr[i])
            i++;

        if(i >= n-1)
            break;

        solution[count].buy = i;
        i++;

        while((i<n) && arr[i]>=arr[i-1])
            i++;

        solution[count].sell = i-1;
        count++;
    }

    for(i=0;i<count; i++)
        cout<<solution[i].buy<<" "<<solution[i].sell<<'\n';

    return 0;
}
