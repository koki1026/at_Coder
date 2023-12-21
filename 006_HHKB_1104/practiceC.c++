#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    vector<set<int>> h(9);
    vector<set<int>> w(9);
    vector<set<int>> box(9);

    for(i=0;i<9;i++){
      for(j=0;j<9;j++){
        int c; cin >> c;
        h[i].insert(c);
        w[j].insert(c);
        box[(((i+3)/3)-1)*3 + ((j+3)/3)-1].insert(c);
      }
    }

    bool check = true;
    for(i=0;i<9;i++){
      if(h[i].size()<9) check = false;
    }
    for(i=0;i<9;i++){
      if(w[i].size()<9) check = false;
    }
    for(i=0;i<9;i++){
      if(box[i].size()<9) check = false;
    }

    if(check) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}