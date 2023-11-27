#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll D;
    cin >> D;
    ll y = 2e6;
    ll ans = D;
    for (ll x = 0; x < 2e6; x++)
    {
        while(y>0 && x*x+y*y>D){
            y--;
        }
        ans = min(ans, abs(x*x+y*y-D));
        ans = min(ans, abs(x*x+(y-1)*(y-1)-D));
    }
    cout << ans << endl;
    return 0;
}