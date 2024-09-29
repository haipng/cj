#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> w(41), v(41);
vector<int> dp(1000000001, 0);

long long solve(int m, long long sum_v, int idx) {

}

int main() 
{
  cin >> n >> m;
  
  for(int i=0; i < n; i++) {
    cin >> w[i] >> v[i];
  }
  
  cout << solve(m, 0, 0);
  // for(int i=0; i<n; i++) {
  //   cout << dp[i]<< " ";
  // }

  return 0;
}