// n個の仕事があります。各仕事は時間Siにはじまり、時間Tiに終わります。あなたは各仕事について、参加するかしないかを選ばなければなりません。
// 仕事に参加するならば、その仕事のはじめから終わりまで参加しなければなりません。また、参加する仕事の時間帯が重なってはなりません
// (開始の瞬間・終了の瞬間だけが重なるのも許されません)。できるだけ多くの仕事に参加したいです。何個の仕事に参加することができるでしょうか。
// 制約: 1 <= n <= 10^5, 1 <= Si < Ti <= 10^9

// 入力例: n = 5, s = {1, 2, 4, 6, 8} t = {3, 5, 7, 9 ,10}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_N = 100000;
int n;
int S[MAX_N];
int T[MAX_N];
pair<int, int> works[MAX_N]; // firstに終了時刻、secondに開始時刻を格納

void read() {
  printf("n is >> ");
  scanf("%d", &n);
  printf("(start), (end) >> \n");
  for (int i = 0; i < n; i++) {
    int start, end;
    scanf("%d, %d", &start, &end);
    works[i].first = end;
    works[i].second = start;
  }
  sort(works, works + n);
}

int solve() {
  int current, result = 0;
  for (int i = 0; i < n; i++) {
    if (works[i].second > current) {
      current = works[i].first;
      result++;
    }
  }
  return result;
}

int main () {
  read();
  cout << solve() << endl;
}
