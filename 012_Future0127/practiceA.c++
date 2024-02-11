#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
  int i = 0, j = 0;
  string s;
  cin >> s;
  // もしsの先頭の文字以外に大文字があればNoを返す
  rep(i, s.size())
  {
    if (i == 0)
    {
      if (s[i] < 'A' || s[i] > 'Z')
      {
        cout << "No" << endl;
        return 0;
      }
    }
    else
    {
      if (s[i] < 'a' || s[i] > 'z')
      {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;

  return 0;
}