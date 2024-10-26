//https://codejam.lge.com/problem/25571

#include <bits/stdc++.h>
using namespace std;


long long n;
long long a[100100];
long long dp[100100];


void solve() {
  memset(dp, 0, sizeof(dp));
  
  long long len = 2;
  
  dp[0] = 0;
  if(a[0] == a[1]) {
    dp[1] = 0;  
  }
  else {
    len = 2;
    dp[1] = 1;
  }
  
  for(long long i=2; i<n; i++) {
    if(a[i-1] == a[i]) {
      len = 0;
      dp[i] = dp[i-1];
    }
    if((a[i-2] <= a[i-1] && a[i-1] < a[i])
    || (a[i-2] >= a[i-1] && a[i-1] > a[i])) {
      len = 2;
      dp[i] = dp[i-1]+1;
    }
    else {
      dp[i] = dp[i-1] + len;
      len++;
    }
  }
  
  cout << dp[n-1] << endl;
  
}




int main() 
{
  int t; cin >> t;
  
  while (t--) {
    memset(a, 0, sizeof(a));
    
    cin >> n;
    for(long long i=0;i<n;i++) {
      cin >> a[i];
    }
    
    solve();
  }
  
  return 0;
}