#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<bitset<20>> switches(M);
    vector<int> p(M);

    for (int i = 0; i < M; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int s;
            cin >> s;
            switches[i].set(s - 1);
        }
    }

    for (int i = 0; i < M; ++i) {
        cin >> p[i];
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << N); ++bit) {
        bool flag = true;
        for (int i = 0; i < M; ++i) {
            int count = (switches[i] & std::bitset<20>(bit)).count();
            if (count % 2 != p[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}