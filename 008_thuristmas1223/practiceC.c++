#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n,k; cin >> n >> k;
    vector<int> a(k);
    for(i=0;i<k;i++){
      cin >> a[i];
    }
    vector<int> deg(k-1);
    for(i=0;i<k-1;i++){
      deg[i] = a[i+1] - a[i];
    }
    set<int> ans_set;
    int ans=0;
    if((k-1)%2==1){
      for(i=0;i<k-1;i+=2)
      ans += deg[i];
    }
    else{
      int tmp = 0;
      for(i=0;i<k-1;i+=2){
        tmp+=deg[i];
      }
      ans_set.insert(tmp);
      for(i=k-1;i>0;i-=2){
        tmp+=deg[i-1];
        tmp-=deg[i-2];
        ans_set.insert(tmp);
      }
      ans = *ans_set.begin();
    }
    cout << ans << endl;
    return 0;
}