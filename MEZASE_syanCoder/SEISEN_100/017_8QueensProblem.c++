#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; //あらかじめ位置が指定されたクイーンの数
    cin >> n;
    pair<int, int> p[n];
    rep(i,n) cin >> p[i].first >> p[i].second;
    //8クイーン問題
    vector<int> a(8); //8つの列にクイーンを置く
    rep(i,8) a[i] = i; //0~7の列
    do{
      //フラグの宣言
      bool flag = true;
      //あらかじめ指定された位置にクイーンがあるかどうか
      rep(i,n){
        if(a[p[i].first] != p[i].second) flag = false;
      }
      if(!flag) continue; //あらかじめ指定された位置にクイーンがない場合は次の列に進む
      //斜めにクイーンがないかどうか
      for(i=0;i<8;i++){
        for(j=i+1;j<8;j++){
          if(abs(i-j) == abs(a[i]-a[j])) flag = false;
        }
      }
      if(!flag) continue; //斜めにクイーンがある場合は次の列に進む
      //出力
      rep(i,8){
        rep(j,8){
          if(a[i] == j) cout << "Q";
          else cout << ".";
        }
        cout << endl;
      }
      cout << endl;
    }while(next_permutation(a.begin(), a.end()));
    return 0;
}