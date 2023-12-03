#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    int n;
    float s, m, l;
    cin >> n >> s >> m >> l;
    //再帰処理で値段をプッシュする
    set<int> values = {};
    values.insert(10e8);
    auto cal = [&](auto cal, char size, int val_tmp, int rest){
      if(size == 's'){
        val_tmp += s;
        rest -= 6;
      }
      else if(size == 'm'){
        val_tmp += m;
        rest -= 8;
      }
      else if(size == 'l'){
        val_tmp += l;
        rest -= 12;
      }
      if(rest <= 0){
        values.insert(val_tmp);
        return;
      }
      cal(cal, 's', val_tmp, rest);
      cal(cal, 'm', val_tmp, rest);
      cal(cal, 'l', val_tmp, rest);
    };

    cal(cal, 's', 0, n);
    cal(cal, 'm', 0, n);
    cal(cal, 'l', 0, n);
    int ans = *(values.begin());
    cout << ans << endl;
    return 0;
}