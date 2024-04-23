#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    string Airpote; cin >> Airpote; //空港の名前
    string ommission; cin >> ommission; //略記
    //空港の名前から略記ができるかどうかを判定
    //略記を小文字表記にする
    rep(i,0,3){
      ommission[i] = tolower(ommission[i]);
    }
    //空港の名前から略記ができるかどうかを判定
    int om_count = 0;

    if(ommission[2]!='x'){
      rep(i,0,Airpote.size()){
        if(Airpote[i] == ommission[om_count]){
          om_count++;
        }
        if(om_count == 3){
          cout << "Yes" << endl;
          return 0;
        }
      }
      cout << "No" << endl;
    }
    else{
      rep(i,0,Airpote.size()){
        if(Airpote[i] == ommission[om_count]){
          om_count++;
        }
        if(om_count == 2){
          cout << "Yes" << endl;
          return 0;
        }
      }
      cout << "No" << endl;
    }
    return 0;
}