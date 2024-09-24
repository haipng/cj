#include <bits/stdc++.h>
using namespace std;


typedef long long LL;
#define MOD 1000000007
LL n;

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

int main() 
{
  
  cin >> n;
  cout << mypow(2, n);
  return 0;
}