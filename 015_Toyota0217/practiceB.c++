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
    rep(i,n-1){
        ll t,s;
        cin >> t >> s;
        ll time = a[i]/t;
        a[i+1]+= s*time;
    }
    cout << a[n-1] << endl;
    return 0;
}