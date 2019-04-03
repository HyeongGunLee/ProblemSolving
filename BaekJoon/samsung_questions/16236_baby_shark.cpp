#:wqinclude <iostream>
#include <queue>
#include <vector>
using namespace std;


struct shark {
   int row, col;
   int age;
   int fish_cnt;
};



struct iPair {
   int r, c, d;
   iPair(int r, int c, int d) : r(r), c(c), d(d) {}
};


int N;
int board[20][20];
int visited[20][20] = { 0, };
int direction[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
shark babyShark;
vector<iPair> fishList;
vector<iPair> rowList;

bool noFish() {
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         if (board[i][j] != 0 && board[i][j] != 9) {
            return false;
         }
      }
   }
   return true;
}

bool canMove(int r, int c) {
   if (r >= 0 && r < N && c >= 0 && c < N && board[r][c] <= babyShark.age) {
      return true;
   }
   return false;
}

bool canEat(iPair temp) {
   if (board[temp.r][temp.c] < babyShark.age && board[temp.r][temp.c] != 0 && board[temp.r][temp.c] != 9) {
      return true;
   }
   return false;
}

void eatFish(iPair temp) {
   // set sharkPosition to 0 and 9
   // increase age & fish cnt
   board[temp.r][temp.c] = 9;
   board[babyShark.row][babyShark.col] = 0;
   babyShark.row = temp.r;
   babyShark.col = temp.c;
   babyShark.fish_cnt += 1;
   if (babyShark.fish_cnt == babyShark.age) {
      babyShark.age += 1;
      babyShark.fish_cnt = 0;
   }
}

void initVisited() {
   for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 20; j++) {
         visited[i][j] = 0;
      }
   }
}

void printBoard() {
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         cout << board[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl;
}

iPair getNearestFish(iPair temp, queue<iPair>& q) {
   fishList.clear();
   rowList.clear();
   int highestRow = temp.r;
   fishList.push_back(temp);
   while (!q.empty()) {
      iPair front = q.front();
      q.pop();
      if (front.d == temp.d && canEat(front)) {
         fishList.push_back(front);
         highestRow = min(highestRow, front.r);
      }
   }


   for (int i = 0; i < fishList.size(); i++) {
      if (fishList[i].r == highestRow) {
         rowList.push_back(fishList[i]);
      }
   }

   /*
   for (int i = 0; i < rowList.size(); i++) {
      cout << "rowList " << i << ": " << rowList[i].r << rowList[i].c << rowList[i].d << endl;
   }
   */

   int fishIdx = 0;
   if (rowList.size() == 1) {
      return rowList[0];
   }
   else {
      int minCol = 21;
      for (int i = 0; i < rowList.size(); i++) {
         if (rowList[i].c < minCol) {
            minCol = rowList[i].c;
            fishIdx = i;
         }
      }
   }
   //cout << "rowList[fishIdx] " << fishIdx << ": " << rowList[fishIdx].r << rowList[fishIdx].c << rowList[fishIdx].d << endl;
   return rowList[fishIdx];
}

int catchFish() {
   int time = 0;
   queue<iPair> q;
   iPair temp(babyShark.row, babyShark.col, 0);
   q.push(temp);
   visited[babyShark.row][babyShark.col] = 1;

   while (!q.empty()) {
      temp = q.front();
      q.pop();
      visited[temp.r][temp.c] = 1;
      if (canEat(temp)) {
         // add a logic to check highest && leftmost
         temp = getNearestFish(temp, q);
         eatFish(temp); //set shartPos (9 & 0 )
         //cout << "#######Eat Fish - (row:" << temp.r << ", col:" << temp.c << ", dis:" << temp.d << ")" << endl;
         //cout << "#######Shark Age: " << babyShark.age << "  Count: " << babyShark.fish_cnt << endl;
         //printBoard();
         initVisited();
         while (!q.empty()) {
            q.pop();
         }
         q.push(iPair(babyShark.row, babyShark.col, 0));
         time += temp.d;
         continue;
      }
      else {
         for (int i = 0; i < 4; i++) {
            int nr = temp.r + direction[i][0];
            int nc = temp.c + direction[i][1];
            if (canMove(nr, nc) && !visited[nr][nc]) {
               q.push(iPair(nr, nc, temp.d + 1));
               visited[nr][nc] = 1;
            }
         }
      }

   }
   return time;
}

int main(void) {
   cin >> N;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         cin >> board[i][j];
         if (board[i][j] == 9) {
            babyShark.age = 2;
            babyShark.row = i;
            babyShark.col = j;
            babyShark.fish_cnt = 0;
         }
      }
   }
   cout << catchFish() << endl;
}
