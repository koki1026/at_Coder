#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    int n, x;
    cin >> n >> x;
    int answer = 0;
    vector<int> s(n);
    for(i=0;i<n;i++){
      int c; cin >> c;
      s[i] = c;
    }
    for(i=0;i<n;i++){
      if(s[i]<=x){
        answer+=s[i];
      }
    }
    cout << answer << endl;
    return 0;
}