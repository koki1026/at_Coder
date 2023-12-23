#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; cin >> n;
    vector<vector<int>> a(3e5+1);
    vector<int> a_c(3e5+1,0);
    for(i=0;i<n-1;i++){
      int u,v;
      cin >> u >> v;
      a[u].push_back(v);
      a_c[u]++;
      a[v].push_back(u);
      a_c[v]++;
    }
    vector<bool> a_b(3e5+1,true);

    int ans = 1;
    int now_max = 0;

    set<int> a_kan;
    a_b[1] = false;
    for(int s : a[1]){
      queue<int> q;
      q.push(s);
      a_b[s] = false;
      int cnt = 1;
      while(!q.empty()){
        int tmp = q.front();
        q.pop();
        cnt += a_c[tmp]-1;
        for(int ss: a[tmp]) {
          if(a_b[ss]){
            q.push(ss);
            a_b[ss] = false;
          }
        }
      }
      ans += cnt;
      now_max = max(cnt,now_max);
    }
    ans = ans -  now_max;
    cout << ans << endl;
    return 0;
}