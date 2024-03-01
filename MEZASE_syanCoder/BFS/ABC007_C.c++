#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int r,c; cin >> r >> c;
    int sy,sx; cin >> sy >> sx;
    int gy,gx; cin >> gy >> gx;
    sy--; sx--; gy--; gx--;
    vector<string> m(r);
    rep(i,r) cin >> m[i];
    vector<vector<int>> dist(r,vector<int>(c,0));
    queue<pair<int,int>> q;
    q.push({sy,sx});
    while(!q.empty()){
        int y,x;
        tie(y,x) = q.front(); q.pop();
        if(y==gy && x==gx) break;
        vector<int> dy = {0,1,0,-1};
        vector<int> dx = {1,0,-1,0};
        rep(i,4){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || ny>=r || nx<0 || nx>=c) continue;
            if(m[ny][nx]=='#') continue;
            if(dist[ny][nx]) continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny,nx});
        }
    }
    cout << dist[gy][gx] << endl;
    return 0;
}