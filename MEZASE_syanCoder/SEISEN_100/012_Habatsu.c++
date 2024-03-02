#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; cin >> n; //人数
    int m; cin >> m; //人間関係の数
    vector<vector<int>> a(n); //人間関係
    rep(i,n){
      a[i].push_back(i);
    }
    rep(i,m){
        int x, y; cin >> x >> y;
        --x; --y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    //派閥が生成し得るかどうかを全探索
    int ans = 0;
    for(i=0; i<(1<<n); i++){
        bool flag = true;
        int bit_count = __builtin_popcount(i);
        if(bit_count <= ans){
            continue;
        }
        for(j=0; j<n; j++){
          //jがiに含まれているか
            if(i&(1<<j)){
              //iの他の全要素に対して、jと繋がっているか
              //iのすべてのメンバーがa[j]に含まれている必要がある
              for(int k=0;k<n;k++){
                if(i&(1<<k)){
                  if(find(a[j].begin(), a[j].end(), k) == a[j].end()){
                    flag = false;
                    break;
                  }
                }
              }
            }
        }
        if(flag){
            ans = bit_count;
        }
    }
    cout << ans << endl;
    return 0;
}