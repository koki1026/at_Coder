#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    int k=0;
    int h,w; cin >> h >> w;
    vector<vector<ll>> a(h,vector<ll>(w,0));
    vector<vector<ll>> b(h,vector<ll>(w,0));
    vector<set<ll>> a_h_s(h, set<ll>());
    vector<set<ll>> b_h_s(h, set<ll>());
    vector<set<ll>> a_w_s(w, set<ll>());
    vector<set<ll>> b_w_s(w, set<ll>());
    bool check = true;
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
        ll c;
        cin >> c;
        a[i][j] = c;
        a_h_s[i].insert(c);
        a_w_s[j].insert(c);
      }
    }
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
        ll cc;
        cin >> cc;
        b[i][j] = cc;
        b_h_s[i].insert(cc);
        b_w_s[j].insert(cc);
      }
    }
    int cnt = 0;
    for(i=0;i<h;i++){
      for(j=i;j<h;j++){
        if(b_h_s[h-1-i]==a_h_s[h-1-j]){
          for(k=h-1-j;k<h-i-1;k++){
            swap(a_h_s[k],a_h_s[k+1]);
            cnt++;
          }
          break;
        }
        if(j==h-1){
          check = false;
        }
      }
    }
    for(i=0;i<w;i++){
      for(j=i;j<w;j++){
        if(b_w_s[w-1-i]==a_w_s[w-1-j]){
          for(k=w-1-j;k<w-i-1;k++){
            swap(a_w_s[k],a_w_s[k+1]);
            cnt++;
          }
          break;
        }
        if(j==w-1){
          check = false;
        }
      }
    }
    if(check) cout << cnt << endl;
    else cout << -1 << endl;
    return 0;
}
