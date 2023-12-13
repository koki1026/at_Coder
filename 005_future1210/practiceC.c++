#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    int n,plane;
    cin >> n >> plane;
    string s;
    cin >> s;
    int rogo=0;

    int plane_now = plane;
    int rogo_now = 0;
    for(i=0;i<n;i++){
      if(s[i]=='1'){
        //無地きて無理ならロゴきる
        if(plane_now>0) --plane_now;
        else if(rogo_now>0) --rogo_now;
        else{
          rogo++;
        }
      }
      else if(s[i]=='2'){
        //ロゴきる
        if(rogo_now>0) --rogo_now;
        else{
           rogo++;
        }
      }
      else{
        //全て復活
        rogo_now = rogo;
        plane_now = plane;
      }
    }
    cout << rogo << endl;
    return 0;
}