// https://www.hackerrank.com/contests/dn-swpct-2024-batch-4th/challenges/number-ladder-1-1

#include <bits/stdc++.h>
using namespace std;

int n[2];
int f[2][100010];
long long psum[2][100010] = {};

// prefix sum to get sum with O(1)
long long calc_sum(int sq, int from, int to) {
  if(from >= n[sq]) return 0;

  return psum[sq][to] - psum[sq][from] + f[sq][from];
}

int main() 
{
  for(int i=0; i<2; i++) {
    cin >> n[i];
    
    long long ss=0;
    for(int j=0; j<n[i]; j++) {
      cin >> f[i][j];
      ss += f[i][j];
      psum[i][j] = ss;
    }
  }
  
  long long ans = 0;
  int old_i=0;
  int old_j=0;
  int i=0;
  int j=0;

  while( i<n[0] && j<n[1] ) {
    // find common node
    // take the path that has large sum
    if(f[0][i] == f[1][j]) {
      ans += max(calc_sum(0, old_i, i), calc_sum(1, old_j, j));

      i++;
      j++;
      old_i = i;
      old_j = j;
    }
    else if(f[0][i] < f[1][j]) {
      i++;
    }
    else {
      j++;
    }
  }
  
  ans+= max(calc_sum(0, old_i, n[0]-1), calc_sum(1, old_j, n[1]-1));
  
  cout << ans << endl;

  return 0;
}