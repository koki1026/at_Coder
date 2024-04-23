#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    ll n,m; cin >> n >> m; //n: 頂点の数, m: 辺の数
    vector<vector<ll>> G(n); //グラフ
    rep(i,0,m){
        ll a,b; cin >> a >> b;
        a--; b--; //0-indexedにする
        G[a].push_back(b);
        G[b].push_back(a);
    }
    //グループを木構造で管理
    vector<ll> group(n,-1);
    map<ll,ll> group_size;
    queue<ll> q;
    rep(i,0,n){
      if(group[i] != -1) continue;
      group[i] = i;
      q.push(i);
      group_size[i] = 1;
      while(!q.empty()){
          int v = q.front(); q.pop();
          for(int nv: G[v]){
              if(group[nv] != -1) continue;
              group[nv] = group[v]; //同じグループに所属
              q.push(nv); //次の頂点を追加
              group_size[group[v]]++;
          }
      }
    }
    ll ans = 0;
    for(auto p: group_size){
        ll size = p.second;
        ans += size*(size-1)/2;
    }
    ans -= m;
    cout << ans << endl;

    return 0;
}