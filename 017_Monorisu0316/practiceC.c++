#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    string s;//文字列
    cin >> s;
    vector<int> v(26,0);//アルファベットの数を数えるための配列
    int n = s.size();
    rep(i,0,n){
        v[s[i]-'a']++;//アルファベットの数を数える
    }
    int flag = 0; //アルファベットに重複があるかどうかのフラグ
    rep(i,0,26){
        if(v[i]>1){
            flag = 1;
            break;
        }
    }
    ll ans = 0;
    ll cnt = n;
    rep(i,0,n){
      char c = s[i];
      v[c-'a']--;//文字列のi番目のアルファベットを数える
      cnt--;
      ans += cnt-v[c-'a'];//文字列のi番目のアルファベットを数える
      //debug
      // cout << "i: " << i << " c: " << c << " v[c-'a']: " << v[c-'a'] << " ans: " << ans << endl;
    }
    if(flag == 0){
        cout << ans << endl; //重複がない場合はそのまま出力
    }
    else{
        cout << ans+1 << endl; //重複がある場合は+1
    }
    return 0;
}