#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    //A:ピザAの値段 B:ピザBの値段 C:両方のピザを半分半分で買う値段
    int A, B, C; cin >> A >> B >> C;
    //X:ピザAをX枚買う Y:ピザBをY枚買う
    int X, Y; cin >> X >> Y;
    //X枚のピザAとY枚のピザBを買う場合の最小値を求める
    ll ans = 0;
    //全探索を用いる
    for(int i=0; i<=max(X,Y)*2; i++){ //i:両方のピザを半分半分で買う枚数
        ll sum = 0; //sum:合計金額
        if(X-i/2>=0) sum += A*(X-i/2);  //X-i/2>=0のとき、sumにA*(X-i/2)を加算
        if(Y-i/2>=0) sum += B*(Y-i/2);  //Y-i/2>=0のとき、sumにB*(Y-i/2)を加算
        sum += C*i; //sumにC*iを加算
        if(i==0) ans = sum;
        else ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}