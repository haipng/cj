//https://c-lab.vn/problems/CTNBULLS
#include <bits/stdc++.h>
using namespace std;

int n,k;
long long f[100010] = {};
const long long MOD = 2111992;

void solve() {
  f[0] = 1;
  f[1] = 2;
  
  for(int i=2; i<=n; i++) {
    if(i > k) {
      // f[i-1] for add C at nth pos
      // f[i-1 - k] for add C..CD at the end
      f[i] = f[i-1] + f[i-1-k];
    }
    else {
      f[i] = f[i-1] + 1;
    }
    f[i] %= MOD;
    
    //cout << "f[" << i << "]=" << f[i] << endl;
  }
  cout << f[n] << "\n";
}

int main() 
{

  cin >> n >> k;
  
  solve();
  
    return 0;
}