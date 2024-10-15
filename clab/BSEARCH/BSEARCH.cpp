#include <bits/stdc++.h>
using namespace std;

int a[100010];
int n, m;


int solve(int val) {
  int lo=0, hi=n-1;
  while(lo<=hi) {
    int mid = (lo + hi)/2;
    
    if(a[mid] == val) return mid;
    else if(a[mid] > val) hi=mid-1;
    else lo=mid+1;
  }

  return -1;
}

int main() 
{
  cin >>n>>m; 
  
  for(int i=0; i<n; i++ ) {
    cin >> a[i];
  }
  

  for(int i=0; i<m; i++) {
    int x;
    cin >> x;
    cout<< solve(x)+1 <<"\n";
    
  }
}