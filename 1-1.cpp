// あなたの友人は次のようなゲームをあなたに仕掛けてきました。数字が書かれたn枚の紙切れが袋に入っています。
// あなたはこの袋から紙切れを取り出し、数字を見て袋に戻すということを4回行い、4回の紙切れの数字の和がmになっていればあなたの勝ち
// そうでなければ友人の勝ちとなります。...紙切れに書かれている数字がk1,k2,...knであったとき、和がmになる取り出し方が存在するかどうかを計算し、
// 存在するならYes,存在しないならNoと出力する。
//
// 1 <= n <= 50
// 1 <= m <= 10^8
// 1 <= ki <= 10^8

#include <iostream>

int main() {
  int n, m;
  printf("紙の数:n 数字の和:m\n");
  scanf("%d,%d", &n, &m);
  
  int nums[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
  }

  bool success = false;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
          if ((nums[i] + nums[j] + nums[k] + nums[l]) == m) {
            success = true;
          }
        }
      }
    }
  }

  if (success) {
    printf("YES");
  } else {
    printf("NO");
  }

  return 0;
}
