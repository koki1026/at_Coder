#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int h, w; cin >> h >> w;
    vector<vector<int>> c(10, vector<int>(10));
    rep(i, 10) rep(j, 10) cin >> c[i][j];
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    rep(k, 10) rep(i, 10) rep(j, 10) c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
    int ans = 0;
    rep(i, h) rep(j, w) if(a[i][j] != -1) ans += c[a[i][j]][1];
    cout << ans << endl;
    return 0;
}