// 長さLcmの竿の上をn匹のアリが毎秒1cmのスピードで歩いています。アリが竿の端に到達すると竿の下に落ちていきます。
// また、竿の上は狭くてすれ違えないので、2匹のアリが出会うと、それぞれ反対を向いて戻っていきます。
// 各アリについて、現在の竿の左端からの距離xiはわかりますが、どちらの方向を向いているのかはわかりません。
// すべてのアリが竿から落ちるまでにかかる最小の時間と最大の時間を求めなさい。
// 制約: 1<= L <= 10^6, 1 <= n <= 10^6, 0 <= xi <= L
// 入力例: L = 10, n = 3, x = { 2, 6, 7 }
// 出力例: min = 4, max = 8

#include <iostream>

using namespace std;

int L;
int n;
int *x;

int minimum = 0;
int maximum = 0;

void read() {
  printf("L is ");
  scanf("%d", &L);

  printf("n is ");
  scanf("%d", &n);

  printf("x are \n");
  x = new int[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    int shortSide =  min(x[i], L - x[i]);
    minimum = max(minimum, shortSide);
  }

  for (int i = 0; i < n; i++) {
    int longSide = max(x[i], L - x[i]);
    maximum = max(maximum, longSide);
  }
}

void print() {
  printf("min = %d\n", minimum);
  printf("max = %d\n", maximum);
}

int main() {
  read();
  solve();
  print();
  delete[] x;
}

  
