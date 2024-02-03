#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    //数字を全てセットの中に入れて、２番目に大きいものを提出
    int n;
    cin >> n;
    set<int> a;
    rep(i,n){
      int c;
      cin >> c;
      a.insert(c);
    }
    int maxElement = *a.rbegin();
    a.erase(maxElement);
    int answer = *a.rbegin();
    cout << answer << endl;
    return 0;
}