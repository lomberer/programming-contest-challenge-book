// N文字の文字列Sが与えられ、N文字の文字列Tを作ります。はじめTは長さ0の文字列で、次のいずれかの操作が行えます。
// ・Sの先頭の一文字削除し、Tの末尾に追加する。
// ・Sの末尾を一文字削除し、Tの末尾に追加する。
// 辞書順比較でできるだけ小さくなるようTを作ってください。
// 制約: 1 <= N <= 2000, 文字列Sに含まれるのはローマ字の大文字のみ。

#include <iostream>
using namespace std;

const int MAX_N = 2000;
int n;
char S[MAX_N];
char T[MAX_N];

void read() {
  printf("N is >> ");
  scanf("%d", &n);
  printf("S is >> ");
  scanf("%s",S);
}

void solve() {
  for (int i = 0, j = n - 1; i < j;) {
    bool left = true;

    for (int l = i, r = j; l < r; l++, r--) {
      if (S[l] < S[r]) break; // 左が小さい
      if (S[l] > S[r]) { // 右が小さい
        left = false; break;
      }
      // 左と右が同じ場合は次の文字を再帰的に比較
    }

    // iとjから今ループ何週目かを算出
    int count = i + n - 1 - j;
    if (left) { // 左を選択
      T[count] = S[i];
      i++;      
    } else { // 右を選択
      T[count] = S[j];
      j--;
    }
  }
}

int main() {
  read();
  solve();
  cout << T << endl;
}
