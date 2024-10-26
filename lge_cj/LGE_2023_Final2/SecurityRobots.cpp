//https://codejam.lge.com/problem/28312
#include <bits/stdc++.h>
using namespace std;


typedef long long LL ;
int n,m;
LL d[30030];

int check(LL inp_cost) {
  LL total_cost=0, new_cost = 0;
  LL step = 0;
  int num_interval = 1;

  for(int i=1; i<n; i++) {
    step++;
    new_cost += d[i]*step; // add new room, delta = every distance is added d[i]
    total_cost += new_cost; // cost(a, b+1) = cost(a+b) + new_cost
    
    if(total_cost > inp_cost) {
      new_cost = 0;
      total_cost = 0;
      step = 0;
      num_interval++;
    }
  }
  
  return num_interval;
}

LL solve() {
  cin >>n>>m;
  for(int i=1; i<n; i++) {
    cin >> d[i];
  }
  
  LL ans = 0;
  
  LL lo=0, hi=1e18;
  
  while(lo<=hi) {
    LL mid = (lo+hi)/2;
    if(check(mid) <= m) {
      ans=mid;
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
  int t; 
  cin >> t;
  
  while(t--) {
    cout << solve() << "\n";
  }
  
  
  
    return 0;
}