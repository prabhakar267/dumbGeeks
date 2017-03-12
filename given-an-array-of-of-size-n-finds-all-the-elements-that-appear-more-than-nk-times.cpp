#include<bits/stdc++.h>
using namespace std;

struct node{
    int count;
    int key;
};

int main(){
    int arr[] = {2, 3, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    struct node aux[k-1];
    
    for(int i=0; i<k-1; i++){
        aux[i].count = 0;
    }

    for(int i=0;i<n;i++){
        int j;
        for(j=0;j<k-1;j++){
            if(aux[j].key == arr[i]){
                aux[j].count += 1;
                break;
            }
        }

        if(j == k-1){
            int l;
            for(l=0;l<k-1;l++){
                if(aux[l].count == 0){
                    aux[l].key = arr[i];
                    aux[l].count = 1;
                    break;
                }
            }

            if(l == k-1){
                for(l=0; l<k-1; l++)
                    aux[l].count -= 1;
            }
        }
    }

    for(int i=0; i<k-1; i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(arr[j] == aux[i].key)
                count++;
        }

        if(count >= (n/k))
            cout<<aux[i].key<<"\n";
    }

    return 0;
}
