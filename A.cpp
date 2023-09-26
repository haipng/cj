#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;


int n, pa,pb, x[1000010];

void solve() {
    cin >> n >> pa >> pb;
    if(pa > pb) {
        swap(pa, pb);
    }
    for(int i=0; i<n; i++) {
        cin >> x[i];
    }

    sort(x, x+n);

    vll pre(n+1), sub(n+2);

    for(int i=1; i<=n; i++) pre[i] = pre[i-1] + 2*(x[i-1] - pa);
    for(int i=n;i>=1; i--) sub[i] = sub[i+1] + 2*(pb - x[i-1]);

    ll tot = 1e16;
    ll dif = 1e16;
    for(int i=0; i<=n; i++) {
        if(pre[i] + sub[i+1] < tot) {
            tot = pre[i] + sub[i+1];
            dif = abs(pre[i] - sub[i+1]);
        }
        else if(tot == pre[i] + sub[i+1]) {
            dif = min(dif, abs(pre[i] - sub[i+1]));
        }
    }

    cout << tot << " " << dif << "\n";
}

int main(void) { 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t; 
    while(t--)
        solve();
    return 0;
}