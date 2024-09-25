#include <bits/stdc++.h>
using namespace std;

int n;
int p[10];
bool v[10] = {0};
void gen(int k) {
  if(k>n) {
    for(int i=1; i<=n; i++) {
      cout << p[i] << " ";
    }
    cout << "\n";
    return;
  }
  

  for(int i=1; i<=n; i++) {
    if(!v[i]) {
      v[i] = true;
      p[k] = i;
      gen(k+1);
      v[i] = false;
    }
  }
}


int main() 
{
  cin >>n;
  gen(1);
  return 0;
}