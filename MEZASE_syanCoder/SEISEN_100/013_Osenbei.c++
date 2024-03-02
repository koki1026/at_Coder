#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int R,C;
    cin >> R >> C; // 行数と列数を入力
    vector<vector<int>> a(R,vector<int>(C)); // 二次元配列を定義
    rep(i,R)rep(j,C) cin >> a[i][j]; // 二次元配列に値を入力
    int ans = 0; // 答えを格納する変数
    rep(bit,1<<R){ // 行の選び方を全探索
        int sum = 0; // おせんべの数を格納する変数
        //お煎餅の状態をコピーする
        vector<vector<int>> b(a);
        rep(i,R){
            if(bit>>i&1){ // i行目を裏返す
                rep(j,C){
                    b[i][j] = 1 - b[i][j];
                }
            }
        }
        rep(j,C){ // 列ごとに裏返すかどうかを全探索
            int num = 0; // おせんべの数を格納する変数
            rep(i,R){
                if(b[i][j]==0) num++; // 表のおせんべを数える
            }
            sum += max(num,R-num); // 表にするおせんべの数を足す
        }
        ans = max(ans,sum); // 答えを更新
    }
    cout << ans << endl; // 答えを出力
    return 0;
}