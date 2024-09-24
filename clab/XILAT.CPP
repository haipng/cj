#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100010];

int solve() {
  int p1=0, p2=n-1;
  int ans=-1;
  
  while(p1<p2) {
    int sum=a[p1]+a[p2];
    
    if(sum == m) return sum;
    else if(sum < m) {
      if(sum > ans) ans=sum;
      p1++;
    }
    else p2--;
  }
  
  return ans;
}

int main() 
{
  cin >>n>>m;
  
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  
  sort(&a[0], &a[n]);
  
  cout << solve();
  
  
  return 0;
}