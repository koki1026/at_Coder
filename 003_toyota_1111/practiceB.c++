#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    int n; cin >> n;
    vector<int> d(n);
    for(i=0;i<n;i++){
      int c; cin >> c;
      d[i] = c;
    }
    //ゾロ目の可能性があるものを保存
    int prob = n / 11; //何個あるか
    int zoro_m = 0;
    if(prob == 0){
      if(n==10)zoro_m = 9;
      else zoro_m = n;
    }
    else zoro_m = 9 + prob;
    //ゾロ目の個数を確認
    int answer=0;
    for(i=0;i<min(9,zoro_m);i++){
      int day = i+1;
      if(d[i]<day){/*何もしない*/}
      else if(d[i]<day*11) answer+=1;
      else answer+=2;
    }
    if(zoro_m>9){
      for(i=0;i<zoro_m-9;i++){
        int day = i+1;
        int month = day*10+day;
        if(d[month-1]<day){/*何もしない*/}
        else if(d[month-1]<day*11) answer+=1;
        else answer+=2;
      }
    }
    cout << answer << endl;
    return 0;
}