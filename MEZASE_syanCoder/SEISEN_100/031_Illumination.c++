#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int W, H;//H:高さ, W:幅
    cin >> W >> H;
    H+=2; W+=2; //ぐるっと一周多く取る
    vector<vector<int>> A(H, vector<int>(W, 0));//A:入力される行列
    rep(i, 1, H-1) rep(j, 1, W-1) cin >> A[i][j];
    rep(i, 0, H) rep(j, 0, W) if(i==0||i==H-1||j==0||j==W-1) A[i][j]=0;//ぐるっと一周0にする

    //移動行列
    vector<int> dx_g={-1, -1, 0, 0, 1, 1}; //偶数列 0,1,2,3,4,5
    vector<int> dy_g={-1, 0, -1, 1, -1, 0};
    vector<int> dx_k={-1, -1, 0, 0, 1, 1}; //奇数列 0,1,2,3,4,5
    vector<int> dy_k={0, 1, -1, 1, 0, 1};

    //探索
    vector<vector<int>> seen(H, vector<int>(W, 0));//seen:探索済みかどうか
    queue<pair<int, int>> que;
    int ans=0;
    int x, y; //x:列, y:行
    x=0; y=0;
    que.push(make_pair(x, y));
    seen[x][y]=1;
    while(!que.empty()){
        x=que.front().first;
        y=que.front().second;
        que.pop();
        if(x%2==0){
            rep(i, 0, 6){
                int nx=x+dx_g[i];
                int ny=y+dy_g[i];
                if(nx<0||nx>=H||ny<0||ny>=W) continue;
                if(A[nx][ny]==1){
                    ans++;
                    continue;
                }
                if(seen[nx][ny]) continue;
                seen[nx][ny]=1;
                que.push(make_pair(nx, ny));
            }
        }else{
            rep(i, 0, 6){
                int nx=x+dx_k[i];
                int ny=y+dy_k[i];
                if(nx<0||nx>=H||ny<0||ny>=W) continue;
                if(A[nx][ny]==1){
                    ans++;
                    continue;
                }
                if(seen[nx][ny]) continue;
                seen[nx][ny]=1;
                que.push(make_pair(nx, ny));
            }
        }
    }

    cout << ans << endl;


    return 0;
}