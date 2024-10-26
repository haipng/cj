//https://c-lab.vn/problems/LIQ2
#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];

void solve() {
  vector<int> sq;

  for(int i=0; i<n; i++) {
    auto it = lower_bound(sq.begin(), sq.end(), a[i]);
    
    if(it == sq.end()) {
      sq.push_back(a[i]);
    }
    else {
     *it = a[i]; 
    }
  }
  
  cout << sq.size() << endl;
}


int main() 
{
  cin >> n;
  
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  
  solve();

  return 0;
}