// https://c-lab.vn/problems/CAITUI3
#include <bits/stdc++.h>
using namespace std;

int n,m;
int w[100] = {};
int v[100] = {};

int dp[100] = {};


void solve() {
  dp[m] = 0;
  
  for(int i=0; i<n; i++) {
    for(int j=m; j>=w[i]; j--) {
      dp[j] = max(dp[j], dp[j-w[i]] + v[i]); 
    }
  }
  
  cout << dp[m] << endl;
}


int main() 
{
  cin >>n>>m;
  
  for(int i=0; i<n; i++) {
    cin >> w[i] >> v[i];
  }
  
  solve();
    return 0;
}