https://www.hackerrank.com/contests/dn-swpct-2024-batch-4th/challenges/manig-en
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
    string s;
    int k;
    cin >> s >> k;
    int len = s.size();
    
    int key = k;
    for(int t = 0; t < len/k; ++t) {
      int start = t * k;
      
      
      for(int i = start; i < start+k; ++i){
          char c = s[i] - 'a';
          c += (26 + key);
          c %= 26;
          s[i] = 'a' + c;
      }
      
      key = -key;
    }

    cout << s;
    return 0;
}