#include <bits/stdc++.h>
using namespace std;

int n;

void solve(int n, char from_col, char to_col, char empty_col) {
  if(n == 0) return;
  
  solve(n-1, from_col, empty_col, to_col); 
  cout << n << " " << from_col << " " << to_col << "\n";
  solve(n-1, empty_col, to_col, from_col);
}

int main() 
{
  cin >> n;
  solve(n, 'a', 'c', 'b');
  return 0;
}