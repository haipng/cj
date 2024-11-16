#include <bits/stdc++.h>
using namespace std;

const int MAXN=10000;
int n,m;
int x[MAXN];

int f_drop[MAXN][501];
int f_bypass[MAXN][501];
int f_take[MAXN][501];

void solve() {
    memset(f_drop, 0, sizeof(f_drop));
    memset(f_bypass, 0, sizeof(f_bypass));
    memset(f_take, 0, sizeof(f_take));
    
    f_take[0][1] = x[0];

    for(int i=1; i<n; i++) {
      
      for(int k=0; k<=m; k++) {
        // bypass
        f_bypass[i][k] = max(f_drop[i-1][k], f_bypass[i-1][k]);
        f_bypass[i][k] = max(f_bypass[i][k], f_take[i-1][k]);
        
        // drop
        if(k<m) {
          f_drop[i][k] = max(f_drop[i-1][k+1], f_bypass[i-1][k+1]);
          f_drop[i][k] = max(f_drop[i][k], f_take[i-1][k+1]);
        }
        
        // take
        if(k==1) {
          f_take[i][k] = max(f_bypass[i-1][0], f_drop[i-1][0]) + x[i];
        }
        if(k>1) {
          f_take[i][k] = f_take[i-1][k-1] + x[i];
        }
      }
    }
    
    cout << max(f_bypass[n-1][0], f_drop[n-1][0]) << endl;
}

int main()
{
    cin>>n>>m;
    
    for(int i=0; i<n; i++) {
      cin >> x[i];
    }
    
    solve();
    
    return 0;
}