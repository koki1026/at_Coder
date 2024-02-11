#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
  int i = 0, j = 0;
  string s;
  cin >> s;
  string ans;
  //ピリオドを見つける
  rep(i, s.size()){
    ans.push_back(s[i]);
    if (s[i] == '.')
    {
      //ansを初期化
      ans.clear();
    }
  }
  cout << ans << endl;

  return 0;
}