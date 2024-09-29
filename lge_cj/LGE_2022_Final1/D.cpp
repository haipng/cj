#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[100100];
int max_len[100100];
int v[300100];
  
#define MOD 1000000007LL
typedef long long LL;

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
  if(n == 1 || x==1) return x*n;

  LL nom = (x * (mypow(x, n) -1)) % MOD;
  LL denom = mypow(x-1, MOD-2);
  LL ans = (nom * denom) % MOD;

  return ans;


  // if(n==1) return x;

  // LL a = mypow(x, n/2);
  
  // LL ans1 = powsum(x,n/2) % MOD;
  // LL ans2 = (a*ans1) % MOD;
  
  // if(n%2) {
  //   ans2 += mypow(x, n);
  //   ans2 %= MOD;
  // }

  // return (ans1 + ans2) %MOD;
}


void find_left(int * max_len) {
  int p1 = 1;
  int p2 = 1;
  
  for(int i=0; i<300100; i++) {
    v[i] = 0;
  }
  
  while(p2 <= n) {
    while(v[a[p2]] >= p1) {
      max_len[p1] = p2 - p1;
      p1++;
    }
    
    v[a[p2]] = p2;
    p2++;
  }
  
  while(p1 <= p2) {
    max_len[p1] = p2-p1;
    p1++;
  }
}

void find_right(int * max_len) {
  int p1=n;
  int p2=n;
  
  for(int i=0; i<300100; i++) {
    v[i] = n+1;
  }
  
  while(p2 >= 1) {
  
    while(p1 >= v[a[p2]]) {
      max_len[p1] = p1-p2;
      p1--;
    }
    
    v[a[p2]] = p2;
    p2--;
  }
  
  while(p1 >= p2) {
    max_len[p1] = p1-p2;
    p1--;
  }
}


long long solve() {
  long long ans=0;

  find_right(max_len);
  
  for(LL i=1; i<=n; i++) {
    ans += powsum(i, max_len[i]) -i; 
    ans %= MOD;
  }
  
  find_left(max_len);

  for(LL i=1; i<=n; i++) {
    ans += powsum(i, max_len[i]) -i;
    ans %= MOD;
  }
    
  return ans;
}

int main() 
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> t;
  
  while(t--) {
    cin >> n;   
    for(int i=1; i <= n; i++) {
      cin >> a[i];
    }
    
    cout << solve() << "\n";
  }


  return 0;
}