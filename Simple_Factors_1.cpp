#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;

int main(){
    int t,a,b;
    int p[1000001] = {0},sum[1000001] = {0};
    for(int i = 2;i <= 1000000;i++){
        if(!p[i]){
            for(int j = 2*i;j<=1000000;j += i)
                p[j]++;
            p[i] = 1;
        }
    }
    
    for(int i = 2;i<=1000000;i++)
        sum[i] = sum[i-1] + p[i];
    
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<sum[b] - sum[a-1]<<endl;
    }
    return 0;
}
