#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define MOD 1000000007

LL x, n;
LL sum = 0;

LL mypow(LL x, LL n) {
  if(n==0) return 1;

  LL a = mypow(x, n/2) % MOD;
  a *= a;
  a %= MOD;
  
  if(n%2) {
    a *= x;
    a %= MOD;
  }
  
  return a;
}

LL powsum(LL x, LL n) {
  if(n==1) return x;

  LL a = mypow(x, n/2);
  
  LL ans1 = powsum(x,n/2) % MOD;
  LL ans2 = (a*ans1) % MOD;
  
  if(n%2) {
    ans2 += mypow(x, n);
    ans2 %= MOD;
  }

  return (ans1 + ans2) %MOD;
}

LL solve() {
  if(n == 1 || x==1) return x*n;

  LL nom = (x * (mypow(x, n) -1)) % MOD;
  LL denom = mypow(x-1, MOD-2);
  LL ans = (nom * denom) % MOD;

  return ans;
}

int main() 
{
  cin >>x>>n;
  cout << powsum(x, n);
  return 0;
}