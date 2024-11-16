#include <bits/stdc++.h>
using namespace std;


string s;
int n;
int f[501][501];

void find_diff() {
  memset(f, -1, sizeof(f));
  
  for(int i=0; i<n; i++) {
    for(int j=i; j<n; j++) {
      int k=0;
      while(s[i+k] == s[j+k]) {
        if(i+k == n || j+k == n) break;
        k++;
      }

      f[i][j] = i+k;
      f[j][i] = j+k;
    }
  }
  
  // for(int i=0; i<n; i++) {
  //   for(int j=0; j<n; j++) {
  //     cout << f[i][j] << "\t";
  //   }
  //   cout << endl;
  // }
}

void solve() {
  find_diff();
  
  int ans = 0;
  for(int start=0; start < n; start++) {
    for(int end=start; end < n; end++) {
      if(end - start + 1 < 5) {
        continue;
      } 
      
      bool isMin = true;
      for(int i=start+1; i<=end; i++) {
        if(f[i][start] <= end) {
          if(s[f[i][start]] < s[f[start][i]]) {
            isMin=false;
            //cout << "false1" << endl;
            break;
          }
        }
        else {
          // rollover case f[i][start] outside end
          // abcdef---------abcdef------x
          // st-------------i----en-----f[i][start]
          // 
          // must rollover
          // s[i,end] are same as s[st,st+end-i+1]
          // start to compare from s[start] - s[start + end - i + 1]
          
          int tmp1 = f[start][start + end - i + 1];
          int tmp2 = f[start + end - i + 1][start];
          if(tmp1 < i) {
            if(s[tmp1] < s[tmp2]) {
              isMin = false;
              //cout << "false2" << endl;
              break;
            }
          }
        }
      }
      if(isMin) {
        //cout << "true" << endl;
        ans++;
      }
    }
  }
  
  cout << ans << endl;
  
}



int main() 
{
    cin >> s;
    n = s.size();
    
    solve();
    
    return 0;
}
