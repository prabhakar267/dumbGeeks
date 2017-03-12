#include<bits/stdc++.h>
using namespace std;

int main(){
    int price[] = {2, 30, 15, 10, 8, 25, 80};
    // int price[] = {10, 22, 5, 75, 65, 80};
    
    int n = sizeof(price) / sizeof(price[0]);
    int profit[n];

    for(int i=0;i<n;i++)
        profit[i] = 0;

    int max_price = price[n-1];

    for(int i=n-2;i>=0;i--){
        max_price = max(max_price, price[i]);
        profit[i] = max(profit[i+1], max_price-price[i]);
    }

    int min_price = price[0];

    for(int i=1; i<n;i++){
        min_price = min(min_price, price[i]);
        profit[i] = max(profit[i-1], profit[i] + (price[i] - min_price));
    }

    cout<<profit[n-1]<<"\n";

    return 0;
}
