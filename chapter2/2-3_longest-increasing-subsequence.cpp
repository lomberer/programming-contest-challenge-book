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
int dp[MAX_N + 1]; 

// O(n^2)
int solve1() {
  int res = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    res = max(res, dp[i]);
  }
  return res;
}


int main() {
  read();
  printf("result is >> %d\n", solve1());
  return 0;
}

