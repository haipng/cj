// https://c-lab.vn/problems/NKTICK
#include <bits/stdc++.h>
using namespace std;

int n;
int t[60010]={};
int r[60010]={};
int dp[60010] = {};

void solve() {
  dp[0] = t[0];
  dp[1] = min(t[0] + t[1], r[0]);
  
  for(int i=2; i<n; i++) {
    
    dp[i] = min(dp[i-2]+r[i-1], dp[i-1]+t[i]);

  }
  cout << dp[n-1] << endl;
}

int main() 
{
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> t[i];
  }
  
  if(n == 1) {
    cout << t[0] << endl;
    return 0;
  }
  
  for(int i=0; i<n-1; i++) {
    cin >> r[i];
  }
  
  solve();
  return 0;
}