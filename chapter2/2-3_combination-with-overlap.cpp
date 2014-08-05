// n種類の品物があり、i番目の品物はa[i]個あります。異なる種類の品物同士は区別できますが、同じ種類の品物同士は区別できません。
// これらの品物の中からm個選ぶ組み合わせの総数を求め、Mで割った余りを答えなさい。
// 制約: 1 <= n <= 1000, 1 <= m <= 1000, 1 <= a[i] <= 1000, 2 <= M <= 10000

// 入力例: n = 3, m = 3, a = {1, 2, 3}, M = 10000
// 出力例: 6(0+0+3, 0+1+2, 0+2+1, 1+0+2, 1+1+1, 1+2+0)

#include <iostream>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;
int n;
int m;
int M;
int a[MAX_N];
int dp[MAX_M+1];

void read() {
  printf("n is >> "); scanf("%d", &n);
  printf("m is >> "); scanf("%d", &m);
  printf("a are >> \n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  printf("M is >> "); scanf("%d", &M);
}

int solve() {
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      if (j == 0) dp[j] = 1;
      else if (a[i] < j) dp[j] = dp[j-1] - 1;
      else dp[j] = dp[j] + dp[j - 1];
    }
  }
  return dp[m] % M;
}

int main() {
  read();
  printf("result >> %d\n", solve());
  return 0;
}
