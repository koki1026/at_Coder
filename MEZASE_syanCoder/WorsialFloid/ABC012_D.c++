#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n, m; cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(n, 1e9));
    rep(i, n) d[i][i] = 0;
    rep(i, m){
        int a, b, t; cin >> a >> b >> t;
        a--; b--;
        d[a][b] = d[b][a] = t;
    }
    rep(k, n) rep(i, n) rep(j, n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int ans = 1e9;
    rep(i, n){
        int t = 0;
        rep(j, n) t = max(t, d[i][j]);
        ans = min(ans, t);
    }
    return 0;
}