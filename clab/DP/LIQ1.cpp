#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];

// class DP {
//   public:
//   int len;
//   int prev_less;
//   int prev_greater;
// };

int dp[100010];


void solve() {
  memset(dp, 0, sizeof(dp));
  
  int ans = 0;
  for(int i=0; i<n; i++) {
    dp[i] = 1;
    for(int j=0; j < i; j++) {
      if(a[i] > a[j]) {
        dp[i] = max(dp[i], dp[j] + 1);  
      }
    }
    
    ans = max(ans, dp[i]) ;
  }
  
  cout << ans << endl;
}


int main() 
{
  cin >> n;
  
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  
  solve();
  
  
  return 0;
}
