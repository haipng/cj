#include <bits/stdc++.h>
using namespace std;

int n,m;
int x[100010];
int d[100010];


bool check(int min_d) {
  
  int curr = 0;
  for(int cow=1; cow<m;cow++) {
    int i = curr+1;
    while(i<n) {
      if(x[i] - x[curr] >= min_d) {
        curr = i;
        break;
      }
      i++;
    }
    if(i >=n ) return false; 
  }
  
  return true;
}


int solve() {
  int ans = -99;
  
  int lo=1, hi=10e9;
  while(lo<=hi) {
    int mid = (lo+hi)/2;
    if(check(mid)) {
      ans = mid;
      lo=mid+1;
    }
    else {
      hi = mid-1;
    }
  }
  
  return ans; 
}


int main() 
{
  cin >>n>>m;
  
  for(int i=0; i<n; i++) {
    cin >> x[i];
  }
  
  for(int i=1; i<n;i++) {
    d[i] = x[i] - x[i-1];
  }
  
  cout << solve();
  
  
  
    return 0;
}