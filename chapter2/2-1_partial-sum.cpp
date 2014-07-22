// 整数a[1], a[2], ... , a[n]が与えられます。その中からいくつか選び、その和をちょうどkにすることができるかを判定しなさい。
// 制約 1 <= n < 20, -10^8 <= a[i] <= 10^8, -10^8 <= k < 10^8
// 入力例: n = 4, a = { 1, 2, 4, 7 }, k = 13
// 出力例: Yes

#include <iostream>

int n;
int *a;
int k;

void read() {
  printf("n is ");
  scanf("%d", &n);
  
  printf("a are \n");
  a = new int[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  printf("k is ");
  scanf("%d", &k);
}

bool dfs(int depth, int sum) {
  if (depth == n) return sum == k;

  if (dfs(depth + 1, sum)) return true;

  if (dfs(depth + 1, sum + a[depth])) return true;

  return false;
}

void solve() {
  if (dfs(0, 0)) printf("Yes\n");
  else printf("No\n");
}

int main() {
  read();
  solve();
}
