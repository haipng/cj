#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;
int digit[10]={};

void gen(int k) {
  if(k>n) {
    int tmp=0;
    for(int i=1; i<=n; i++) {
        tmp *= 10;
        tmp += digit[i]; 
    }
    ans.push_back(tmp);
    return;
  }
  
  for(int i=digit[k-1]+1; i<=9; i++) {
    digit[k] = i;
    gen(k+1);
  }
}

int main() 
{
  cin >> n;

  gen(1);

  cout << ans.size() << "\n";
  for(auto a:ans) {
    cout << a << "\n";
  }
  
}