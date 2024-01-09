// https://codejam.lge.com/problem/25571
// Zigzag Subarrays
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define FOR(_i, _a, _b) for (int _i = (_a); _i < (_b); _i++)

typedef long long              ll;
typedef pair<int,int>         pii;
typedef vector<int>            vi;
typedef vector<vector<int>>   vvi;
typedef vector<ll>            vll;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}

//const ll MOD = ll(1e9)+7;
//const ll INF = ll(1e18);
const int INF = int(1e9);

int N = 0;
int a[100010];
int b[100010];

void solve() {
    cin >> N;
    FOR(i, 0, N) {
        cin >> a[i];
    }

    ll ans = 0;
    int lo = 0, hi = 0;
    while(hi < N) {
        if(lo == hi) {
            hi++;
            continue;
        }

        if(a[hi-1] < a[hi]) {
            if(hi-lo==1 || a[hi-2] > a[hi-1]) {
                hi++;
            }
            else {
                ans += 1LL*(hi-lo)*(hi-lo-1)/2;
                lo = hi-1;
            }
        }
        else if(a[hi-1] > a[hi]) {
            if(hi-lo==1 || a[hi-2] < a[hi-1]) {
                hi++;
            }
            else {
                ans += 1LL*(hi-lo)*(hi-lo-1)/2;
                lo = hi-1;
            }
        }
        else {
            ans += 1LL*(hi-lo)*(hi-lo-1)/2;
            lo = hi;
        }
    }
    ans += 1LL*(hi-lo)*(hi-lo-1)/2;
    cout << ans << "\n";
}

