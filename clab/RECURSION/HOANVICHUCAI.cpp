#include <bits/stdc++.h>
using namespace std;

int n;
vector<char> ch;
string p = "";
bool v[10];
set<string> uset;

void gen(int k) {
  if(k==n) {
    if(uset.find(p) == uset.end())
    {
      uset.insert(p);
    }
    return;
  }
  
  for(int i=0; i<n; i++) {
    if(!v[i]) {
      v[i] = true;
      p[k] = ch[i];
      gen(k+1);
      v[i] = false;
    }
  }
}

int main() 
{
  string s; cin >> s;
  n = s.size();
  
  for(char c : s) {
    ch.push_back(c);
    p += c;
  }
  
  sort(ch.begin(), ch.end());

  gen(0);
  
  cout << uset.size() << "\n";
  for(auto a:uset) {
    cout << a << "\n";
  }
  
}