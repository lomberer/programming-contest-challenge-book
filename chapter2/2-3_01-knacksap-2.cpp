// 重さと価値がそれぞれwi, viであるようなn個の品物があります。これらの品物から、重さの総和がWを超えないように選んだ時の
// 価値の総和の最大値を求めなさい。
// 制約; 1 <= n < 100, 1 <= wi < 10^7, 1 <= vi <= 100, 1 <= W < 10^9

// 入力例: n = 4, (w, v) = {(2, 3), (1, 2), (3, 4), (2, 2)}, W = 5
// 出力例: 7(0, 1, 3番目の品物を選ぶ)

#include <iostream>
using namespace std;

const int MAX_N = 100;
const int MAX_V = 100;
const int INF = 0x7ffffff;
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

int dp[MAX_N + 1][MAX_N * MAX_V + 1];
 
int solve() {
  fill(dp[0], dp[0] + MAX_N * MAX_V + 1, INF);
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= MAX_N * MAX_V; j++) {
      if (j < v[i]) {
        dp[i + 1][j] = dp[i][j];
      } else {
        dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
      }
    }
  }  
  int res = 0;
  for (int i = 0; i <= MAX_N * MAX_V; i++) {
    if (dp[n][i] <= W) res = i;
  }
  return res;
}

int main() {
  read();
  printf("%d\n", solve());
  return 0;
}
