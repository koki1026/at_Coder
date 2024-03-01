#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    //n:最大値
    int n; cin >> n;
    //nまでの奇数をカウントアップして、その約数が8個のものをカウントする
    int ans = 0;
    for(int i=1; i<=n; i+=2){
        int cnt = 0;
        for(int j=1; j<=i; j++){
            if(i%j==0) cnt++;
            if(cnt>8) break;
        }
        if(cnt==8) ans++;
    }
    cout << ans << endl;
    return 0;
}