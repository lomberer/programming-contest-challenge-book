// 長さnの数列a[0], a[1],...,a[n-1]があります。この数列の増加部分列のうち、最長のものの長さを求めなさい。
// ただし、増加部分列とは、すべてのi < jでa[i] < a[j]を満たす部分列のことを言います。
// 制約: a <= n <= 1000, 0 <= a[i] <= 10^6

// 入力例: n = 5, a = {4, 2, 3, 1, 5}
// 出力例: 3(a[1], a[2], a[4])

#include <iostream>
using namespace std;

const int MAX_N = 1000;
int n;
int a[MAX_N];

void read() {
  printf("n is >> "); scanf("%d", &n);
  printf("a are >> \n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
}

// dp[i] := a[i]が最後になるような増加部分列の長さ
int dp1[MAX_N + 1]; 

// O(n^2)
int solve1() {
  int res = 0;
  for (int i = 0; i < n; i++) {
    dp1[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j]) {
        dp1[i] = max(dp1[i], dp1[j] + 1);
      }
    }
    res = max(res, dp1[i]);
  }
  return res;
}

// dp[i] := 長さi+1の増加部分列の最終要素の最小値(存在しない場合はINF)
int dp2[MAX_N + 1];
const int INF = 10^7;
// O(n^2)
int solve2() {
  fill(dp2, dp2 + MAX_N + 1, INF);
  dp2[0] = a[0];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || dp2[j - 1] < a[i]) {
        dp2[j] = min(dp2[j], a[i]);
      }
    }
  }
  int rec = 0;
  for (int i = 0; i < MAX_N + 1; i++) {
    if (dp2[i] == INF) break;
    rec++;
  }
  return rec;
}

int dp3[MAX_N];

// O(n log n)
int solve3() {
  fill(dp3, dp3 + n, INF);
  for (int i = 0; i < n; i++) {
    *lower_bound(dp3, dp3 + n, a[i]) = a[i];
  }
  return lower_bound(dp3, dp3 + n, INF) - dp3;
}

int main() {
  read();
  //  printf("result is >> %d\n", solve1());
  // printf("result is >> %d\n", solve2());
  printf("result is >> %d\n", solve3());
  return 0;
}

