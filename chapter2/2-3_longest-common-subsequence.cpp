// 2つの文字列s1, s2...snとt1, t2...tmが与えられます。これら2つの共通部分文字列の長さの最大値を求めなさい。
// ただし、文字列s1, s2...sの部分文字列とは、si1, si2...sim(i1 < i2 < ... < im)と表すことのできる文字列のことをいいます。
// 制約: 1 <= n, m <= 1000
// 入力例: n = 4, m = 4, s = "abcd", t = "becd"
// 出力例: 3 ("bcd")

#include <iostream>
#include <string>

using namespace std;

const int MAX_N_AND_M = 1000;
int n;
int m;
char s[MAX_N_AND_M];
char t[MAX_N_AND_M];
int dp[MAX_N_AND_M + 1][MAX_N_AND_M + 1];


void read () {
  printf("n is >> "); scanf("%d", &n);
  printf("m is >> "); scanf("%d", &m);
  printf("s are >> \n");
  for (int i = 0; i < n; i++) {
    scanf("%s", &s[i]);
  }
  printf("t are >> \n");
  for (int i = 0; i < m; i++) {
    scanf("%s", &t[i]);
  }  
}

int solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i] == t[j]) {
        dp[i+1][j+1] = dp[i][j] + 1;
      } else {
        dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
      }
    }
  }
  return dp[n][m];
}


int main () {
  read();
  printf("%d\n", solve());
  return 0;
}
