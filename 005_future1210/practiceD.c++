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
    set<int> myset;
    myset.insert(10000);
    auto swapy = [&](auto swapy, vector<vector<ll>> now, int hw, int first, int last , int cnt) -> void {
      vector<vector<ll>> tmp(h,vector<ll>(w,0));
      for(int ii=0;ii<h;ii++){
        for(int jj=0;jj<w;jj++){
          tmp[ii][jj] = now[ii][jj];
        }
      }
      if(hw == 0){
        for(int ii=0;ii<w;ii++){
          swap(tmp[first][ii], tmp[last][ii]);
        }
      }
      else if(hw == 1){
        for(int ii=0;ii<h;ii++){
          swap(tmp[ii][first], tmp[ii][last]);
        }
      }
      int cnt_ = cnt;
      cnt_ ++;
      bool check = true;
      int check_cnt = 0;
      for(int ii=0;ii<h;ii++){
        if(check){
          for(int jj=0;jj<w;jj++){
            if(check){
              if(tmp[ii][jj]!=b[ii][jj]) check = false;
              else check_cnt ++;
            }
          }
        }
      }
      if(check_cnt==h*w){
        myset.insert(cnt_);
      }
      else if(cnt_ >20){
        //
      }
      else{
        for(int ii=0;ii<h-1;ii++){
          for(int jj=ii+1;jj<h;jj++){
            swapy(swapy, tmp, 0, ii, jj, cnt_);
          }
        }
        for(int ii=0;ii<w-1;ii++){
          for(int jj=ii+1;jj<w;jj++){
            swapy(swapy, tmp, 1, ii, jj, cnt_);
          }
        }
      }
    };
    for(int ii=0;ii<h-1;ii++){
      for(int jj=ii+1;jj<h;jj++){
        swapy(swapy, a, 0, ii, jj, 0);
      }
    }
    for(int ii=0;ii<w-1;ii++){
      for(int jj=ii+1;jj<w;jj++){
        swapy(swapy, a, 1, ii, jj, 0);
      }
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