#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    string s;
    cin >> s;
    while(s[i]=='A'){
      i++;
    }
    while(s[i]=='B'){
      i++;
    }
    while(s[i]=='C'){
      i++;
    }
    if(i==s.size()){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
    return 0;
}