#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    string s;
    cin >> s;
    string t; //最終出力関数
    // 方針: ABCを削除するにあたり、スタックを実装する。一番左から削除していくので、徐々にスタックに入れていきながらABCが出来上がるごとに削除していけば、最後に残っているものが自ずと答えになる
    for(char c :s){ //char型のcにsを一文字ずつ入れてはループ内の操作を行う
        t += c;
        if(t.size() >= 3 && t.substr(t.size()-3) == "ABC"){
            t.pop_back();
            t.pop_back();
            t.pop_back();
        }
    }
    cout << t << endl;
    return 0;
}