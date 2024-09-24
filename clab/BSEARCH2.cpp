#include <bits/stdc++.h>
using namespace std;

int a[100010];
int x[100010];
int n, m;


int solve(int val) {
  int lo=0, hi=n-1;
  int ans = -2;
  while(lo<=hi) {
    int mid = (lo + hi)/2;
    
    if(a[mid] >= val) {
      ans = mid;
      hi=mid-1;
    }
    else {
      lo=mid+1;
    }
  }

  return ans;
}

int main() 
{
  cin >>n>>m; 
  
  for(int i=0; i<n; i++ ) {
    cin >> a[i];
  }
  
  //sort(&a[0], &a[n]);

  for(int i=0; i<m; i++) {
    int x;
    cin >> x;
    cout<< solve(x)+1 <<"\n";
    
  }
}