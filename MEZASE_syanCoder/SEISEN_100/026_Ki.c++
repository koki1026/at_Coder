#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int n,m; cin >> n >> m; //n:頂点の数 m:クエリの数
    vector<vector<int>> g(n); // 隣接リスト
    vector<int> a(n,0); // 頂点の値
    rep(i, 0, n-1){
      int a, b; cin >> a >> b;
      g[a].push_back(b);
    }
    vector<int> d(n, -1); // 訪れたかどうかのフラグ
    function<void(int, int)> dfs = [&](int x, int c){
        d[x] = 1; //訪れた
        a[x] += c;
        for(int nx : g[x]){
            if(d[nx] == -1){
                dfs(nx, c);
            }
        }
    };
    rep(i, 0, m){
        int x,c; cin >> x >> c; // x:頂点 c:値
        x--;
        dfs(x, c);
    }
    rep(i, 0, n){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}