// n本の棒があります。棒iの長さはaiです。あなたは、それらの棒から3本を選んでできるだけ周囲の長い三角形を作ろうと考えています。
// 最大の周長を求めなさい。ただし、三角形が作れない際には0を答えとしなさい。

// 制約: 3 <= n <= 100, 1 <= ai <= 10^6

// 入力例: n = 5, a = {2, 3, 4, 5, 10}
// 出力例:12

#include <iostream>
#include <time.h>
using namespace std;

int n;
int *a;
int m;

#define MAX2(a, b) ((a > b) ? a : b)
#define MAX3(a, b, c) ((c > MAX2(a, b)) ? c : MAX2(a, b))

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        int h = MAX3(a[i], a[j], a[k]);
        int o = 0;
        if (a[i] == h) { o = a[j] + a[k]; }
        else if (a[j] == h) { o = a[i] + a[k]; }
        else if (a[k] == h) { o = a[i] + a[j]; }

        if (o > h) {
          if (a[i] + a[j] + a[k] > m) {
            m = a[i] + a[j] + a[k];
          }
        }
      }
    }
  }
}

int main() {
  printf("n is \n");
  scanf("%d", &n);
  a = new int[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  solve();

  delete[] a;

  printf("%d", m);
}


