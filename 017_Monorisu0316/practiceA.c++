#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    string s;
    cin >> s;
    int n = s.size();
    while (i < n){
        if(i==0){
            if(s[i]=='<'){
              i++;
            }
            else{
              cout << 'No' << endl;
              break;
            }
        }else if(i==n-1){
            if(s[i]=='>'){
              cout << 'Yes' << endl;
              break;
            }
            else{
              cout << 'No' << endl;
              break;
            }
        }else{
            if(s[i]=='='){
              i++;
            }
            else{
              cout << 'No' << endl;
              break;
            }
        }
    }
    return 0;
}