#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
  int i = 0, j = 0;
  int n;
  cin >> n;              // 材料の個数
  vector<int> q(n);      // 材料の個数分の配列
  rep(i, n) cin >> q[i]; // 材料の個数分の配列に個数を入力
  vector<int> a(n);      // 食材Aを作るために必要な材料の個数
  rep(i, n) cin >> a[i]; // 食材Aを作るために必要な材料の個数を入力
  vector<int> b(n);      // 食材Bを作るために必要な材料の個数
  rep(i, n) cin >> b[i]; // 食材Bを作るために必要な材料の個数を入力

  set<int> ans;      // 作れる料理の数
  bool check = true; // 作れる料理があるかどうか
  int A_cnt = 0;
  int B_cnt = 0;
  while (check)
  {
    int tmp = 100100100;
    rep(i, n)
    {
      if (q[i] >= (a[i] * A_cnt))
      {
        if (b[i] == 0)
        {
          continue;
        }
        else
        {
          B_cnt = (q[i] - (a[i] * A_cnt)) / b[i];
          tmp = min(tmp, B_cnt);
        }
      }
      else
      {
        tmp = 0;
        A_cnt = 0;
        check = false;
        break;
      }
    }
    ans.insert(tmp + A_cnt);
    A_cnt++;
  }
  cout << *ans.rbegin() << endl;
  return 0;
}