#include <bits/stdc++.h>
using namespace std;

int n;
long long a[5011] = {};
long long ps[5011] = {};

void prefix_sum() {
  ps[0] = a[0];

  for(int i=1; i<n; i++) {
    ps[i] = ps[i-1] + a[i];
  }
}

long long calcsum(int p1, int p2) {
  return ps[p2] - ps[p1] + a[p1];
}

int find_k(int p1, int p2) {
  int lo=p1, hi=p2;
  
  while(lo <= hi) {
    int mid = (lo+hi)/2;
    if(calcsum(p1, mid) == calcsum(p1, p2) - calcsum(p1, mid)) {
      return mid;
    }
    else if(calcsum(p1, mid) > calcsum(p1, p2) - calcsum(p1, mid)) hi=mid-1;
    else lo=mid+1;
  }
  return -1;
}


int solve() {
  int ans = 0;
  for(int p1=0;p1<n-1;p1++) {
    for(int p2=p1+1;p2<n;p2++) {
      if(find_k(p1, p2) > -1) ans = max(ans, p2-p1+1);
    }
  }
  return ans;
}

int main() 
{
  cin >> n;
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  
  prefix_sum();
  
  cout << solve();
  
  
  return 0;
}