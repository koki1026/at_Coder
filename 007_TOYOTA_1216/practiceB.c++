#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    string s;
    rep(i,4){
      char c; cin >> c;
      s.push_back(c);
    }
    vector<int> p(4);
    for(i=0;i<4;i++){
      if(s[i]=='A') p[i]=0;
      else if(s[i]=='B') p[i]=1;
      else if(s[i]=='C') p[i]=2;
      else if(s[i]=='D') p[i]=3;
      else if(s[i]=='E') p[i]=4;
    }
    int check_ss = abs(p[0]-p[1])%5;
    int check_tt = abs(p[2]-p[3])%5;
    if(check_ss==check_tt){
      cout << "Yes" << endl;
    }
    else if (check_ss == 1 && check_tt==4){
      cout << "Yes" << endl;
    }
    else if (check_ss == 4 && check_tt==1){
      cout << "Yes" << endl;
    }
    else if (check_ss == 2 && check_tt==3){
      cout << "Yes" << endl;
    }
    else if (check_ss == 3 && check_tt==2){
      cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    return 0;
}