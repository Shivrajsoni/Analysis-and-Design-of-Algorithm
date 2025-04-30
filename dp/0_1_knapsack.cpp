#include <iostream>
#include <vector>
using namespace std;

int knapsackRec(int W, vector<int> &val, vector<int> &wt, int n) {

  // Base Case
  if (n == 0 || W == 0)
    return 0;

  int pick = 0;

  // Pick nth item if it does not exceed the capacity of knapsack
  if (wt[n - 1] <= W)
    pick = val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1);

  // Don't pick the nth item
  int notPick = knapsackRec(W, val, wt, n - 1);

  return max(pick, notPick);
}

// memorization

int memorizationKnapsack(int ind,int W,vector<int> &val, vector<int> &wt,vector<vector<int>>&dp){
  if(ind==0){
    if(wt[0]<=W){
      return val[0];
    }
    return 0;
  }

  if(dp[ind][W]!=-1) return dp[ind][W];
  int notTake = 0 + memorizationKnapsack(ind-1,W,val,wt,dp);
  int take = val[ind] + memorizationKnapsack(ind - 1,W - wt[ind],val,wt,dp);
  return dp[ind][W] = max(notTake,take);
}
// tabulation

int knapsack(int W, vector<int> &val, vector<int> &wt) {
  int n = val.size();
  return knapsackRec(W, val, wt, n);
}


// int setnotationKnapSack(int ind,int W,vector<int> &val, vector<int> &wt){
//    
// }

int main() {
  vector<int> wt = {4, 5, 1};
  vector<int> profit = {1, 2, 3};
  int Max_Wt = 4;
  int n = 3;
//  vector<vector<int>>dp(n,vector<int>(Max_Wt+1,-1));

 // cout<< "maximum profit using memorization method is : " <<memorizationKnapsack(n-1,Max_Wt,wt,profit,dp)<<endl;

  

  // cout << "Maximum profit using recursive method :"
  //      << knapsack(Max_Wt, profit, wt) << endl;

  // return 0;


  // tabulation method

  vector<vector<int>>dp(n,vector<int>(Max_Wt + 1,0));
  
  for(int W = wt[0]; W<Max_Wt;W++){
    dp[0][W]= profit[0];
  }

  for(int ind = 1;ind<n;ind++){
    for(int W = 0;W<=Max_Wt;W++){
      int notTake = 0+ dp[ind-1][W];
      int take = INT_MIN;
      if(wt[ind]<=W){
        take = profit[ind] + dp[ind-1][W-wt[ind]];
      }
      dp[ind][W] = max(take,notTake);
    }

  }
  cout<< "Maximum Porfit using tabulation method is : "<<dp[n-1][Max_Wt]<<endl;
}
