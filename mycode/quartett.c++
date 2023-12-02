#include <bits/stdc++.h>
using namespace std;
using ll = long long;


//与えられた四つの数字から10となる四則演算の組み合わせを見つける
int main(){
  int i=0, j=0;
  vector<float> n;
  for(i=0;i<4;i++){
    float c; cin >> c;
    n.insert(c);
  }

  //nから一つずつ要素を取り出しては四則演算のどれかをさせる再帰処理を回し、全て取り出し終わったら10になっているか判定
  vector<vector<float>> correct_box(4,0);
  auto alice = [&](auto alice, int s, char c, float ans, vector<float>n_array){
      s++;
      if(c=='+') ans += n_array[s];
      else if(c=='-') ans -= n_array[s];
      else if(c=='*') ans *= n_array[s];
      else if(c=='/') ans /= n_array[s];
      if(s>=3){
        //判定
        if(ans==10) correct_box.insert(n_array);
      }
      alice(alice, s, +, int ans_a, nums);
      alice(alice, s, -, int ans_b, nums);
      alice(alice, s, *, int ans_c, nums);
      alice(alice, s, /, int ans_d, nums);
  }
  auto quar = [&](auto quar, int k, vector<float> nums) -> void {
    if(k==0){
      //10であるか判定
      int s = 0;
      alice(alice, s, +, int ans_a, nums);
      alice(alice, s, -, int ans_b, nums);
      alice(alice, s, *, int ans_c, nums);
      alice(alice, s, /, int ans_d, nums);
    }
    for(int l=0;l<k;k++){
      vector<float> tmp = nums;
      swap(tmp[l],tmp[k]);//選択したものを端っこへ
      quar(quar, k-1, tmp);//入れ替えた配列にて再帰処理
      swap(tmp[l],tmp[k]);//元に戻す
    }
  };
  return 0;
}