// n個の互いに区別できない品物を、m個以下に分割する方法の総数を求め、Mで割った余りを答えなさい。
// 制約: 1 <= m <= n <= 1000, 2 <= M <= 10000
// 入力例: n = 4, m = 3, M = 10000
// 出力例: 4 (1+1+2=1+3=2+2=4)

#include <iostream>
using namespace std;

const int MAX_N = 1000;
int n;
int m;
int M;

void read() {
  printf("n is >> "); scanf("%d", &n);
  printf("m is >> "); scanf("%d", &m);
  printf("M is >> "); scanf("%d", &M);    
}

void print_table();

// dp[i] := n個の品物をi+1個に分割する方法の総数。
int dp[MAX_N];
int solve() {
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      if (j != 0 &&  i % (j + 1) == 0) dp[j] = dp[j] + 1;
    }
    print_table();
  }

  int rec = 0;
  for (int i = 0; i < m; i++) rec += dp[i];
  return rec % M;
}

#define DEBUG 1
#if DEBUG
void print_table() {
  for (int i = 0; i < m; i++) printf("%2d ", dp[i]);
  putchar('\n');
}
#endif

int main() {
  read();
  printf("%d\n", solve());
  return 0;
}
