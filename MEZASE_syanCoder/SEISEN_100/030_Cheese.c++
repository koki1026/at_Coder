#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int H, W;//縦H, 横W
    cin >> H >> W;
    int n; //チーズの数
    cin >> n;
    pair<int,int> a[n+1]; //スタート地点, ゴール地点, チーズの位置
    vector<string> s(H);
    rep(i,0,H){
        cin >> s[i];
        rep(j,0,W){
            if(s[i][j] == 'S'){
                a[0] = {i,j};
            }else if(s[i][j]=='.' || s[i][j]=='X'){
                continue;
            }else{
                a[s[i][j]-'0'] = {i,j};
            }
        }
    }
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int x,y; //スタート地点
    int x2,y2; //ゴール地点
    int ans = 0;
    rep(i,0,n){
        x=a[i].first; y=a[i].second;
        x2=a[i+1].first; y2=a[i+1].second;
        queue<pair<int, int>> q;
        vector<vector<int>> dist(H, vector<int>(W, -1));
        q.push({x,y});
        dist[x][y] = 0;
        while(!q.empty()){
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          rep(i,0,4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=H || ny<0 || ny>=W) continue;
            if(s[nx][ny]=='X') continue;
            if(dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx,ny});
          }
          //debug
          // cout << "dist[" << x << "][" << y << "] = " << dist[x][y] << endl;
        }
        ans += dist[x2][y2];
        //debug
        // cout << "dist[" << x2 << "][" << y2 << "] = " << dist[x2][y2] << endl;
    }
    cout << ans << endl;
    return 0;
}