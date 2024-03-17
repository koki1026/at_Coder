#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int H, W;//縦H, 横W
    cin >> H >> W;
    vector<string> s(H);
    rep(i, 0, H) cin >> s[i];
    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int, int>> que;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int sx, sy, gx, gy;
    sx = 0; sy = 0; gx = H-1; gy = W-1;
    que.push(make_pair(sx, sy));
    dist[sx][sy] = 1;
    while(!que.empty()){
      int x,y;
      tie(x, y) = que.front(); que.pop();
      rep(i, 0, 4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if(s[nx][ny] == '#') continue;
        if(dist[nx][ny] != -1) continue;
        dist[nx][ny] = dist[x][y] + 1;
        que.push(make_pair(nx, ny));
      }
    }
    if(dist[gx][gy] == -1){
      cout << -1 << endl;
      return 0;
    }
    int ans = 0;
    rep(i, 0, H){
      rep(j, 0, W){
        if(s[i][j] == '#') ans++;
      }
    }
    ans = H*W - ans - dist[gx][gy];
    cout << ans << endl;
    return 0;
}
