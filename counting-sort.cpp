#include<bits/stdc++.h>
#define RANGE 255

using namespace std;

int main(){
    char arr[] = "geeksforgeeks";

    int count_array[RANGE] = {0};
    int n = strlen(arr);
    char output[n];

    for(int i=0;i<n;i++)
        count_array[arr[i]]++;

    for(int i=1;i<RANGE;i++)
        count_array[i] += count_array[i-1];

    for(int i=0;i<n;i++){
        char temp = arr[i];
        int index = count_array[temp];

        count_array[temp]--;
        output[index-1] = temp;
    }

    for(int i=0;i<n;i++)
        cout<<output[i]<<" ";

    cout<<"\n";
    return 0;
}
