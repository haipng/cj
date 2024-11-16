#include <bits/stdc++.h>
using namespace std;

int n;
int p[1010];

int f[1010][1010];

const int MAX_INT = 9999999;
const int BUY = 0;
const int FREE = 1;
void solve() {
  int voucher = 0;
  
  for(int i=0; i<1010; i++) {
    for(int j=0; j<1010; j++) {
        f[i][j] = MAX_INT;
    }
  }

  

  if(p[1] > 100) {
    voucher++;
  }
  f[1][voucher] = p[1];


  for(int i=2; i<=n; i++) {
    for(int v = voucher; v>=0; v--) {
      f[i][v] = min(f[i-1][v+1], f[i-1][v] + p[i]);
      if(p[i] > 100) f[i][v+1] = f[i][v];
    }
    
    if(p[i] > 100) {
      voucher++;
    }
    
    //f[i][voucher] = f[i-1][voucher] + p[i];
    
    
    
    

    
    
    for(int v=0; v<=voucher; v++) {
      cout << f[i][v] << " ";
    }
    // cout << endl;
    // for(int v=0; v<=voucher; v++) {
    //   cout << f[i][v][1] << " ";
    // }
    cout << endl << endl;
  }

  int ans = MAX_INT;
  
  for(int i=0; i<=voucher; i++) {
    ans = min(ans, f[n][i]);  
  }
  cout << ans << endl;
}

int main() 
{
  cin >> n;
  
  for(int i=1; i<=n; i++) {
    cin >> p[i]; 
  }
  
  solve();
  
  return 0;
}

/* test
8
102
0
0
0
998
101
110
999
*/