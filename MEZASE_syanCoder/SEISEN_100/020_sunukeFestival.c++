#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; //ピースの数
    cin >> n;
    vector<ll> a(n); //上部ピースの大きさ
    vector<ll> b(n); //中部ピースの大きさ
    vector<ll> c(n); //下部ピースの大きさ
    rep(i, 0, n){
        cin >> a[i];
    }
    rep(i, 0, n){
        cin >> b[i];
    }
    rep(i, 0, n){
        cin >> c[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll ans = 0;

    //累積和を用いて、とあるbピースをが真に大きい中の最小であるときの、cピースの数を求める
    vector<ll> c_sum(n+1, 0);
    for(int i=n-1; i>=0; --i){
      ll idx = upper_bound(c.begin(), c.end(), b[i]) - c.begin();
      c_sum[i] = c_sum[i+1] + n - idx;
    }
    //aピースを固定して、bピースを選ぶ
    rep(i, 0, n){
      ll idx = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
      ans += c_sum[idx];
    }
    cout << ans << endl;
    return 0;
}

int bekkai(int n, vector<ll> a, vector<ll> b, vector<ll> c){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll ans = 0;

    //bピースを固定して、aピースをが真に小さい中の最大であるときの、cピースの数を求める
    rep(i, 0, n){
      ll idx = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
      ll idx2 = upper_bound(c.begin(), c.end(), b[i]) - c.begin();
      ans += idx * (n - idx2);
    }
    return ans;
}