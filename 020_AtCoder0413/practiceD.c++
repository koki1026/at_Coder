#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    ll L,R; cin >> L >> R; // L: スタート数, R: ゴール数
    vector<vector<ll>> ans_kan(0, vector<ll>(2, 0));
    int ans = 0;
    auto f = [&](auto f, ll L, ll R) -> void {
        //L以上R未満の数の長さを求める
        ll len = 0; len = R - L;
        //終了条件
        if(len == 1){
          ans += 1;
          ans_kan.push_back({L, R});
          return;
        }
        else if(len <= 0){
          return;
        }
        //len以下の数の中で、2^lである最大のlを求める
        ll l_en = 0; while((1LL<<l_en) < len) l_en++;
        //lの時の2^lの値を求める
        ll l = (1LL<<l_en);

        //lの倍数のうち、L以上である最小の数を求める
        ll a = 0; a = (L-1) / l;
        a = (a+1) * l;

        //a+lがR未満かどうか判定
        bool flag = false;
        if(a+l < R) flag = true;
        else flag = false;

        if(flag){
          ans += 1;
          ans_kan.push_back({a, a+l});
          f(f, L, a);
          f(f, a+l, R);
        }
        else{
          //lをデクリメントして、lが入る個数を求める
          ll l_en_s = l_en-1;
          ll l_s = 0; l_s = (1LL<<l_en_s);
          ll a_s = 0; a_s = (L-1) / l_s;
          a_s = (a_s+1) * l_s;
          int len_s = 0; len_s = (R-a_s) / l_s;
          ans += len_s;
          ans_kan.push_back({a_s, a_s+(l_s*len_s)});
          f(f, L, a_s);
          f(f, a_s+(l_s*len_s), R);
        }
    };
    f(f, L, R);
    //ans_kanを一つ目の要素でソート
    sort(ans_kan.begin(), ans_kan.end(), [](auto x, auto y){return x[0] < y[0];});
    cout << ans << endl;
    //ans_kanを出力
    for(i=0;i<ans_kan.size();i++){
      cout << ans_kan[i][0] << " " << ans_kan[i][1] << endl;
    }
    return 0;
}