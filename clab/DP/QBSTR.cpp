//https://c-lab.vn/problems/QBSTR
#include <bits/stdc++.h>
using namespace std;

string a, b;

int lcs[1001][1001] = {};


void solve() {
  for(int i=1; i<=a.size(); i++) {
    for(int j=1; j<=b.size(); j++) {
      if(a[i-1] != b[j-1]) {
        lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);  
      }
      else {
        lcs[i][j] = lcs[i-1][j-1] + 1;
      }
      //cout << lcs[i][j] << "\t";
    }
    //cout << endl;
  }
  
  cout << lcs[a.size()][b.size()] << endl;
}

int main()
{
  cin >> a >> b;
  solve();
  
  return 0;
}