#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n; 
ll k;
int a[100010];

ll produce(ll d) {
  ll sum=0;
  for(int i=0;i<n;i++) {
    sum+=d/a[i];
  }
  
  return sum;
  
}

ll solve() {
  ll lo=0, hi=1e10;
  ll ans=-99;
  
  while(lo<=hi) {
    ll mid= (lo+hi)/2;
    ll p=produce(mid);
    if(k <= p) {
      ans = mid;
      hi=mid-1;
    }
    else lo=mid+1;
  }
  
  return ans;
}


int main() 
{
  cin >>n>>k;
  
  for(int i=0;i<n;i++) {
    cin >>a[i]; 
  }
  
  cout << solve();
  
  
  return 0;
}