#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    //n:用いる事ができる数字の数, x:目標の数
    int n,x; cin >> n >> x;
    //ループを3つ回す
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            for(int k=j+1; k<=n; k++){
                if(i+j+k==x) ans++;
                cout << i << " " << j << " " << k << endl;
            }
        }
    }
    cout << ans << endl;

    return 0;
}