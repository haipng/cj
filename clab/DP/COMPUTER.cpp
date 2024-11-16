#include <bits/stdc++.h>
using namespace std;

int a,b,x,y,n;

pair<int,int> f[1001][1001];


bool solve(int v) {
  memset(f, 0, sizeof(f));
  
  for(int i=0; i<=x; i++) {
    for(int j=0; j<=y; j++) {
      
      if(i < x) {
        pair<int,int> tmpx = f[i][j];
        tmpx.second += a;
        if(tmpx.second >= v) {
          tmpx.first++;
          tmpx.second = 0;
        }
        
        f[i+1][j] = max(f[i+1][j], tmpx);
      }
      
      if(j<y) {
        pair<int,int> tmpy = f[i][j];
        tmpy.second += b;
        if(tmpy.second >= v) {
          tmpy.first++;
          tmpy.second = 0;
        }
        
        f[i][j+1] = max(f[i][j+1], tmpy);
      }
      if(f[i][j].first == n) return true;
      
    }
  }
  return false;
}

void bs() {
  int lo = 0; 
  int hi = a*x+b*y;
  
  int ans = 0;
  while(lo<=hi ) {
    int mid = (hi+lo)/2;
    
    //cout << "mid:" << mid << endl;
    if(solve(mid)) {
      ans = mid;
      lo = mid+1;
    }
    else {
      hi = mid-1;
    }
  }
  
  cout << ans << endl;
}

int main() 
{
  int t = 2;
  while(t--) {
    cin >>x>>a>>y>>b>>n;
  
    bs();
  }

  return 0;
}
