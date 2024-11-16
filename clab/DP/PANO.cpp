//https://c-lab.vn/problems/PANO
#include <bits/stdc++.h>
using namespace std;

int n, k; 


class A {
  public:
  int l;
  int p;
  int s;
  bool operator < (A& that) {
    return s < that.s;
  }
};

A a[111];

int dp[16000][100];




void solve() {
  sort(a, a+k);
  
  memset(dp, -1, sizeof(dp));

  
  for(int i=0; i<k; i++) {
    for(int len=-a[l]+1; len < a[i].l+1; i++) {
      int pos = a[i].s + len;
        
      if(len*a[i].p > dp[p][i-1] * a[i-1].p) {
        dp[p][i] = len;
      }
      else {
        dp[p][i] = 9;
      }
    }
  }
  
  for(int i=0; i<k;i++) {
    for(int j=0; j<n; j++) {
      cout << dp[i][j] << "\t";
    }
    cout << endl;
  }
}



int main() 
{
  cin >> n >> k;
  
  for(int i=0;i<k; i++) {
    cin >> a[i].l >> a[i].p >> a[i].s;
  }
  
  solve();

  return 0;
}
