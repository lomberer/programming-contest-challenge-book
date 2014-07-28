// 重さと価値がそれぞれwi, viであるようなn個の品物があります。これらの品物から、重さの総和がWを超えないように
// 選んだときの、価値の総和の最大値を求めなさい。
// 制約: 1 <= n <= 100, 1 <= wi, vi <= 100, 1 <= W <= 100000
// 入力例: n = 4, (w, v) = {(2, 3), (1, 2), (3, 4), (2, 2)}, W = 5
// 出力例: 7(0, 1, 3番の品物を選ぶ)

#include <iostream>
using namespace std;

const int MAX_N = 100;
int w[MAX_N];
int v[MAX_N];
int n;
int W;

void read() {
  printf("n is "); scanf("%d", &n);
  printf("w are \n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
  }
  printf("v are \n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  printf("W is "); scanf("%d", &W);
}

int inner_rec(int idx, int total_w, int total_v) {
  if (idx == n) { // 終端。
    return total_v;
  }
  if (total_w + w[idx]> W) {// 選択するとWを超えてしまうのでスキップ。
    return inner_rec(idx + 1, total_w, total_v);
  }
  // 現在のインデックスの値を選んだ場合と、選ばなかった場合。
  return max(inner_rec(idx + 1, total_w + w[idx], total_v + v[idx]), inner_rec(idx + 1, total_w, total_v));
}

int solve() {
  return inner_rec(0, 0, 0);
}

int main() {
  read();
  int ans = solve();
  printf("%d\n", ans);
  return 0;
}
