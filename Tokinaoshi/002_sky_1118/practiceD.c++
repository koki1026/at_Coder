#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; //候補者の人数
    cin >> n;
    //候補者の作成
    vector<int> predeter(n,0);//最初は得票数0
    //得票数マックスの候補者の候補者キーと得票数(同数の場合はキー番号が若い人がトップとなる)
    int topKey = 0;
    int topGets = 0;
    int q; //投票人数
    cin >> q;
    rep(i,q){//開票結果に応じて候補者に票を与えていき、トップの人を毎回更新、その都度出力する
      int c;
      cin >> c; //i番目の開票結果
      c--; //候補者キーと合わせる
      predeter[c]++;
      //マックスの候補者より現在票が入った人の方が上回っていれば交代
      if(predeter[c]>topGets){
        topKey = c;
        topGets = predeter[c];
      }
      else if(predeter[c] == topGets && c < topKey){
        topKey = c;
      }
      //更新結果の表示
      int topPredeter = topKey + 1;
      cout << topPredeter << endl;
    }

    return 0;
}