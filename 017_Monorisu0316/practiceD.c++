#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; //タイルの枚数
    cin >> n;
    int H,W; //タイルを敷き詰めたい長方形の縦横
    cin >> H >> W;
    pair<int,int> p[n];
    rep(i,0,n){
        int a,b; //タイルの縦横
        cin >> a >> b;
        p[i] = make_pair(a,b);
    }
    //任意のタイルを用いて長方形にピッタリ敷き詰めることができるかどうかを判定
    int ans = 0;
    //ビット全探索を用いてタイルの選び方を全探索
    rep(i,0,1<<n){
        vector<int> v;
        rep(j,0,n){
            if(i>>j&1){
                v.push_back(j);
            }
        }
        
    }
    return 0;
}