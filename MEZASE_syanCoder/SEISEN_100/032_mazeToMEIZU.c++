#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int H,W; cin >> W >> H;//縦H,横W
    vector<vector<int>> maze_y(H+1, vector<int>(W, 0));//迷路の横向きの壁
    vector<vector<int>> maze_x(H, vector<int>(W+1, 0));//迷路の縦向きの壁
    rep(i,0,W){
        maze_y[0][i]=1;
        maze_y[H][i]=1;
    }
    rep(i,0,H*2-1){
        if(i%2==0){
            rep(j,0,W-1){
                cin >> maze_x[i/2][j+1];
            }
            maze_x[i/2][0]=1;
            maze_x[i/2][W]=1;
        }else{
            rep(j,0,W){
                cin >> maze_y[i/2+1][j];
            }
        }
    }


    vector<vector<int>> dist(H, vector<int>(W, -1));//各マスまでの最短距離
    queue<pair<int,int>> que;
    que.push(make_pair(0,0));//スタート地点
    dist[0][0]=1;//スタート地点までの距離は0
    int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};//4方向への移動
    while(!que.empty()){
      pair<int,int> p=que.front(); que.pop();
      int x=p.first, y=p.second;
      rep(i,0,4){
        int nx=x+dx[i], ny=y+dy[i];
        if(nx<0 || nx>=W || ny<0 || ny>=H) continue;//迷路の外に出るならスキップ
        if(i==0 && maze_x[y][x+1]==1) continue;//右に壁があるならスキップ
        if(i==1 && maze_y[y+1][x]==1) continue;//下に壁があるならスキップ
        if(i==2 && maze_x[y][x]==1) continue;//左に壁があるならスキップ
        if(i==3 && maze_y[y][x]==1) continue;//上に壁があるならスキップ
        if(dist[ny][nx]!=-1) continue;//既に訪れているならスキップ
        dist[ny][nx]=dist[y][x]+1;//移動先の距離を更新
        que.push(make_pair(nx,ny));//移動先をキューに追加
      }
    }
    cout << dist[H-1][W-1] << endl;//ゴール地点までの最短距離を出力

    return 0;
}