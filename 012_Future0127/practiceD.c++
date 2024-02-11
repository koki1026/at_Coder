#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
  int i = 0, j = 0;
  int n;
  cin >> n; // 合計の場所の数
  int m;
  cin >> m;                      // 訪れる場所の数
  vector<set<int>> basyo(n + 1); // 訪れる場所basyo[i]が何番目に訪れる場所か
  vector<int> a(m);              // 訪れる場所の配列(インデックス小さい順に訪れる)
  rep(i, m)
  {
    cin >> a[i];
    if (i != m - 1)
    {
      basyo[a[i]].insert(i);
    }
    if (i != 0)
    {
      basyo[a[i]].insert(i - 1);
    }
  }
  vector<int> left(m - 1);      // 左からの距離
  vector<int> right(m - 1);     // 右からの距離
  vector<int> now_kyori(m - 1); // 左からの距離と右からの距離どちらで回っているか
  vector<int> lorr(m - 1);      // 左回りか右回りか(左回りなら1,右回りなら-1)
  set<int> ans;                 // 答え
  rep(i, m - 1)
  {
    left[i] = (a[i + 1] - a[i] + n) % n;
    right[i] = n - left[i];
    cout << "left[" << i << "]: " << left[i] << endl;
    cout << "right[" << i << "]: " << right[i] << endl;
  }
  rep(i, n)
  {
    // a[i]及びa[i+1]が1ではないとき、a[i+1]がa[i]よりも大きければ右回り
    // a[i]及びa[i+1]が1ではないとき、a[i+1]がa[i]よりも小さければ左回り
    if (a[i] != 1 && a[i + 1] != 1)
    {
      if (a[i + 1] > a[i])
      {
        now_kyori[i] = right[i];
        lorr[i] = -1;
      }
      else
      {
        now_kyori[i] = left[i];
        lorr[i] = 1;
      }
    }
    else if (a[i] == 1 && a[i + 1] != 1)
    {
      now_kyori[i] = left[i];
      lorr[i] = 1;
    }
    else if (a[i] != 1 && a[i + 1] == 1)
    {
      now_kyori[i] = right[i];
      lorr[i] = -1;
    }
  }
  int tmp = 0;
  rep(i, m - 1)
  {
    tmp += now_kyori[i];
  }
  ans.insert(tmp);
  cout << "tmp: " << tmp << endl;
  rep(i, n + 1)
  {
    // iが関わっている場所の周りが逆回りになる
    if (basyo[i].size() != 0)
    {
      for (auto itr = basyo[i].begin(); itr != basyo[i].end(); itr++)
      {
        tmp -= now_kyori[*itr];
        if (lorr[*itr] == 1)
        {
          lorr[*itr] = -1;
          now_kyori[*itr] = right[*itr];
        }
        else
        {
          lorr[*itr] = 1;
          now_kyori[*itr] = left[*itr];
        }
        tmp += now_kyori[*itr];
        ans.insert(tmp);
        cout << "i: " << i << endl;
        cout << "tmp: " << tmp << endl;
      }
    }
  }
  cout << *ans.begin() << endl;
  return 0;
}