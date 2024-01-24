#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n;
    cin >> n;
    vector<int> a(n+1); //それぞれの人が誰の背後にいるか
    for(i=0;i<n;i++){
      cin >> a[i+1];
    }
    int check=-1; //何が出るまで探索するか
    int now = 1; //今誰をみているか
    int check_cnt=0;
    list<int> answer(1,0);
    set<int> mada;
    for(i=0;i<n;i++){
      mada.insert(i+1);
    }

    while(check_cnt<n){
      list<int> tmp;
      while(a[now] != check){
        mada.erase(now);
        tmp.push_front(now);
        check_cnt+=1;
        now = a[now];
      }
      tmp.push_front(now);
      check_cnt+=1;
      mada.erase(now);
      answer.insert(answer.end(),tmp.begin(),tmp.end());
      check = tmp.back();
      cout << check << endl;
      now = *mada.begin();
      list<int>::iterator it = answer.begin();
      while( it != answer.end() ) {
          cout << *it << endl;
          ++it;
      }
    }
    list<int>::iterator it = answer.begin();
    it++;
      while( it != answer.end() ) {
          cout << *it << " ";
          ++it;
      }
      cout << endl;
    return 0;
}