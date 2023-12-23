#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n,m;
    cin >> n >> m;
    vector<vector<int>> to(n); //隣接している数字たちをもつ
    vector<int> a(m),b(m);
    rep(i,m) cin >> a[i], a[i]--;
    rep(i,m) cin >> b[i], b[i]--;
    rep(i,m){
      to[a[i]].push_back(b[i]);
      to[b[i]].push_back(a[i]);
    }

    vector<int> color(n,-1);
    auto bfs = [&](auto bfs, int v, int c=0) -> bool {
      if(color[v]!=-1) return color[v]==c;
      color[v] = c;
      for(int u : to[v]){
        if(!bfs(bfs, u, c^1)) return false;
      }
      return true;
    };

    rep(v,n) if(color[v]==-1){
      if(!bfs(bfs, v, 0)){
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
    return 0;
}