#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; //めぐる町の数
    cin >> n;
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    // 2点間の距離を求める
    vector<vector<double>> dist(n, vector<double>(n));
    rep(i,n) rep(j,n){
        dist[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
    }
    //各町を訪れる順番を全通り試す
    vector<int> order(n);
    rep(i,n) order[i] = i;
    double sum = 0;
    do{
        rep(i,n-1) sum += dist[order[i]][order[i+1]];
    }while(next_permutation(order.begin(), order.end()));
    //順列の総数で割る
    int m = 1;
    for(int i=1; i<=n; i++) m *= i;
    cout << fixed << setprecision(10) << sum/m << endl;
    return 0;
}