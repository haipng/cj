//https://c-lab.vn/problems/LATGACH
#include <bits/stdc++.h>
using namespace std;

long long f[100] = {};

void solve() {
  memset(f, 0, sizeof(f));
  f[0] = 0;
  f[1] = 1;
  f[2] = 2;
  
  int n; cin >> n;
  
  for(int i=3; i<=n; i++) {
    f[i] = f[i-1] + f[i-2];
  }
  
  cout << f[n] << "\n"; 
}


int main() 
{
  
  int t; cin >> t;
  
  while(t--) {
    solve();
  }
  
  return 0;
}