//https://codejam.lge.com/problem/23021
#include <bits/stdc++.h>
using namespace std;

// SUBSET SUM
// MEET IN THE MIDDLE

typedef long long LL;
int n, m, x, c, d;
int a[20], b[20];

// count - len
pair<int,LL> cla[1<<18];
pair<int,LL> clb[1<<18];


const int MOD = 1000000007;

LL factorial(int n) {
  LL ans = 1;
  for(int i=2; i<=n; i++) {
    ans *= i;
    ans %= MOD;
  }
  return ans;
}


void generate_set(int *inarr, int n, pair<int, LL> * cl) {
  for(int i=0; i<(1<<n); i++) {
    cl[i].first = 0;
    cl[i].second = 0;
    for(int j=0; j<n; j++) {
      if(i & (1<<j)) {
        cl[i].first++;
        cl[i].second += inarr[j];
        cl[i].second %=MOD;
      }
    }
  }
}

int solve() {
  generate_set(a, n, cla);
  generate_set(b, m, clb);
  
  int size_cla = 1 << n;
  int size_clb = 1 << m;
  
  sort(clb, clb + size_clb, [](const pair<int,LL> &a, const pair<int,LL> &b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
  });
  
  // for(int i=0; i<size_cla ; i++) {
  //   cout << cla[i].first << " " << cla[i].second << endl;
  // }
  
  // for(int i=0; i<size_clb ; i++) {
  //   cout << clb[i].first << " " << clb[i].second << endl;
  // }

  LL ans = 0;
  // O(2^*n/2)
  for(int i=0; i < size_cla; i++) {
    //cout << "check " << cla[i].first << endl;
    if(cla[i].second > d) {
      //cout << "second " << cla[i].second << endl;
      continue;
    }
    //if(cla[i].second < c) continue;
    
    for(int offset=-1; offset<=1; offset++) {
      //cout << "offset " << offset << endl; 
      int r_first=-1, l_first=-1;
      {
        int lo=0, hi=size_clb-1;
        while(lo<=hi) {
          int mid = (lo + hi)/2;
          
          if(clb[mid].first == cla[i].first + offset) {
            r_first = mid;
            lo = mid+1;
          }
          else if(clb[mid].first < cla[i].first + offset) {
            lo = mid+1;
          }
          else {
            hi=mid-1;
          }
          //cout << "first" << mid  << " " << lo <<  " " << hi << endl;
        }
      }
        
      {
        int lo=0, hi=size_clb-1;
        while(lo<=hi) {
          int mid = (lo + hi)/2;
          
          if(clb[mid].first == cla[i].first + offset) {
            l_first = mid;
            hi = mid-1;
          }
          else if(clb[mid].first > cla[i].first + offset) {
            hi = mid-1;
          }
          else {
            lo=mid+1;
          }
        }
      }
      
      
      if(r_first == -1 || l_first == -1) continue;
      if(r_first < l_first) continue;
      //cout << "r_first " << r_first << " " << l_first << endl; 
      int r_second=-1, l_second=-1;
      {
        int lo=l_first, hi=r_first;
        while(lo<=hi) {
          int mid = (lo + hi)/2;
          
          int n_bridge = cla[i].first + clb[mid].first -1;
          LL sumlen = cla[i].second+clb[mid].second + x*n_bridge;
          
          if(sumlen <= d) {
            r_second = mid;
            lo = mid+1;
          }
          else {
            hi=mid-1;
          }
        }
      }
      
      {
        int lo=l_first, hi=r_first;
        while(lo<=hi) {
          int mid = (lo + hi)/2;
          
          int n_bridge = cla[i].first + clb[mid].first -1;
          LL sumlen = cla[i].second+clb[mid].second + x*n_bridge;
          //cout << sumlen<<endl;
          if(sumlen >= c) {
            l_second = mid;
            hi = mid-1;
          }
          else {
            lo=mid+1;
          }
        }
      }
      
      
      //cout << "r_second " << r_second << " " << l_second << endl; 
      if(r_second == -1 || l_second == -1) continue;
      if(r_second < l_second) continue;
      
      
      //cout << "found " << cla[i].first << " " << clb[l_second].first << endl;
      // calc num of way
      LL nway = factorial(cla[i].first) * factorial(clb[l_second].first);
      nway %= MOD;
      
      
      nway *= (r_second - l_second + 1);
      nway %= MOD;
      if(cla[i].first == clb[l_second].first) {
        nway*=2;
        nway %=MOD;
      }
      //cout << "nway " << nway << endl;
      ans += nway;
      ans %= MOD;
    }
  }

  return ans;
}



int main() 
{
  int t; cin >> t;
  
  while(t--) {
  
    cin >> n >> m >> x >> c >> d;
    
    for(int i=0; i < n; i++) {
      cin >> a[i];
    }
    for(int i=0; i < m; i++) {
      cin >> b[i];
    }
    
    cout << solve() << "\n";
  
  }

  return 0;
}