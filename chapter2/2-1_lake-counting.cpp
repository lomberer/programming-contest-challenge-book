// 大きさがNxMの庭があります。そこに雨が振り、水溜りができました。水溜りは8近傍で隣接している場合に繋がっているとみなします。
// 全部でいくつの水溜りがあるでしょうか?
// 制約: N, M <= 100

#include <iostream>
#include <time.h>
#include <stdlib.h>

int N;
int M;
char **garden;

int numOfLake;

void read() {
  printf("N and M are >>");
  scanf("%d, %d", &N, &M);
}

void generate() {
  srand(time(NULL));
  garden = new char*[N];
  for(int i = 0; i < N; i++) {
    garden[i] = new char[M];
    for(int j = 0; j < M; j++) {
      garden[i][j] = rand() % 2 ? 'W' : '.';
    }
  }
}

void printGardern() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      putchar(garden[i][j]);
    }
    putchar('\n');
  }
}

void dfs(int x, int y, int depth) {
  // out of range.
  if (y < 0 || y >= N) return;
  if (x < 0 || x >= M) return;

  if (garden[y][x] == 'W') {
    if (depth == 0) numOfLake++; // はじめてWを発見した場合。
    garden[y][x] = '.'; // 探索済みの箇所は.に置き換える。
    dfs(x - 1, y - 1, depth + 1); // upper left
    dfs(x, y - 1, depth + 1); // up
    dfs(x + 1, y - 1, depth + 1); // upper right
    dfs(x - 1, y, depth + 1); // left
    dfs(x + 1, y, depth + 1); // right
    dfs(x - 1, y + 1, depth + 1); // lower left
    dfs(x, y + 1, depth + 1); // down
    dfs(x + 1, y + 1, depth + 1); // lower right;
  }
}

void solve() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      dfs(j, i, 0);
    }
  }
}

int main() {
  read();
  generate();
  printGardern();
  solve();
  printf("result is %d\n", numOfLake);
}
