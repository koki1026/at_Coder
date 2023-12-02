#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    string s; cin >> s;
    int n = s.size();
    while(i < n-2){
      if(s[i]=='A'){
        if(s[i+1]=='B'){
          if(s[i+2]=='C'){
            s.erase(i,3);
            i = max(-1, i-3);
          }
        }
      }
      i++;
    }
    cout << s << endl;
    return 0;
}