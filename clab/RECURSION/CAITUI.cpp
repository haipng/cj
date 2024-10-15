#include <bits/stdc++.h>
using namespace std;

int n, m;
int w[21], v[21];

int solve(int m, int sum_v, int idx) {
  if(m < 0) return -1;
  if(idx == n) return sum_v; 

  return max(solve(m, sum_v, idx+1), 
      solve(m-w[idx], sum_v+v[idx], idx+1));
}

int main() 
{
  cin >> n >> m;
  
  for(int i=0; i < n; i++) {
    cin >> w[i] >> v[i];
  }
  
  cout << solve(m, 0, 0) << "\n";

  return 0;
}