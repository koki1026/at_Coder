#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int H,W; //グリッドの高さと幅
    cin >> H >> W;
    vector<string> s(H); //グリッド
    int sx=0, sy=0, gx=0, gy=0; //スタート地点とゴール地点
    rep(i, 0, H){
        cin >> s[i];
        //スタート地点とゴール地点を探す
        rep(j, 0, W){
            if(s[i][j] == 'S') sx = i, sy = j;
            if(s[i][j] == 'T') gx = i, gy = j;
        }
    }
    int N; cin >> N; //エネルギー補給マスの数
    vector<int> a(N), b(N); //エネルギー補給マスの座標
    vector<int> e(N); //エネルギー補給量
    rep(i, 0, N) cin >> a[i] >> b[i] >> e[i];
    rep(i, 0, N) a[i]--, b[i]--;
    //エネルギー補給マスをグリッドに反映
    rep(i, 0, N) s[a[i]][b[i]] = i + '0';

    //スタートからゴールまでのコストを幅優先探索のように求める(戻ることもできる)
    vector<vector<int>> max_e(H, vector<int>(W, -1));
    //座標とコストを格納するタプルを作成
    struct P{int x, y, c;};
    queue<P> q;
    if(s[sx][sy] == '.') q.push({sx, sy, 0});
    else{
      q.push({sx, sy, e[s[sx][sy] - '0']});
    }

    while(!q.empty()){
      //各マスにおけるエネルギーの最大値をmax_eに格納
      auto [x, y, c] = q.front(); q.pop();
      if(max_e[x][y] >= c) continue;
      max_e[x][y] = c;
      //上下左右に進む
      int dx[] = {1, 0, -1, 0};
      int dy[] = {0, 1, 0, -1};
      if(c<=0) continue;
      rep(i, 0, 4){
        int nx = x + dx[i], ny = y + dy[i];
        //範囲外や壁の場合はスキップ
        if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        //エネルギー補給マスの場合はエネルギーを補給して進む
        if(s[nx][ny] == '#') continue;
        if(s[nx][ny] == '.'){
          int tmp = c-1;
          q.push({nx, ny, tmp});
        }else{
          if(c < e[s[nx][ny] - '0']){
            int tmp = e[s[nx][ny] - '0'];
            q.push({nx, ny, tmp});
          }
          else{
            int tmp = c-1;
            q.push({nx, ny, tmp});
          }
        }
      }


    }
    //ゴール地点のエネルギーが0なら失敗
    if(max_e[gx][gy] == -1) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}