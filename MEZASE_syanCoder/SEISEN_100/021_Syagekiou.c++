#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; //風船の数
    cin >> n;
    vector<ll> h(n); //風船の高さと場所
    vector<ll> s(n); //風船の速度
    rep(i, 0, n){
        cin >> h[i] >> s[i];
    }
    ll ans = 0;
    //とある高さまでに風船を割ることができるかを二分探索で調べる
    ll left = 0, right = 1e18; //風船を割るまでの最大の高さ
    while(right - left > 1){
        ll mid = (left + right) /2; //風船を割るまでの最大の高さ
        bool ok = true; //風船を割ることができるか
        vector<ll> t(n, 0); //風船を割るまでの時間
        rep(i, 0, n){
            if(mid < h[i]){
                ok = false;
            }else{
                t[i] = (mid - h[i]) / s[i];
            }
        }
        sort(t.begin(), t.end());
        //i番目の風船を割るまでの時間がi以下でなければ風船を割ることができない
        rep(i, 0, n){
            if(t[i] < i){
                ok = false;
            }
        }
        if(ok){
            right = mid;
        }else{
            left = mid;
        }
    }
    cout << right << endl;

    return 0;
}