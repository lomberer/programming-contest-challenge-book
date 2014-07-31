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

////////////////////////////////////////
// O(3^n)
////////////////////////////////////////
int rec1(int i, int rest_w) {
  if (i == n) return 0;
  if (w[i] > rest_w) return rec1(i + 1, rest_w); // 重量オーバーのためi番目を選ぶことができない。
  return max(rec1(i, rest_w - w[i]) + v[i], // i番目を選びもう一度i番目を選ぶか選択する。
             max(rec1(i + 1, rest_w - w[i]) + v[i], // i番目を選び次の品物へ。
                 rec1(i + 1, rest_w))); // i番目をスキップ。
}

int solve1() {
  return rec1(0, W);
}

////////////////////////////////////////
// memoization
////////////////////////////////////////
const int MAX_W = 10000;
int memo[MAX_N][MAX_W];

int rec2(int i, int rest_w) {
  if (memo[i][rest_w] > -1) return memo[i][rest_w]; // 計算済みの値。
  int res;
  if (i == n) res = 0;
  if (w[i] > rest_w)
    res = rec1(i + 1, rest_w); // 重量オーバーのためi番目を選ぶことができない。
  else
    res = max(rec1(i, rest_w - w[i]) + v[i], // i番目を選びもう一度i番目を選ぶか選択する。
              max(rec1(i + 1, rest_w - w[i]) + v[i], // i番目を選び次の品物へ。
                  rec1(i + 1, rest_w))); // i番目をスキップ。
  return memo[i][rest_w] = res;
}

int solve2() {
  memset(memo, -1, sizeof(memo));
  return rec2(0, W);
}

////////////////////////////////////////
// DP (O(n*W))
////////////////////////////////////////
int dp[MAX_N + 1][MAX_W];

int solve3() {
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= W; j++) {
      if (w[i] > j) {
        dp[i][j] = dp[i+1][j]; 
      } else {
        dp[i][j] = max(dp[i][j - w[i]] + v[i],
                       max(dp[i + 1][j - w[i]] + v[i],
                           dp[i + 1][j]));
      }
    }
  }
  return dp[0][W];
}

int main() {
  read();
  //printf("%d\n", solve1());
  //printf("%d\n", solve2());
  printf("%d\n", solve3());
  return 0;
}
