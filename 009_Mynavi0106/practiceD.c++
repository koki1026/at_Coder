#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n;
    cin >> n;
    vector<vector<int>> ground(n+1,vector<int>(n+1,0));
    int cnt;
    cnt = n*n;
    int w = (n+1)/2;
    int h = (n+1)/2-1;
    ground[w][h] = --cnt;
    w++;
    ground[w][h] = --cnt;
    for(i=2;i<n;i++){
      if(i%2==0){
        for(j=0;j<i;j++){
          h++;
          ground[w][h] = --cnt;
        }
        for(j=0;j<i;j++){
          w--;
          ground[w][h] = --cnt;
        }
      }
      else if(i%2==1){
        for(j=0;j<i;j++){
          h--;
          ground[w][h] = --cnt;
        }
        for(j=0;j<i;j++){
          w++;
          ground[w][h] = --cnt;
        }
      }
    }
    for(i=0;i<n-1;i++){
      --h;
      ground[w][h] = --cnt;
    }

    //描画
    for(i=1;i<n+1;i++){
      if(i!=(n+1)/2){
        for(j=1;j<n;j++){
          cout << ground[i][j] << " ";
        }
        cout << ground[i][j] << endl;
      }
      else {
        for(j=1;j<(n+1)/2;j++){
          cout << ground[i][j] << " ";
        }
        cout << 'T' << " ";
        for(j=(n+1)/2 + 1;j<n;j++){
          cout << ground[i][j] << " ";
        }
        cout << ground[i][j] << endl;
      }
    }
    return 0;
}