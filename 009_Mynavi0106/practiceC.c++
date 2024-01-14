#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n,q;
    int q1,q_int;
    char q_char;
    cin >> n >> q;
    vector<vector<int>> p(n,vector<int>(2,0));
    for(i=0;i<n;i++){
      p[i][0] = i+1;
    }
    int cnt = 0;
    for(i=0;i<q;i++){
      cin >> q1;
      if(q1 == 1){
        if(cnt==0) cnt=n-1;
        else cnt--;
        cin >> q_char;
        if(q_char=='R'){
          p[cnt][0] = p[(cnt+1)%n][0]+1;
          p[cnt][1] = p[(cnt+1)%n][1];
        }
        else if(q_char=='L'){
          p[cnt][0] = p[(cnt+1)%n][0]-1;
          p[cnt][1] = p[(cnt+1)%n][1];
        }
        else if(q_char=='U'){
          p[cnt][0] = p[(cnt+1)%n][0];
          p[cnt][1] = p[(cnt+1)%n][1]+1;
        }
        else if(q_char=='D'){
          p[cnt][0] = p[(cnt+1)%n][0];
          p[cnt][1] = p[(cnt+1)%n][1]-1;
        }
        //cout << p[0][0] << " " << p[0][1] << endl;
      }
      else{
        cin >> q_int;
        int tmp = (cnt+q_int-1)%n;
        cout << p[tmp][0] << " " << p[tmp][1] << endl;
      }
    }
    return 0;
}