#include <bits/stdc++.h>
using namespace std;


int n;
int a[100011];
int idx[1000011] = {};


int solve() {
  if(n==1) return 1;

  memset(idx, -1 ,sizeof(idx));
  int p1=0,p2=0;
  int ans = 1;
  
  for(int p2=0; p2<n; p2++) {
    p1=max(p1, idx[a[p2]] + 1);
    ans=max(ans, p2-p1+1);
    idx[a[p2]]=p2;
  }
  
  return ans;
}

int main() 
{
    cin >>n;
    for(int i=0;i<n;i++) {
      cin >> a[i];
    }
    
    cout<<solve();
    
    return 0;
}