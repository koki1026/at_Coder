#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    ll D;
    cin >> D;
    double double_D = static_cast<double>(D);
    double root_D = sqrt(D);
    ll cast_D  = static_cast<ll>(floor(root_D));
    cast_D += 5;
    int minn = 1001001001;
    rep(i,cast_D){
      ll xx = i*i;
      ll yy_dash = D - xx;
      double yy_double = sqrt(yy_dash);
      int y = static_cast<int>(floor(yy_double));
      int yy = y*y;
      int yy_a = (y+1)*(y+1);
      int tmp = abs(yy+xx-D);
      minn = min(minn,tmp);
      tmp = abs(yy_a+xx-D);
      minn = min(minn,tmp);
    }
    cout << minn << endl;
    return 0;
}