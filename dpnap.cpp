#include <bits/stdc++.h>
using namespace std;

int dpnap(vector<int> weight,vector<int> value,vector<vector<int>> dp,int n,int W){
    // DP初期条件: dp[0][w] = 0
  for (int w = 0; w <= W; ++w) dp[0][w] = 0;

  // DPループ
  for (int i = 0; i < n; ++i) {
    for (int w = 0; w <= W; ++w) {
      if (w >= weight[i]) dp[i+1][w] = max(dp[i][w-weight[i]] + value[i], dp[i][w]);
      else dp[i+1][w] = dp[i][w];
    }
  }

  return dp[n][W];
}


int main() {
  // 入力
  int n, W;
  vector<int> weight(110), value(110);

  // DPテーブル
  vector<vector<int>> dp(110,vector<int>(10010));
  cin >> n >> W;
  
  for (int i = 0; i < n; ++i) {
    cin>>weight[i]>>value[i];
  }
  
  // DP初期条件: dp[0][w] = 0
  //for (int w = 0; w <= W; ++w) dp[0][w] = 0;
    /*
  // DPループ
  for (int i = 0; i < n; ++i) {
    for (int w = 0; w <= W; ++w) {
      if (w >= weight[i]) dp[i+1][w] = max(dp[i][w-weight[i]] + value[i], dp[i][w]);
      else dp[i+1][w] = dp[i][w];
    }
  }*/

  cout << dpnap(weight,value,dp,n,W) << endl;
}