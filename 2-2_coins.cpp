// 1円玉、5円玉、10円玉、100円玉、500円玉が、それぞれC1、C5、C10、C100、C500枚ずつあります。
// できるだけ少ない枚数の硬貨でA円を支払いたいと考えています。何枚の硬貨を出す必要があるでしょうか。
// なお、そのような支払い方は少なくとも1つは存在するとします。
// 制約: 0 <= C1、C5、C10、C100、C500 <= 10^9, 0 <= A <= 10^9

#include <iostream>
using namespace std;

const int coinTypes = 6;
int coins[coinTypes] = {1, 5, 10, 50, 100, 500};
int numOfCoins[coinTypes];
int results[coinTypes];
int price;

void read() {
  printf("Please input number of each coins. >> ");
  scanf("%d,%d,%d,%d,%d,%d", &numOfCoins[0], &numOfCoins[1], &numOfCoins[2], &numOfCoins[3], &numOfCoins[4], &numOfCoins[5]);
  printf("Please input total price. >> ");
  scanf("%d", &price);
}

void solve() {
  for (int i = coinTypes - 1; i >= 0; i--) {
    results[i] = min(price / coins[i], numOfCoins[i]);
    price -= coins[i] * results[i];
  }
}

void printResuls() {
  if (price != 0) { printf("There is no answer.\n");  return;}
  int total = 0;
  for (int i = coinTypes - 1; i >= 0; i--) {
    total += results[i];
    printf("%d x %d\n", coins[i], results[i]);
  }
  printf("Total number of coins are %d\n", total);
}

int main() {
  read();
  solve();
  printResuls();
  return 0;
}
