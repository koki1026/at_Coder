#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; cin >> n; //人数
    vector<ll> a(n); //商品の座標
    vector<ll> b(n); //商品の座標
    rep(i,n) cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    //aの各要素からの距離が最小となる入口を求める
    ll a_min = a[0]; //入口の座標
    int a_left = 1; //入口の左側の人数
    int a_right = n-1; //入口の右側の人数
    int a_point = 0; //誰が入口の左側のうち、入口に最も近いか
    ll a_distance = 0; //入口からの距離
    while(a[a_point] == a[a_point+1]){
        a_left++;
        a_right--;
        a_point++;
    }
    a_min = a[a_point];
    for(int i=0; i<n; i++){
        a_distance += abs(a[i]-a_min);
    }
    while(a_point < n-1)
    {
      a_min++;
      ll a_distance_temp = a_distance;
      a_distance+=a_left;
      a_distance-=a_right;
      if(a[a_point+1]==a_min){
        a_left++;
        a_right--;
        a_point++;
        if(a_point == n-1){
          break;
        }
        while(a[a_point] == a[a_point+1]){
          a_left++;
          a_right--;
          a_point++;
          if(a_point == n-1){
            break;
          }
        }
      }
      if(a_distance_temp < a_distance){
        a_distance = a_distance_temp;
        break;
      }
    }
    //bの各要素からの距離が最小となる入口を求める
    ll b_min = b[0]; //入口の座標
    int b_left = 1; //入口の左側の人数
    int b_right = n-1; //入口の右側の人数
    int b_point = 0; //誰が入口の左側のうち、入口に最も近いか
    ll b_distance = 0; //入口からの距離
    while(b[b_point] == b[b_point+1]){
        b_left++;
        b_right--;
        b_point++;
    }
    b_min = b[b_point];
    for(int i=0; i<n; i++){
        b_distance += abs(b[i]-b_min);
    }
    while(b_point < n-1)
    {
      b_min++;
      ll b_distance_temp = b_distance;
      b_distance+=b_left;
      b_distance-=b_right;
      if(b[b_point+1]==b_min){
        b_left++;
        b_right--;
        b_point++;
        if(b_point == n-1){
          break;
        }
        while(b[b_point] == b[b_point+1]){
          b_left++;
          b_right--;
          b_point++;
          if(b_point == n-1){
            break;
          }
        }
      }
      if(b_distance_temp < b_distance){
        b_distance = b_distance_temp;
        break;
      }
    }
    ll atob_distance = 0;
    for(int i=0; i<n; i++){
      atob_distance += abs(a[i]-b[i]);
    }
    //debug
    // cout << "a_distance: " << a_distance << endl;
    // cout << "b_distance: " << b_distance << endl;
    // cout << "atob_distance: " << atob_distance << endl;
    // cout << "a_min: " << a_min << endl;
    // cout << "b_min: " << b_min << endl;
    cout << a_distance+b_distance+atob_distance << endl;
    return 0;
}