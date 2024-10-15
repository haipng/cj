#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100010];

bool check(int len) {
  int cnt=0;
  for(int i=0; i<n; i++) {
    cnt+=a[i]/len;
  }
  
  if(cnt >= k) return true;
  return false;
}


int solve() {
  int lo=0, hi=1e9;
  int ans=-999;
  while(lo <= hi) {
    int mid = (lo+hi)/2;
    
    if(check(mid)) {
      ans = mid;
      lo=mid+1;
    }
    else hi=mid-1;
  }
  
  return ans;
}



int main() 
{
  cin >>n>>k;
  
  for(int i=0; i<n;i++) {
    cin>>a[i];
  }
  
  cout << solve();
  
  
    return 0;
}