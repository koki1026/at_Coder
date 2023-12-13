#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    int h,w; cin >> h >> w;
    vector<vector<ll>> a(h,vector<ll>(w,0));
    vector<vector<ll>> b(h,vector<ll>(w,0));
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
        ll c;
        cin >> c;
        a[i][j] = c;
      }
    }
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
        ll cc;
        cin >> cc;
        b[i][j] = cc;
      }
    }
    set<vector<vector<ll>>> s;
    set<int> myset;
    myset.insert(10000);
    auto swapy = [&](auto swapy, vector<vector<ll>> now, int hw, int first, int cnt) -> void {
      vector<vector<ll>> tmp;
      tmp = now;
      if(tmp == b){
        myset.insert(cnt);
      }
      if(hw == 0){
        swap(tmp[first], tmp[first + 1]);
      }
      else if(hw == 1){
        for(int ii=0;ii<h;ii++){
          swap(tmp[ii][first], tmp[ii][first + 1]);
        }
      }
      int cnt_ = cnt;
      cnt_ ++;
      if(s.count(tmp) == 0){
        s.insert(tmp);
        for(int ii=0;ii<h-1;ii++){
          swapy(swapy, tmp, 0, ii, cnt_);
        }
        for(int ii=0;ii<w-1;ii++){
          swapy(swapy, tmp, 1, ii, cnt_);
        }
      }
    };
    for(int ii=0;ii<h-1;ii++){
      swapy(swapy, a, 0, ii, 0);
    }
    for(int ii=0;ii<w-1;ii++){
      swapy(swapy, a, 1, ii, 0);
    }
    int ans=0;
    ans = *myset.begin();
    if(ans==10000){
      ans = -1;
      cout << ans << endl;
    }
    else cout << ans << endl;
    return 0;
}