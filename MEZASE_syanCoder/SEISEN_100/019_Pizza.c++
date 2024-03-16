#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    ll d; //環状線の長さ
    int n; //店舗数
    int m; //注文数
    cin >> d >> n >> m;
    vector<ll> store(n);
    rep(i, 0, n-1){
        cin >> store[i+1]; //店舗の位置
    }
    store[0] = 0;
    sort(store.begin(), store.end()); //店舗の位置を昇順にソート
    //注文ごとに、店舗の位置を二分探索で探し、その店舗までの最短距離を求める
    ll ans = 0;
    rep(i, 0, m){
        ll k;
        cin >> k;
        int idx = lower_bound(store.begin(), store.end(), k) - store.begin();
        ll dist1; //idx番目の店舗までの距離
        ll dist2; //idx-1番目の店舗までの距離
        //idxがend()の場合、storeの最後の要素より大きい値が入力されたことになるので、0番目の店舗までの距離を求める
        if(idx == n){
          dist1 = d - k;
        }else{
          dist1 = store[idx] - k;
        }
        //idxが0の場合、0番目の店舗と同じ位置に配達先があるので、0番目の店舗までの距離を求める
        if(idx == 0){
          dist2 = k;
        }else{  
          dist2 = k - store[idx-1];
        }
        ans += min(dist1, dist2);
    }
    cout << ans << endl;
    return 0;
}