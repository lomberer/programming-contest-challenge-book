// n種類の数aiがそれぞれmi個ずつあります。これらの中からいくつか選び、その総和をちょうどKとすることができるか判定しなさい。
// 制約: 1 <= n <= 100, 1 <= ai, mi <= 100000, 1 <= K <= 100000
// 入力例: n = 3, a = {3, 5, 8}, m = {3, 2, 2}, K = 17
// 出力例: Yes(3*3+8=17)

#include <iostream>
using namespace std;

const int N_MAX = 100;
int n;
int a[N_MAX];
int m[N_MAX];
int K;

void read() {
  printf("n is >> "); scanf("%d", &n);
  printf("a are >> \n");
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("m are >> \n");
  for (int i = 0; i < n; i++)
    scanf("%d", &m[i]);
  printf("K is >> "); scanf("%d", &K);
}

bool rec(int i, int k) {
  printf("%d, %d\n", i, k);
  bool ret;
  if (i == n) // iが範囲外
    ret = false;
  else if (m[i] < 0) // これ以上i番目の数を使用できない
    ret = false;
  else if (k > K) // 合計値がKを上回った
    ret = false;
  else if (k == K) // 解発見
    ret = true;
  else if (rec(i + 1, k)) // 次の数へ
    ret = true;
  else { // i番目の数を使用する
    --m[i]; // i番目の数の残数を減らす
    ret = rec(i, k + a[i]);
  }
  // 探索に失敗つまり、葉に到達したとき、使用したi番目の数を返却する。
  if (!ret) ++m[i];
  return ret;
}

bool solve() {
  return rec(0, 0);
}

int main() {
  read();
  solve() ? printf("YES") : printf("NO");
  putchar('\n');
  return 0;
}
