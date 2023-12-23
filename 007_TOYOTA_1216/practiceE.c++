#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n;cin>>n;
    vector<int> t(n+1);
    vector<int> x(n+1);
    for(i=n;i>0;--i){
      cin >> t[i-1];
      cin >> x[i-1];
    }
    vector<int> monster(n+1,0);
    vector<int> portion(n+1,0);
    vector<int> t_or_m;
    int syoji=0;
    int syoji_max=0;
    //冒険の始まり
    for(i=0;i<n;i++){
      if(t[i]==2){
        monster[x[i]]++; //エンカウント
      }
      else{
        if(portion[x[i]]<monster[x[i]]){
          portion[x[i]]++; //足りないなら拾う
          t_or_m.push_back(1); //拾ったことを伝える
        }
        else{
          t_or_m.push_back(0); //拾わなかったことを伝える
        }
      }
    }
    //冒険の振り返り
    int rslt = 0;
    for(i=0;i<n;i++){
      if(monster[i]>portion[i]) rslt = -1;
    }
    if(rslt==-1){
      cout << rslt << endl;
      return 0;
    }
    int t_or_m_size = t_or_m.size()-1;
    for(i=n;i>0;i--){
      if(t[i-1]==2) syoji--;
      else{
        syoji += t_or_m[t_or_m_size];
        t_or_m_size--;
      }
      syoji_max = max(syoji,syoji_max);
    }
    cout << syoji_max << endl;
    for(i=t_or_m.size();i>0;--i){
      cout << t_or_m[i-1];
      if(i!=0) cout << " ";
    }
    return 0;
}