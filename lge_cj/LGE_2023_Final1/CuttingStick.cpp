//https://codejam.lge.com/problem/27361
#include <bits/stdc++.h>
using namespace std;

long long n, k, a,b;
long long s[111];
const long long INF = 1e18;

long long dp[10010] = {};

long long cost(long long x) {
  if(x == 1) return 0;
  return a*(x-1)*(x-1)+b;
}

void solve() {
  for(int i=0; i<10010; i++) {
    dp[i] = INF;
  }
  
  int total = 0;
  for(int i=0;i<n; i++) {
    total += s[i];
  }
  

  for(int i=0; i<n; i++) {
    for(int j=total; j >= 0; j--) {
      if(j <= s[i]) {
        dp[j] = min(dp[j], cost(s[i]));
      }
      else {
        dp[j] = min(dp[j], dp[j-s[i]] + cost(s[i])); 
      }
    }
  }
  
  long long ans = INF;
  for(int i=k; i<=total; i++) {
    ans = min(ans, dp[i]);
  }
  
  cout << ans << endl;
}



int main() 
{
  int t; cin >> t;
  
  while(t--) {
    cin >> n >> k >> a >> b;
    memset(s, 0, sizeof(s));
    for(int i=0; i<n; i++) {
      cin >> s[i];
    }
    solve();
  }
  
  
  return 0;
}