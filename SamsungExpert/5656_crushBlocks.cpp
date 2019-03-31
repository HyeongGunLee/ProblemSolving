#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, W = 0, H = 0;
int board[15][12];
int minBlock;

void initBoard() {
   for (int i = 0; i < 15; i++) {
      for (int j = 0; j < 12; j++) {
         board[i][j] = 0;
      }
   }
   minBlock = 987654321;
}

void printBoard() {
   for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
         cout << board[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl;
}

int calcRemained() {
   int remained = 0;
   //cout << "Calculating...." << endl;
   //printBoard();
   for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
         if (board[i][j] != 0) {
            remained++;
         }
      }
   }
   return remained;
}

bool canCrush(int col) {
   for (int i = 0; i < H; i++) {
      if (board[i][col] != 0) {
         return true;
      }
   }
   return false;
}

void bomb(int row, int col) {
   //cout << "Bomb!! => " << "row: " << row << ", col: " << col << endl;
   //printBoard();
   int bombLen = board[row][col];

   if (bombLen == 0) {
      return;
   }

   if (bombLen != 0) {
      board[row][col] = 0;
   }

   int temp = 0;

   // up
   while ((temp < bombLen) && ((row - temp) >= 0)) {
      bomb(row - temp, col);
      temp++;
   }

   // right
   temp = 0;
   while ((temp < bombLen) && ((col + temp) < W)) {
      bomb(row, col+temp);
      temp++;
   }

   // left
   temp = 0;
   while ((temp < bombLen) && ((col - temp) >= 0)) {
      bomb(row, col - temp);
      temp++;
   }
   
   // down
   temp = 0;
   while ((temp < bombLen) && ((row + temp) < H)) {
      bomb(row + temp, col);
      temp++;
   }
   return;
}

void cleanupBoard() {
   
   for (int i = 0; i < W; i++) {
      vector<int> temp;
      for (int j = 0; j < H; j++) {
         if (board[j][i] != 0) {
            temp.push_back(board[j][i]);
            board[j][i] = 0;
         }
      }

      int cur = H - 1;
      while (!temp.empty()) {
         board[cur][i] = temp.back();
         temp.pop_back();
         cur--;
      }
   }
}

void crush(int col) {
   for (int i = 0; i < H; i++) {
      if (board[i][col] != 0) {
         bomb(i, col);
         cleanupBoard();
         return;
      }
   }
}

void backupBlocks(int temp[15][12]) {
   for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
         board[i][j] = temp[i][j];
      }
   }
}

void crushBlocks(int n) {
   if (calcRemained() == 0) {
      minBlock = 0;
   }

   if (n == N) { // end of ball
      int blocks = calcRemained();
      minBlock = min(minBlock, blocks);
      return;
   }

   int tempBoard[15][12];
   for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
         tempBoard[i][j] = board[i][j];
      }
   }

   for (int i = 0; i < W; i++) {
      if (canCrush(i)) {
         //cout << "Crushed = " << i << endl;
         crush(i);
         //printBoard();
         crushBlocks(n + 1);
         backupBlocks(tempBoard);
      }
   }
}

int main(void) {
   cin >> T;
   for (int x = 0; x < T; x++) {
      cin >> N >> W >> H;
      initBoard();
      for (int i = 0; i < H; i++) {
         for (int j = 0; j < W; j++) {
            cin >> board[i][j];
         }
      }
      crushBlocks(0);
      cout << "#" << x + 1 << " " << minBlock << endl;
   }
   return 0;
}
