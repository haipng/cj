const int MAX_N = 15;


int end_mask;
int dp[MAX_N][1 << (MAX_N+1)];
int dist[MAX_N][MAX_N];

int tsp(int i, int mask) {
    if(mask == end_mask) {
        return 0;
    }
    int&ret = dp[i][mask];

    if(ret != -1) return ret;

    ret = MAX;
    for(int j=1; j<n+1; j++) {
        if(mask & (1<<j)) continue;
        int v = tsp(j, mask | (1<<j)) + dist[i][j];
        ret = min(v, ret);
    }
    //cout << ret << endl;
    return ret;

}

void solve() {
    // ...


    // start tsp
    memset(dp, 0, sizeof(dp));

    end_mask = (1 << (n + 1)) - 1;
    cout << tsp(0, 1) << "\n";
}

