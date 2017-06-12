#include <iostream>
#include<climits>
using namespace std;



int coinsNeeded(int coins[],int amount,int n){
    //Base Case
    if(amount==0){
        return 0;
    }
    
    //Rec Case
    int ans = INT_MAX;
    
    for(int i=0;i<n;i++){
        // Think about it for 2 mins !
        if(amount-coins[i]>=0){
            int smallerAns = coinsNeeded(coins,amount-coins[i],n);
            if(smallerAns!=INT_MAX){
                ans = min(ans,smallerAns+1);
            }
        }
    }
    
     return ans;
    
}
// Bottom Up Dp
int coinsNeededDP(int coins[],int amount,int n){
    int *dp = new int[amount+1];
    
    for(int i=0;i<=amount;i++){
        dp[i] = INT_MAX;
    }
    
    
    
    dp[0] = 0;
    for(int rupay=1; rupay<=amount;rupay++){
        
        // Iterate Over Coins
        for(int i=0;i<n;i++){
            
            if(coins[i]<=rupay){
                
                int smallerAns = dp[rupay-coins[i]];
                if(smallerAns!=INT_MAX){
                    dp[rupay] = min(dp[rupay],smallerAns + 1);
                }
                
            }
            
        }
    }
    
    
    return dp[amount];
    
}



int main() {
    int us_coins[] = {1,7,10};
    int n = 3;
    int amount = 15; // Ans should be 3
    
    int indian_coins[] = { 1,2,5,10,50};
    int paise = 13;
    
    cout<<coinsNeeded(us_coins,amount,n)<<endl;
    cout<<coinsNeeded(indian_coins,paise,5)<<endl;
    
    cout<<"Using DP"<<endl;
    cout<<coinsNeededDP(indian_coins,paise,5)<<endl;
    cout<<coinsNeededDP(indian_coins,39,5)<<endl;
    
    
    
    
return 0;
}
