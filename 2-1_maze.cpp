// 大きさNxMの迷路が与えられています。迷路は通路と壁からできており、1ターンに隣接する上下左右4マスの通路へ移動することができます。
// スタートからゴールまで移動するのに必要な最小ターン数を求めなさい。ただし、スタートからゴールまで移動できると仮定します。

#include <iostream>
#include <queue>

const int MAX_N = 100;
const int MAX_M = 100;
const int INF = 100000000;

using namespace std;

// 迷路データ
char * mazeMap =
 (char *)"\
#S######.#\
......#..#\
.#.##.##.#\
.#........\
##.##.####\
....#....#\
.#######.#\
....#.....\
.####.###.\
....#...G#\
";

int N = 10; // 迷路のy方向の長さ
int M = 10; // 迷路のx方向の長さ

// スタート地点
int sx = 1, sy = 0;

// ゴール地点
int gx = 8, gy = 9;

// パース済みの迷路
char parsedMap[MAX_N][MAX_M];

// 各点へのスタート地点からの距離。
int d[MAX_N][MAX_M]; 

void parseMap() {
  int pos = 0;
  int x, y;
  while(mazeMap[pos] != '\0') {
    x = pos % M;
    y = pos / M;
    parsedMap[y][x] = mazeMap[pos];
    pos++;
  }
}

// 距離をINFで初期化(到達不能点はINFのままとなる)
void setupDistance() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      d[i][j] = INF;
    }
  }
}

// DEBUG
void printParsedMap() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      putchar(parsedMap[i][j]);
    }
    putchar('\n');
  }
}

typedef pair<int, int> P;

int bfs() {
  queue<P> que;
  // スタート地点をキューにpush
  que.push(P(sx, sy));
  // スタート地点の距離を0に
  d[sy][sx] = 0;

  // queが空になるまで
  while(!que.empty()) {
    P p = que.front(); que.pop();

    // 上下左右を探索
    for(int dx = -1; dx <= 1; dx++) {
      for(int dy = -1; dy <= 1; dy++) {

        // 上下左右でない。
        if( (abs(dx) + abs(dy)) != 1 ) continue;
        
        int nx = p.first + dx; int ny = p.second + dy;
        
        // 範囲外
        if(nx < 0 || nx >= M) continue;
        if(ny < 0 || ny >= N) continue;
        
        // 壁
        if(parsedMap[ny][nx] == '#') continue;

        // 探索済み
        if(d[ny][nx] != INF) continue;

        // 新たに発見した地点の距離を記録
        d[ny][nx] = d[p.second][p.first] + 1;

        // キューへ追加
        que.push(P(nx, ny));
      }
    }
  }

  // 全経路の探索終了後、ゴール地点の距離を返却。
  return d[gy][gx];
}

void solve() {
  printf("%d\n",bfs());
}

int main() {
  parseMap();
  printParsedMap();
  setupDistance();
  solve();
}
