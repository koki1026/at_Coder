#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int H,W; cin >> H >> W; //盤面の縦横
    int x,y;  //スタート地点
    cin >> x >> y; x--; y--;
    int gx,gy; //ゴール地点
    cin >> gx >> gy; gx--; gy--;
    vector<string> s(H);
    rep(i,0,H) cin >> s[i]; //.は通れる, #は通れない
    vector<vector<int>> dist(H, vector<int>(W, -1));//各マスへの最短距離
    queue<pair<int,int>> que;
    que.push({x,y});
    dist[x][y] = 0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    while(!que.empty()){
      int x = que.front().first;
      int y = que.front().second;
      que.pop();
      rep(i,0,4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if(s[nx][ny] == '#') continue;
        if(dist[nx][ny] != -1) continue;
        dist[nx][ny] = dist[x][y] + 1;
        que.push({nx,ny});
      }
    }
    cout << dist[gx][gy] << endl;
    return 0;
}