#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int m, n; cin >> m >> n;//n:行数, m:列数
    vector<vector<int>> a(n, vector<int>(m));//a:行列
    rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];//0:氷がない, 1:氷がある
    int ans = 0;
    //深さ優先探索にて氷の塊を探す
    vector<vector<int>> b(n, vector<int>(m, 0));//b:訪れたかどうかのフラグ
    function<int(int, int)> bfs = [&](int x, int y){
        int cnt = 1;
        if(x<0 || x>=n || y<0 || y>=m || a[x][y]==0 || b[x][y]==1) return 0;
        //debug
        //cout << "x: " << x << " y: " << y << endl;
        b[x][y] = 1;
        //4方向に移動
        cnt += bfs(x+1, y);
        cnt = max(cnt, bfs(x-1, y)+1);
        cnt = max(cnt, bfs(x, y+1)+1);
        cnt = max(cnt, bfs(x, y-1)+1);
        //割った氷を元に戻す
        b[x][y] = 0;
        return cnt;
    };
    rep(i, 0, n) rep(j, 0, m){
        if(a[i][j] == 1 && b[i][j] == 0){
            ans = max(ans, bfs(i, j));
            //debug
            //cout << "ans: " << ans << endl;
        }
        b = vector<vector<int>>(n, vector<int>(m, 0));
    }
    cout << ans << endl;
    return 0;
}