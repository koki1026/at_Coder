#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int N;
    cin >> N;
    vector<int> a(N);
    int D;
    cin >> D;
    rep(i,N) {
        cin >> a[i];
    }

    vector<vector<int>> a_neibhorD(N);

    rep(i,N){
        rep(j,i){
            int diff = abs(a[i]-a[j]);
            if(diff <= D){
                a_neibhorD[i].push_back(j);
            }
        }
    }

    int ans=0;
    vector<int> dp(N,0);
    rep(i,N){
        int max_dp=0;
        for(int x : a_neibhorD[i]){
            int j = x;
            max_dp=max(max_dp,dp[j]);
        }
        dp[i]=max_dp+1;
        ans=max(ans,dp[i]);
    }
    cout << ans << endl;
    return 0;
}