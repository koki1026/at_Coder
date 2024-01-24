#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n;
    cin >> n;
    int t_score=0;
    int a_score=0;
    for(i=0;i<n;i++){
      int c1,c2;
      cin >> c1 >> c2;
      t_score+=c1;
      a_score+=c2;
    }
    if(a_score>t_score){
      cout << "Aoki" << endl;
    }
    else if(a_score<t_score){
      cout << "Takahashi" << endl;
    }
    else {
      cout << "Draw" << endl;
    }
    return 0;
}