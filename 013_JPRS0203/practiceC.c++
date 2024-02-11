#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    //後ろから見ていく
    ll min_init=0;
    rep(i,n){
        //n-1-i番目の要素が負の数なら、それをansに足す
        if(a[n-1-i]<0){
            min_init-=a[n-1-i];
        }
        //n-1-i番目の要素が0以上なら、ansからそれを引く
        else{
            min_init-=a[n-1-i];
        }
        //ansが負の数になったら、0にする
        if(min_init<0){
            min_init=0;
        }
    }
    //min_initの時の、最終的な計算値を出力
    rep(i,n){
        min_init+=a[i];
    }
    cout << min_init << endl;
    return 0;
}