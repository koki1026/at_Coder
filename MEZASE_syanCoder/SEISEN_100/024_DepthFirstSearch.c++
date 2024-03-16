#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; //グラフの頂点数
    cin >> n;
    vector<vector<int>> g(n); //グラフ
    rep(i, 0, n){
        int u, k; //頂点の番号と隣接する頂点の数
        cin >> u >> k;
        rep(j, 0, k){
            int v; //隣接する頂点
            cin >> v;
            g[u-1].push_back(v-1);
        }
    }
    vector<int> d(n, -1); //頂点の訪問状態
    vector<int> f(n, -1); //頂点の訪問状態
    int t = 0; //訪問時刻
    function<void(int)> bfs = [&](int u){ //u: 頂点の番号
        if(d[u] != -1){
            return;
        }
        d[u] = ++t;
        for(int v : g[u]){
            bfs(v);
        }
        f[u] = ++t;
    };
    rep(i, 0, n){
        bfs(i);
    }
    rep(i, 0, n){
        cout << i+1 << " " << d[i] << " " << f[i] << endl;
    }
    return 0;
}