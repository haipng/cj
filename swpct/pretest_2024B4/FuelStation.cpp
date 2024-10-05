
// https://www.hackerrank.com/contests/dn-swpct-2024-batch-4th/challenges/fuel-station-1
#include <bits/stdc++.h>
using namespace std;

bool reachable(int fuel, int from, int to) {
  return (fuel - (from - to)) >= 0;
}

int main() 
{
  int n =0; cin >> n;
  vector<pair<int,int>> df(n+1);
  int d,f;  
  
  for(int i=0; i<n; i++) {
    int di = 0;
    int fi = 0;
    cin >> di >> fi;
    df[i] = {di, fi};
  }
  
  // set destination as a station with  d=0, f=0
  df[n] = {0,0};
  
  cin >> d >> f;
  
  sort(df.begin(), df.end(), greater<pair<int, int>>());
  

  auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
    return (a.second) < (b.second);
  };
  priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
  
  int fuel = f;
  int dist = d;
  int cnt = 0;
  int i=0;

  for(int i=0; i<=n;i++) {
    while(!reachable(fuel, dist, df[i].first)) {
      if(pq.empty()) break;
    
      pair<int, int> station = pq.top();
      pq.pop();

      fuel += station.second;

      if(dist >= station.first) {
        fuel -= dist - station.first;
        dist = station.first;
      }
    
      cnt++; 
    }
    
    if(reachable(fuel, dist, df[i].first)) pq.push(df[i]);
    else break;
  }
  
  if(reachable(fuel, dist, 0)) cout << cnt << endl;
  else cout << -1 << endl;
  
  return 0;
}