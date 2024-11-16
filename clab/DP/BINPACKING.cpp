#include <bits/stdc++.h>
using namespace std;

int l,n;
int a[100010];

void solve() {
  if(n>20) return;
  
  int ans = 1e9;
  
  for(int i=0; i < (1<<n); i++) {
    int nbox = 2;
    int b1 = 0;
    int b2 = 0;
    
    for(int j=0; j<n; j++) {
      if(i & (1 << j)) {
        if(b1+a[j] > l) {
          nbox++;
          b1 = a[j];
        }
        else {
          b1 += a[j];
        }
      }
      else {
        if(b2+a[j] > l) {
          nbox++;
          b2 = a[j];
        }
        else {
          b2 += a[j];
        }
      }
    }
    ans = min(ans, nbox);
  }
  cout << ans << endl;
}

const int INF = 1e9;
pair<int, int> f[10010][5005];

void solve2() {
  for(int i=0; i<n; i++) {
    for(int j=0; j<=l; j++) {
      f[i][j] = {INF, l};
    }
  }
  
  f[0][a[0]] = {2, 0};
  f[0][0] = {2, a[0]};
   
  for(int i=1; i<n; i++) {
    for(int j=0; j<=l; j++) {
      // put into box 1
      pair<int,int> b1 = f[i-1][j];
      
      if(j+a[i] > l) {
        b1.first++;
        
        f[i][a[i]] = min(f[i][a[i]], b1);
      }
      else {
        f[i][j+a[i]] = min(f[i][j+a[i]], b1);
      }
      
      
      // put into box 2
      pair<int,int> b2 = f[i-1][j];
      
      if(b2.second + a[i] > l) {
        b2.first++;
        b2.second=a[i];
        f[i][j] = min(f[i][j], b2);
      }
      else {
        b2.second+=a[i];
        f[i][j]= min(f[i][j], b2);
      }
    }
    // for(int j=0; j<=l;j++) {
    //   cout << f[i][j].first << " ";
    // }
    // cout << endl;
  }
  
  int ans = INF;
  
  for(int i=0; i<=l;i++) {
    ans = min(ans, f[n-1][i].first);
  }
  
  cout << ans << endl;
}



int main() 
{
  cin >> l >> n;
  
  for(int i=0; i<n; i++) cin >> a[i];
  
  if(l < 5001) solve2();
  else solve();
  
  return 0;
}
