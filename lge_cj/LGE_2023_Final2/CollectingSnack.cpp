// https://codejam.lge.com/problem/28309
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Node {
public:
  Node() : x(0), y(0) {};
  //Node(int x_, int y_) : x(x_), y(y_) {};
  ll x;
  ll y;
  
  bool operator < (const Node& other) {
    if(x != other.x) return x < other.x;
    else return y < other.y;
  }
};

class DP {
public:
  DP() : max_snack(0), n_way(0) {};
  ll max_snack;
  ll n_way;
};

const ll MOD = 1000003;
ll r,c,N;
Node s[111];
DP dp[111];

ll mypow(ll x, ll n) {
  if(n==0) return 1;

  ll a = mypow(x, n/2) % MOD;
  a *= a;
  a %= MOD;
  
  if(n%2) {
    a *= x;
    a %= MOD;
  }
  
  return a;
}

ll f[2000200] = {};

ll fact(ll n) {
  return f[n];
}

ll nCr(ll n, ll r)
{
  ll nom = fact(n) ;
  ll denom = (fact(r) * fact(n-r)) % MOD;
  ll denom_inv = mypow(denom, MOD-2);
  return (nom * denom_inv) %MOD;
}

ll calc_way(ll a, ll b) {
  return nCr(s[b].x + s[b].y - s[a].x - s[a].y, s[b].x - s[a].x); 
}


void solve() {
  sort(s, s+N+1);
  
  memset(dp, 0, sizeof(dp));

  dp[0].max_snack = 0;
  dp[0].n_way = 1;
  
  for(ll i=1; i<=N+1; i++) {
    for(ll j=0; j < i; j++) {
      if(s[j].x > s[j].x || s[j].y > s[i].y) {
        continue;
      }

      if(dp[i].max_snack == dp[j].max_snack + 1) {
        dp[i].n_way += (dp[j].n_way * calc_way(j, i)) % MOD;
        dp[i].n_way %= MOD;
      } 
      else if(dp[i].max_snack < dp[j].max_snack +1) {
        dp[i].max_snack = dp[j].max_snack+1;
        dp[i].n_way = (dp[j].n_way * calc_way(j,i)) %MOD ;
        dp[i].n_way %= MOD;
      }
    }
  }

  cout << dp[N+1].n_way << endl;
}


int main() 
{
  
  int t; cin >> t;
  
  f[0] = 1;
  for(ll i=1; i<2000200; i++) {
    f[i] = (f[i-1] * i)%MOD;
  }
  
  while (t--) {
    memset(s, 0, sizeof(s));
    
    cin >> r >> c >> N;
    
    s[0].x = 1;
    s[0].y = 1;
    
    for(ll i=1; i<=N; i++) {
      cin >> s[i].x >> s[i].y;
    }
    
    s[N+1].x = r;
    s[N+1].y = c;
    
    solve();
  }
  return 0;
}