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

int inner_rec1(int idx, int total_w, int total_v) {
  if (idx == n) { // 終端。
    return total_v;
  }
  if (total_w + w[idx]> W) {// 選択するとWを超えてしまうのでスキップ。
    return inner_rec1(idx + 1, total_w, total_v);
  }
  // 現在のインデックスの値を選んだ場合と、選ばなかった場合。
  return max(inner_rec1(idx + 1, total_w + w[idx], total_v + v[idx]), inner_rec1(idx + 1, total_w, total_v));
}

int solve1() { // O(2^n)
  return inner_rec1(0, 0, 0);
}

int memo[MAX_N][MAX_N];
int inner_rec2(int i, int j) { // iはindex、jは許容可能な重さの残り。
  int res;
  if (memo[i][j] >= 0) {
    res = memo[i][j];
  }
  if (i == n) {
    res = 0;
  } else if (j - w[i] < 0) {
    res = inner_rec2(i + 1, j);
  } else {
    res = max(inner_rec2(i + 1, j), inner_rec2(i + 1, j - w[i]) + v[i]);
  }
  return memo[i][j] = res;
}

int solve2() { // memoize
  memset(memo, -1, sizeof(memo));
  // for (int i = 0; i < MAX_N; i++) {
  //   for (int j = 0; j < MAX_N; j++) {
  //     printf("%d", memo[i][j]);
  //   }
  //   putchar('\n');
  // }
  return inner_rec2(0, W);
}

int main() {
  read();
  int ans;
  // ans = solve1();
  ans = solve2();
  printf("%d\n", ans);
  return 0;
}
