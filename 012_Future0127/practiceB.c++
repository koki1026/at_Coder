#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
  int i = 0, j = 0;
  string s;
  cin >> s;
  // sに登場する文字の各個数をカウントする
  vector<set<int>> cnt(26);
  int max_cnt = 0;
  int max_cnt_idx = 0; // max_cntを達成する文字のインデックス(同数であれば最小のインデックス)
  rep(i, s.size())
  {
    cnt[s[i] - 'a'].insert(i);
    // 今追加した文字の個数が最大個数より多ければ更新
    if (cnt[s[i] - 'a'].size() > max_cnt)
    {
      max_cnt = cnt[s[i] - 'a'].size();
      max_cnt_idx = s[i] - 'a';
    }
    // 今追加した文字の個数が最大個数と同数であれば、その文字のインデックスが最小であれば更新
    else if (cnt[s[i] - 'a'].size() == max_cnt)
    {
      max_cnt_idx = min(max_cnt_idx, s[i] - 'a');
    }
  }
  // 最大個数のインデックスを出力
  cout << (char)('a' + max_cnt_idx) << endl;
  return 0;
}