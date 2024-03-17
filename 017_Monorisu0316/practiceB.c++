#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    ll n; //値
    cin >> n;
    ll d_ten = n/10; //10の位
    ll d_one = n%10; //1の位
    if(d_one == 0){ //1の位が0の場合
        cout << d_ten << endl; //10のくらい以上をそのまま出力
    }
    else if(d_one != 0 && n>0){ //1の位が0でない場合かつ正の数の時、繰上げ
        cout << d_ten+1 << endl;
    }
    else if(d_one != 0 && n<0){ //1の位が0でない場合かつ負の数の時、繰り下げ
        cout << d_ten << endl;
    }
    return 0;
}