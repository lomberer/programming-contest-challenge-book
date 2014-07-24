// 農夫ジョンは、フェンスを修理するため、とても長い板からN個の板を切り出そうとしています。切り出そうとしている板の長さは
// L1, L2,...,Lnであり、元の板の長さはちょうどこれの合計になっています。板を切断する際には、その板の長さの分だけのコストがかかります。
// 例えば、長さ21の板から長さ5, 8, 8の3つの板を切り出したいとします。長さ21の板を長さ13と8の板に切断すると、コストが21かかります。
// その13の板をさらに5と8に切断すると、コストが13かかります。合計で34のコストがかかります。最小で、どれだけのコストで全ての板を切り出すことができるでしょうか。
// 制約: 1 <= N <= 20000, 1 <= Li <= 50000

// 入力例: N = 3, L = {8, 5, 8}
// 出力例: 34

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> L;

// NとLを入力から初期化。
void read() {
  printf("N is >> "); scanf("%d", &N);
  printf("F are \n");
  for (int i = 0; i < N; i++) {
    int tmp;
    scanf("%d", &tmp);
    L.push_back(tmp);
  }
  cout << endl;
}

void print_L () {
  for (int i = 0; i < L.size(); i++) {
    cout << L[i] << endl;
  }
}

// Lを昇順にソート。
void _sort() {
  sort(L.begin(), L.end());
}

// Lの総和。
int total_length() {
  int res = 0;
  for (int i = 0; i < L.size(); i++) {
    res += L[i];
  }
  return res;
}

// 解。
int solve() {
  int res = 0;
  int total = total_length();
  while(L.size() > 1) {
    res += total;
    int max = L.back();
    L.pop_back();
    total -= max;
  }
  return res;
}

int main() {
  read();
  _sort();
  printf("%d\n", solve());
  return 0;
}

