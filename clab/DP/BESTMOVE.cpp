// https://c-lab.vn/problems/BESTMOVE
#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[10010];


int f[10010][11];
int dp[10010];


void solve() {
  int ans = -100000000;
  memset(f, 0, sizeof(f));
  
  for(int i=1; i<=n; i++) {
    int tmp = -100000000;
    for(int s=1; s<=k && s<=i; s++) {
      tmp = max(tmp, dp[i-s]);
    } 
    
    dp[i] = tmp + a[i];
    ans = max(ans, dp[i]);
  }
  
  cout << ans << "\n";
  
  
}


int main() 
{
  cin >> n >> k;
  
  for(int i=1; i<=n; i++) {
    cin >> a[i];
  }
  
  
  solve();
  
  
    return 0;
}