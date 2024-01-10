#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define FOR(_i, _a, _b) for (int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)

typedef long long              ll;
typedef pair<int,int>         pii;
typedef vector<int>            vi;
typedef vector<vector<int>>   vvi;
typedef vector<ll>            vll;

const ll MOD   = ll(1e9)+7;
const ll LLINF = ll(1e18);
const int INF  = int(1e9);

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t=1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}

/***** START *****/  
int n,m,k;
const int nmax = 10010;
vi x[nmax];
vi y[nmax];
int xsize[nmax];
int ysize[nmax];
int v[nmax];
int w[nmax];

bool comp(vi in1, vi in2) {
    return (in1.size() > in2.size());
}

void solve() {
    cin >> n >> m >> k;

    FOR(i, 0, nmax) {
        x[i].clear();
        y[i].clear();
    }

    FOR(i, 0, k) {
        int a, b;
        cin>>a>>b;
        a--;b--;
        x[a].pb(b);
        y[b].pb(a);
    }

    FOR(i, 0, n) {
        xsize[i] = x[i].size();
    }
    FOR(i, 0, m) {
        ysize[i] = y[i].size();
    }

    sort(&xsize[0], &xsize[n]);
    sort(&ysize[0], &ysize[m]);

    ll sum = 0;

    FOR(i, 0, n) {
        if(i==0 || xsize[i-1] < xsize[i]) {
            v[xsize[i]] = i+1;
        }
        
        sum+=(i+1)*xsize[i];
    }
    FOR(i, 0, m) {
        if(i==0 || ysize[i-1] < ysize[i]) {
            w[ysize[i]] = i+1;
        }
        
        sum+=(i+1)*ysize[i];
    }

    ll sum2 = 0;
    // remove and find v,w wrt the size
    FOR(i, 0, n) {
        for(int j : x[i]) {
            sum2 = max(sum2, sum - v[x[i].size()] - w[y[j].size()]);
        }
    }

    cout <<sum<<" " <<sum2<<endl;

}

