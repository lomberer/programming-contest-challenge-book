// 重さと価値がそれぞれwi, viであるようなn種類の品物があります。これらの品物から、重さの総和がWを超えないように選んだ時の、
// 価値の総和の最大値を求めなさい。ただし、同じ種類の品物をいくつでも選ぶことができます。
// 制約: 1 <= n < 100, 1 <= wi, vi <= 100, 1 <= W <= 10000

// 入力例: n = 3, (w, v) = {(3, 4), (4, 5), (2, 3)}, W = 7
// 出力例: 10(0番目の品物を1つ、2番目の品物を2つ選ぶ)

#include <iostream>
using namespace std;

const int MAX_N = 100;
int n;
int w[MAX_N];
int v[MAX_N];
int W;

void read() {
  printf("n is >> "); scanf("%d", &n);
  printf("w are >> \n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
  }
  printf("v are >> \n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  printf("W is >> "); scanf("%d", &W);
}

int rec(int i, int rest_w) {
  if (i == n) return 0;
  if (w[i] > rest_w) return rec(i + 1, rest_w); // 重量オーバーのためi番目を選ぶことができない。
  return max(rec(i, rest_w - w[i]) + v[i], // i番目を選びもう一度i番目を選ぶか選択する。
             max(rec(i + 1, rest_w - w[i]) + v[i], // i番目を選び次の品物へ。
                 rec(i + 1, rest_w))); // i番目をスキップ。
}

int main() {
  read();
  printf("%d\n", rec(0, W));
  return 0;
}
