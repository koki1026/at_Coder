#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    int mm, dd;
    cin >> mm >> dd;
    int y, m, d;
    cin >> y >> m >> d;
    d++;
    if(d>dd){
      d = 1;
      m++;
      if(m>mm){
        m = 1;
        y++;
      }
    }
    cout << y << " " << m << " " << d << endl;
    return 0;
}