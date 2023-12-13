#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vvi = vector<vector<int>>;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int i=0, j=0;
    int h,w;
    cin >> h >> w;
    vvi a(h, vector<int>(w));
    vvi b(h, vector<int>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    rep(i,h)rep(j,w) cin >> b[i][j];

    queue<vvi> q; //各状態を挿入
    map<vvi, int> dist; //距離を管理
    auto push = [&](vvi& s, int d) {
        if(dist.count(s)) return; //すでに登場した盤面であればなにもしない
        dist[s] = d;  //距離と
        q.push(s);    //キューを更新
    };

    //初期化
    push(a,0);
    while (!q.empty()) {
        vvi s = q.front(); q.pop();
        int d = dist[s];
        rep(i,h-1) {
            vvi ns = s;
            swap(ns[i], ns[i+1]);
            push(ns,d+1); //もしnsが以前登場した盤面なら関数の中で勝手に弾かれるのでとりあえずd+1して入れてみていい
        }
        rep(j,w-1) {
            vvi ns = s;
            rep(i,h) swap(ns[i][j], ns[i][j+1]);
            push(ns,d+1);
        }
    }
    
    if(dist.count(b)) cout << dist[b] << endl;
    else cout << -1 << endl;

    return 0;
}