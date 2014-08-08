// トラックで距離Lの道を移動します。はじめトラックにはガソリンがP積まれています。このトラックは距離1走るとガソリンが1消費されます。
// 途中でガソリンが0になってしますとトラックは停止してしまい、移動に失敗してしまいます。途中にはN個ガソリンスタンドがあります。
// 各ガソリンスタンドiは道のスタート地点から距離A[i]の地点にあって、B[i]だけガソリンを補給することができます。
// トラックの燃料タンクの容量には制限はなく、いくらでもガソリンを補給することができます。トラックは移動を完了できるでしょうか？
// またその際、最小で何回のガソリンの補給が必要でしょうか？完了できる場合は最小の補給回数を、できない場合は-1を出力してください。
// 制約: 1 <= N <= 10^4, 1 <= L <= 10^6, 1 <= P <= 10^6, 1 <= A[i] <= L, 1 <= B[i] <= 100

// 入力例: N = 4, L = 25, P = 10, A = {10, 14, 20, 21}, B = {10, 5, 2, 4}
// 出力例: 2(1つめと2つめのガソリンスタンドで補給)


#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 10^4;
int N;
int L;
int P;
// ゴール地点を距離L、供給量0のガソリンスタンドとする。
int A[MAX_N + 1];
int B[MAX_N + 1];



void read() {
  printf("N is >> "); scanf("%d", &N);
  printf("L is >> "); scanf("%d", &L);
  printf("P is >> "); scanf("%d", &P);

  printf("A are >> \n");
  for (int i = 0; i < N; i++)
    scanf("%d", &A[i]);
  A[N] = L;

  printf("B are >> \n");
  for (int i = 0; i < N; i++)
    scanf("%d", &B[i]);
  B[N] = 0;
}

int solve() {
  int gas = P; // 補給したガソリンの総量。
  int res = 0;
  priority_queue<int> pque;
  for (int i = 0; i <= N; i++) {
    // i番目のガソリンスタンドに到達できるまで過去に遡って給油を行う。
    while (gas < A[i]) {
      if (pque.empty()) return -1; // これ以上補給できないので、到達不能。
      gas += pque.top(); // 補給回数を減らすため、供給量の多いスタンドから使用していく。
      pque.pop();
      res++; // 補給回数をインクリメント。
    }
    pque.push(B[i]); // 到達したガソリンスタンドの補給量を順位キューに追加。
  }
  return res;
}
int main() {
  read();
  printf("result is >> %d\n", solve());
  return 0;
}
