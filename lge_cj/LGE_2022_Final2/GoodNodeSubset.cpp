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

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}

const ll MOD   = ll(1e9)+7;
const ll LLINF = ll(1e18);
const int INF  = int(1e9);


ll v[100010];
int p[100010];
vi child[100010];

ll in[100010];
ll ex[100010];

void dp(int node) {
    if(child[node].empty()) {
        in[node]=v[node];
        ex[node]=0;
        return;
    }
    ll ans=0, maxv=-LLINF;
    in[node] = v[node];
    for(int i : child[node]) {
        dp(i);
        ans += max(in[i], ex[i]);

        ll diff = in[i] - max(in[i], ex[i]);
        
        maxv=max(maxv, diff);
        in[node] += ex[i];
    }
    ex[node]=ans+maxv;
}

void solve() {
    int N = 0;
    cin >> N;
    FOR(i,0,N) {
        cin >> v[i];
        child[i].clear();
    }

    int root = 0;
    FOR(i,0,N) {
        cin >> p[i];
        p[i]--;
        if(p[i]>=0) {
            child[p[i]].pb(i);
        }
        else {
            root = i;
        }
    }

    dp(root);
    cout << max(in[root], ex[root]) << endl;
}
