#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
  int i = 0, j = 0;
  // ASCIIコードにて配列にアクセスできるようにする
  vector<int> c_array(26, 0);
  int n;
  cin >> n;
  int c_arrayBase = static_cast<int>('a');
  int pre = 100;
  int pre_cnt = 0;
  rep(i, n)
  {
    char c;
    cin >> c;
    int c_int = static_cast<int>(c);
    int c_arrayElement = c_int - c_arrayBase;
    if (c_arrayElement == pre)
    { // 前と同じ文字なら
      pre_cnt++;
      c_array[c_arrayElement] = max(pre_cnt, c_array[c_arrayElement]);
    }
    else
    { // 前と違う文字だったら
      pre_cnt = 1;
      c_array[c_arrayElement] = max(pre_cnt, c_array[c_arrayElement]);
      pre = c_arrayElement;
    }
  }
  int answer = 0;
  rep(i, 26)
  {
    answer += c_array[i];
  }
  cout << answer << endl;
  return 0;
}