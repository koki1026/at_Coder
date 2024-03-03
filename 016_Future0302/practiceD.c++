#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; //試合に参加する人数
    int T; //得点が動く回数
    cin >> n >> T;
    vector<ll> a(n); //得点
    rep(i,n){
      a[i] = 0; //初期化
    }
    //得点の変動ごとに何種類の得点が出るかを求めるため、mapとsetを使う
    map<ll,int> m;
    set<ll> s;
    rep(i,n){
      m[0]++; //0点の人数を増やす
      s.insert(0); //0点を追加
    }
    m[0] = n; //0点の人数はn人
    vector<ll> b(T); //得点の変動
    rep(i,T){
      int x; //x番目の人
      int y; //y点取った
      cin >> x >> y;
      x--; //0-indexedにする
      m[a[x]]--; //a[x]点の人数を減らす
      if(m[a[x]]==0){
        s.erase(a[x]); //a[x]点を削除
      }
      a[x] += y; //得点を更新
      m[a[x]]++; //a[x]点の人数を増やす
      s.insert(a[x]); //a[x]点を追加
      int ans = 0;
      //得点の種類を求める
      ans = s.size();
      b[i] = ans; //得点の種類を記録
      //debug
      // cout << "a" << endl;
      // rep(j,n){
      //   cout << a[j] << " ";
      // }
      // cout << endl;
    }
    rep(i,T){
      cout << b[i] << endl;
    }
    return 0;
}