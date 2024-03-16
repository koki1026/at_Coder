#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int w, h; cin >> w >> h; // w:横 h:縦
    vector<vector<int>> a(h, vector<int>(w)); // 2次元配列の初期化
    rep(i, 0, h) rep(j, 0, w) cin >> a[i][j]; // 2次元配列の入力　1:陸地 0:海
    vector<vector<int>> d(h, vector<int>(w, -1)); // 訪れたかどうかのフラグ
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1}; // 8方向の移動
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1}; // 8方向の移動
    function<int(int, int)> dfs = [&](int x, int y){
        d[y][x] = 1; // 訪れた
        rep(i, 0, 8){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < w && ny >= 0 && ny < h && a[ny][nx] == 1 && d[ny][nx] == -1){
                return dfs(nx, ny) +1;
            }
        }
        return 1;
    };
    int cnt = 0;
    int ans = 0;
    rep(i, 0, h) rep(j, 0, w){
        if(a[i][j] == 1 && d[i][j] == -1){
            int tmp = dfs(j, i);
            cnt = max(cnt, tmp);
            ans++;
        }
    }
    cout << cnt << endl;
    cout << ans << endl;
    return 0;
}