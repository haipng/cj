#include <bits/stdc++.h>
using namespace std;

// SUBSET SUM
// MEET IN THE MIDDLE

typedef long long LL;

int n, m;
int v[44], w[44];
pair<LL,LL> wv1[1<<20];
pair<LL,LL> wv2[1<<20];
LL max_val[1<<20];

void solve_half(int n, int offset, pair<LL,LL> *wv) {
  for(int i=0; i<(1<<n); i++) {
    for(int j=0; j<n; j++) {
        if(i & (1<<j)) {
          wv[i].first += w[j+offset];
          wv[i].second += v[j+offset];
        }
    }
  }
}

LL solve() {
  solve_half(n/2, 0, wv1);
  solve_half(n-n/2, n/2, wv2);

  int size_wv1 = 1 << (n/2);
  int size_wv2 = 1 << (n-n/2);

  sort(wv2, wv2 + size_wv2);

  
  LL max_cur = 0;
  for(int i=0; i < size_wv2; i++) {
    max_cur = max(max_cur, wv2[i].second);
    max_val[i] = max_cur;
  }

  LL ans = 0;
  for(int i=0; i < size_wv1; i++) {
    if(wv1[i].first > m) continue;

    int lo=0, hi=size_wv2-1;
    int idx = 0;
    while(lo<=hi) {
      int mid = (lo + hi)/2;
      
      if(wv1[i].first + wv2[mid].first <= m) {
        idx = mid;
        lo = mid+1;
      }
      else {
        hi=mid-1;
      }
    }

    ans = max(ans, wv1[i].second + max_val[idx]);
  }

  return ans;
}

int main() 
{
  cin >> n >> m;
  
  for(int i=0; i < n; i++) {
    cin >> w[i] >> v[i];
  }
  
  cout << solve() << "\n";

  return 0;
}