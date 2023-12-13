#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

void chmin(double& a, double b) { a = min(a,b);}

int main(){
    int i=0, j=0;
    int n,d;
    cin >> n >> d;
    vector<double> w(n);
    rep(i,n) cin >> w[i];

    //2のn乗はシフト演算でできる
    int n2 = 1<<n;

    //平均の計算
    double ave = 0;
    for(i=0;i<n;i++){
        ave += w[i];
    }
    ave /= d;

    vector<double> x(n2);  //部分集合の集合→集合の二乗平均
    rep(s,n2) {
        rep(i,n) if (s>>i&i) x[s] += w[i];
        x[s] = (x[s] - ave) * (x[s] - ave);
    }

    const double INF = 1e18;
    vector<double> dp(n2, INF);
    dp[n2-1] = 0;
    rep(i,d) {
        vector<double> old(n2, INF);
        swap(old,dp);
        rep(s,n2){
            for(int t=s;;t=(t-1)&s) {
                chmin(dp[s^t], dp[s]+x[t]);
                if (t==0) break;
            }
        }
    }

    double ans = dp[0]/d;
    printf("%.10f\n", ans);
    return 0;
}