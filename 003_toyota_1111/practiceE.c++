#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;

struct Edge{
    int a, b;ll w;
    Edge(){}
    Edge(int a, int b, ll w): a(a), b(b), w(w){}
};

int main(){
    int i=0, j=0;
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<Edge> es;
    for (i=0;i<m;i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u; --v;
        es.emplace_back(u,v,w);
    }
    const ll INF = 1e18;
    ll ans = INF;
    auto dfs = [&](auto dfs, int i, vector<int> is) -> void {
        if(is.size() == n-1) {
            //辺をつないでいって木を作成する＆その木がループを持つかどうかを判定する
            dsu uf(n);
            bool ok = true;
            ll now = 0;
            for (int ei : is){
                auto e = es[ei];
                if(uf.same(e.a, e.b)) ok = false;
                uf.merge(e.a, e.b);
                now = (now+ e.w)%k;
            }
            if (ok) ans = min(ans, now);
            return;
        }
        if (i==m) return;
        dfs(dfs, i+1, is); //iを非採用
        is.push_back(i);
        dfs(dfs, i+1, is); //ｉを採用
    };

    dfs(dfs,0,{});

    cout << ans << endl;
    return 0;
}