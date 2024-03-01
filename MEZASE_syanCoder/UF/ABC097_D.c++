#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    //n:頂点数, m:辺の数
    int n, m; cin >> n >> m;
    //配列の初期状態
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    //Union-Find木の初期状態
    vector<int> par(n);
    rep(i, n) par[i] = i;
    //Union-Find木の実装
    function<int(int)> find = [&](int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    };
    auto same = [&](int x, int y){
        return find(x) == find(y);
    };
    auto unite = [&](int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        par[x] = y;
    };
    //辺の情報を受け取り、Union-Find木を構築
    rep(i, m){
        int x, y; cin >> x >> y;
        unite(x-1, y-1);
    }
    //答えを求める
    int ans = 0;
    rep(i, n) if(same(i, p[i]-1)) ans++;
    cout << ans << endl;
    return 0;
}