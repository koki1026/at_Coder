#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int H,W;  cin >> H >> W; // H:縦, W:横
    int m; cin >> m;//クエリの数
    pair<int, int> query[m];
    vector<int> h_or_w(m); //クエリの種類
    rep(i,0,m){
        int ki, ai, xi; cin >> ki >> ai >> xi;
        if(ki==1){
            query[i] = make_pair(ai, xi);
            h_or_w[i] = 1;
        }else{
            query[i] = make_pair(ai, xi);
            h_or_w[i] = 2;
        }
    }


    vector<bool> h_paint(H,false); //縦の色が塗られているか
    vector<bool> w_paint(W,false); //横の色が塗られているか
    vector<ll> color(200010,0); //色の数
    color[0] = H*W; //色が塗られていないマスの数
    int h_size = 0; //縦のクエリの数
    int w_size = 0; //横のクエリの数
    //クエリを逆順に処理する
    for(i=m-1; i>=0; --i){
        if(h_or_w[i]==1){
            //縦のクエリを処理
            int color_change_size = W - w_size; //変更されるマスの数
            if(!h_paint[query[i].first]){ //その場所が既出であるか
                h_paint[query[i].first] = true;
                h_size++;
                if(query[i].second == 0){
                    continue;
                }
                color[query[i].second] += color_change_size;
                color[0] -= color_change_size;
            }

        }else{
            //横のクエリを処理
            int color_change_size = H - h_size; //変更されるマスの数
            if(!w_paint[query[i].first]){ //その場所が既出であるか
                w_paint[query[i].first] = true;
                w_size++;
                if(query[i].second == 0){
                    continue;
                }
                color[query[i].second] += color_change_size;
                color[0] -= color_change_size;
            }
        }
    }

    //順に答えを出力
    int count = 0;
    rep(i,0,color.size()){
        if(color[i]!=0){
            count++;
        }
    }
    cout << count << endl;
    rep(i,0,color.size()){
        if(color[i]!=0){
            cout << i << " " << color[i] << endl;
        }
    }

    return 0;
}