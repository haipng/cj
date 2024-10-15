//https://c-lab.vn/problems/BCDIV
#include <bits/stdc++.h>
using namespace std;

long long f[30][30] = {};

void solve() {
  memset(f, 0, sizeof(f));
  int n, k;
  
  cin >> n >> k;
  
  f[0][0] = 1;
  //f[1][0] = 0;
  //f[1][1] = 1;
  
  for(int j=1; j<=n; j++) {
    for(int i=1; i<=k && i<=j;i++) {
      f[j][i] = f[j-1][i]*i + f[j-1][i-1];
      
      //cout << "n=" << j << " k=" << i << " f=" << f[j][i] << endl;
    }
  }
  
  cout << f[n][k] << "\n";
}

int main() 
{
  int t;
  cin >> t;
  
  while(t--) {
    solve();
  }
  
  
  
  return 0;
}