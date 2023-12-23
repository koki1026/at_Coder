#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; cin >> n;
    set<ll> rep_kan;

    auto repunit = [&] (auto repunit, ll iii, int cnt) -> void {
      if(cnt == 3){
        rep_kan.insert(iii);
      }
      else{
        repunit(repunit, iii+ll(1), cnt+1);
        repunit(repunit, iii+ll(11), cnt+1);
        repunit(repunit, iii+ll(111), cnt+1);
        repunit(repunit, iii+ll(1111), cnt+1);
        repunit(repunit, iii+ll(11111), cnt+1);
        repunit(repunit, iii+ll(111111), cnt+1);
        repunit(repunit, iii+ll(1111111), cnt+1);
        repunit(repunit, iii+ll(11111111), cnt+1);
        repunit(repunit, iii+ll(111111111), cnt+1);
        repunit(repunit, iii+ll(1111111111), cnt+1);
        repunit(repunit, iii+ll(11111111111), cnt+1);
        repunit(repunit, iii+ll(111111111111), cnt+1);
      }
    };
    repunit(repunit, 0, 0);

    for(i=0;i<n-1;i++){
      rep_kan.erase(rep_kan.begin());
    }
    ll ans = *rep_kan.begin();
    cout << ans << endl;
    return 0;
}