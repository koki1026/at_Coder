#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    //箱の数
    int n;
    //クエリの数
    int q;
    cin >> n >> q;
    //箱をsetで定義
    vector<set<int>> boxes(n,set<int>());
    rep(i,n){
      //箱に最初のボールを入れる
      int c; cin >> c;
      boxes[i].insert(c);
    }
    //クエリの処理
    rep(i,q){
      int out_b,in_b; cin >> out_b >> in_b; //空にする箱とその箱からボールを移される箱
      //箱の番号を一つ下げる
      out_b--;
      in_b--;
      if(boxes[out_b].size()>boxes[in_b].size()){
        swap(boxes[out_b],boxes[in_b]);
      }
      //boxes[out_b]の全てのメンバーをboxes[in_b]へ
      boxes[in_b].insert(boxes[out_b].begin(),boxes[out_b].end());
      //boxes[out_b]のメンバー数を表示
      int ans = boxes[in_b].size();
      cout << ans << endl;
      boxes[out_b].clear();
    }
    return 0;
}