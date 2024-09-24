#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[100010];

int solve() {
  int ans=-1;
  
  for(int i=0; i<n; i++) {
    int p1=0, p2=n-1;
    
    int m_tmp = m-a[i];
    
    while(p1<p2) {
      if(p1 == i) {
        p1++;
        continue;
      }
      
      if(p2 == i) {
        p2--;
        continue;
      }
      
      int sum=a[p1]+a[p2];
      
      if(sum == m_tmp) return sum+a[i];
      else if(sum < m_tmp) {
        ans = max(ans, sum+a[i]);
        p1++;
      }
      else p2--;
    }
  }
  
  return ans;
}


int main() 
{
  cin >> n>>m;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  
  sort(&a[0], &a[n]);
  
  cout << solve();


    return 0;
}