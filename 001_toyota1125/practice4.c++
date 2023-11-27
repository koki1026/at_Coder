#include <bits/stdc++.h>
using namespace std;

//縦または横のoの個数をカウント
int s_count(string s, int n){
  int cnt=0;
  for(int i = 0; i<n; i++){
    if(s[i]=='o') cnt++;
  }
  return cnt;
}

int main(){
  int n;
  cin >> n;
  int w,h;
  int ans=0;
  int i,j;
  int h_cnt;
  int w_cnt;
  std::vector<std::string> sw(n);
  std::vector<std::string> sh(n);
  for (i=0;i<n;i++){
    cin >> sw[i];
  }
  for (i=0;i<n;i++){
    for(j=0;j<n;j++){
      sh[i]+=sw[j][i];
    }
  }
  for (i=0;i<n;i++){
    w_cnt = s_count(sw[i],n);
    if(w_cnt>=2){
      for(j=0;j<n;j++){
        if(sw[i][j]=='o'){
          h_cnt = s_count(sh[j],n);
          if(h_cnt>=2){
            ans+=(w_cnt-1)*(h_cnt-1);
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}