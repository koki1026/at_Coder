#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    string s; cin >> s; //文字列
    if(s.size() != 6){
        cout << "No" << endl;
    }
    else{
      if(s[0]=='A'&&s[1]=='B'&&s[2]=='C'){
        //s[3]からs[5]までの文字列を数字に変換
        int num = stoi(s.substr(3,3));
        if(num>=1&&num<=349){
          if(num!=316){
            cout << "Yes" << endl;
          }
          else{
            cout << "No" << endl;
          }
        }
        else{
          cout << "No" << endl;
        }
      }
      else{
        cout << "No" << endl;
      }
    }
    return 0;
}