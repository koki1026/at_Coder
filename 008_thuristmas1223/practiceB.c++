#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    ll a,m,l,r;
    cin >> a >> m >> l >> r;
    ll start = l + ((a - l)%m);
    ll goal = r - ((r-a)%m);
    ll ans;
    if(goal == start) ans = 1;
    else if(goal<start) ans = 0;
    else ans = ((goal - start) / m) + 1;
    cout << ans << endl;
    return 0;
}