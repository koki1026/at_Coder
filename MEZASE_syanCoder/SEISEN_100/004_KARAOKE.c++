#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    //N:人数 M:曲数
    int N, M; cin >> N >> M;
    //A:各人のM曲の得点
    vector<vector<ll>> A(N, vector<ll>(M));
    rep(i,N) rep(j,M) cin >> A[i][j];
    //曲を2つ選ぶ
    ll ans = 0;
    rep(i,M) rep(j,M){
        if(i==j) continue;
        ll sum = 0;
        rep(k,N) sum += max(A[k][i], A[k][j]);
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}