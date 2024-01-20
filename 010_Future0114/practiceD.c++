#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n;
    cin >> n;
    vector<int> c(n,0);
    for(i=0;i<n;i++){
      cin >> c[i];
    }
    vector<int> ans(n);
    int cnt;
    int key=0;
    int tmp=0;
    for(i=0;i<n;i++){
      key++;
      tmp=c[i];
      key = min(key,tmp);
      ans[i]=key;
    }
    key=0;
    for(i=0;i<n;i++){
      key++;
      tmp=c[(n-1)-i];
      key = min(key,tmp);
      ans[(n-1)-i]=min(ans[(n-1)-i],key);
    }
    int maxValue = *max_element(ans.begin(), ans.end());
    cout << maxValue << endl;
    return 0;
}