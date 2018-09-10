#include <cstdio>

int n, used[15], perm[15];

void dfs(int cur) {
  if (cur == n) {
    for (int i = 0; i < n; i++) {
      printf("%d ", perm[i]);
    }
    puts("");
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      used[i] = 1;
      perm[cur] = i;
      dfs(cur+1);
      used[i] = 0;
    }
  }

}

int main() {
  scanf("%d", &n);
  dfs(0);
}
