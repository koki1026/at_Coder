#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int N,K; // N:建物の数, K:色の数
    cin >> N >> K;
    vector<ll> a(N); // 建物の初期高さを格納する配列
    rep(i,N) cin >> a[i]; // 建物の高さを入力
    ll ans = 1e17; // 答えを格納する変数
    rep(bit,1<<N){ // 建物の塗り方を全探索
        ll sum = 0; // 塗り替える回数を格納する変数
        ll max_h = 0; // 塗り替える建物の最大高さを格納する変数
        ll cnt = 0; // 塗り替える建物の数を格納する変数
        rep(i,N){
            if(bit>>i&1){ // i番目の建物を塗り替える
                if(a[i] <= max_h){ // 塗り替える建物の高さが最大高さ以下の場合
                    sum += max_h - a[i] + 1; // 塗り替える回数を足す
                    max_h++; // 塗り替える建物の高さを更新
                }
                max_h = max(max_h,a[i]); // 塗り替える建物の最大高さを更新
                cnt++; // 塗り替える建物の数を足す
            }
            // 塗り替える建物の最大高さを更新
            else if(a[i] > max_h){
                max_h = a[i];
                //debug
                //cout << "bit: " << bit << endl; // "bit: 1" "bit: 3" "bit: 3" "bit: 7" "bit: 7" "bit: 7" "bit: 7
                //cout << "i: " << i << endl;
                //cout << "max_h: " << max_h << endl;
                cnt++;
                //cout << "cnt: " << cnt << endl;
            }
        }
        if(cnt >= K){
            ans = min(ans,sum); // 塗り替える建物の数がK以上の場合、答えを更新
            //cout << "ans: " << ans << endl;
            //cout << "bit: " << bit << endl;
        }
    }
    cout << ans << endl; // 答えを出力
    return 0;
}