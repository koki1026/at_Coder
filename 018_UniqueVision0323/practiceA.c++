#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; cin >> n; //数字の個数
    vector<int> a(n); //数列
    rep(i,0,n) cin >> a[i];
    rep(i,0,n-1){
        cout << a[i] * a[i+1] << " "; //隣り合う要素の積
    }
    cout << endl; //最後の要素
    return 0;
}