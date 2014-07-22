// N個の点が直線上にあります。点iの位置はXiです。N個のうちいくつかの点を選び、それらの点に印を付けます。
// N個のすべての点について、距離がR以内の場所に印を付けられた点がなければなりません
// (自分に印が付いていれば、距離が0のところにあると考えます)。条件を満たすようにしながら、
// できるだけ印を付ける点を少なくしたいです。何個の点に印を付ける必要があるでしょうか。
// 制約: 1 <= N <= 1000, 0 <= R <= 1000, 0 <= Xi <= 1000

// 入力例: N = 6, R = 10, X = {1, 7, 15, 20, 30, 50}
// 出力例: 3

#include <iostream>
using namespace std;

const int MAX_N = 1000;
int N;
int R;
int X[MAX_N];
int flags[MAX_N]; // チェック済みかどうかを管理。
int res = 0;

void read() {
  cout << "N is ";
  cin >> N;
  cout << "R is ";
  cin >> R;
  cout << "X are" << endl;
  for (int i = 0; i < N; i++) {
    scanf("%d", &X[i]);
  }
}

// aがbの範囲内にあるか。
bool within(int a, int b) {
  return (X[b] - R <= X[a] && X[a] <= X[b] + R);
}

// aをチェック。範囲内の箇所もチェックされる。
void check(int a) {
  cout << "check " << a << endl;
  for (int i = a, j = a+1; (i >= 0 || j < N); i--, j++) {
    if (within(i, a)) {
      flags[i] = 1;
    } 
    if (within(j, a)) {
      flags[j] = 1;
    }
  }
  res++;
}

void printFlags() {
  for (int i = 0; i < N; i++) {
    cout << flags[i];
  }
  cout << endl;
}

void solve() {
  for (int i = 0; i < N - 1; i++) {
    if (flags[i] == 1) { continue; } // チェック済み
    
    bool needCheck = false;
    for (int j = i; j >= 0; j--) {
      // 次の点をチェックしても全ての点がチェック済みにならない場合は、チェックする。
      if (within(j, i+1) || flags[j] == 1) { continue; }
      else {
        needCheck = true; break;
      }          
    }
    
    if (needCheck) {
      check(i);
      printFlags();
    }
  }
  
  // 最後の点がチェック済みでなければチェックする。
  if (!flags[N-1]) {
    check(N-1);
    printFlags();
  }
}

int main() {
  read();
  solve();
  cout << res << endl;
  return 0;
}
