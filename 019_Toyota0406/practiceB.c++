#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; cin >> n; //座標上の点の数
    vector<int> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];

    // 2点間の距離を求める
    auto dist = [&](int i, int j) {
        return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
    };

    // 各座標において、2点間の距離の最大値と、その際のインデックを求める
    vector<int> max_index(n);
    vector<double> d(n);
    rep(i, 0, n) {
        d[i] = 0;
        rep(j, 0, n) {
            if(d[i] < dist(i, j)){
                d[i] = dist(i, j);
                max_index[i] = j;
            }
        }
    }
    //結果を出力
    rep(i, 0, n){
        cout << ++max_index[i] << endl;
    }

    return 0;
}