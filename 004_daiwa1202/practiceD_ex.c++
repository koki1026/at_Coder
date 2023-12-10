#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    //累積二乗和を用いて左上から自分までの和を算出。問題に応じて左上からのどこまでを消去するかを考えて必要な箇所の数値を求める
    int n,q; cin >> n >> q;
    vector<string> c(n);
    for(i=0;i<n;i++){
      cin >> c[i];
    }
    //累積二乗和の計算
    vector p(n+1,vector<int>(n+1,0));
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        if(c[i][j]=='B') p[i+1][j+1]=1;
      }
    }
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        p[i+1][j+1] += p[i+1][j];
      }
    }
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        p[i+1][j+1] += p[i][j+1];
      }
    }

    auto f = [&](int a, int b){
      ll res = p[a%n][b%n];
      res += p[n][n] * ll(a/n) * (b/n);
      res += p[n][b%n] * ll(a/n);
      res += p[a%n][n] * ll(b/n);
      return res;
    };

    //クエリの処理
    for(i=0;i<q;i++){
      int aa=0;
      int bb=0;
      int cc=0;
      int dd=0;
      cin >> aa >> bb >> cc >> dd;
      //左上から自分までのBの個数の計算
      cc++; dd++;
      ll ans = 0;
      ans = f(cc,dd) - f(aa,dd) - f(cc,bb) + f(aa,bb);
      cout << ans << endl;
    }
    return 0;
}