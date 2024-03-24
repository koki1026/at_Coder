#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; cin >> n;//頂点数
    vector<vector<int>> G(n);
    rep(i,0,n){
        int u, k; cin >> u >> k;
        rep(j,0,k){
            int v; cin >> v;
            G[u-1].push_back(v-1);
        }
    }
    //BFS
    queue<int> que;
    vector<int> dist(n, -1);
    que.push(0);
    dist[0] = 0;
    while(!que.empty()){
      int v = que.front(); que.pop();
      for(int nv : G[v]){
        if(dist[nv] != -1) continue;
        dist[nv] = dist[v] + 1;
      }
    }
    rep(i,0,n){
      cout << i+1 << " " << dist[i] << endl;
    }
    return 0;
}