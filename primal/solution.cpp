#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 2e5 + 1;
const int MAXLOG = log2(MAXN) - 1;

int fact[MAXN + 5], ifact[MAXN + 5];
int sz[MAXLOG + 5], heap[MAXLOG + 5];
int DP[MAXLOG + 5][MAXN + 5];

inline int mul(int x, int y) {
  return (1ll * x * y) % MOD; 
}

int power(int x, int y) {
  if (y == 0) return 1;
  if (y == 1) return x % MOD;
  int temp = power(x, y / 2);
  temp = mul(temp, temp);
  if (y & 1) return mul(temp, x);
  return temp;
}

inline int C(int n, int k) {
  if (k > n) return 0;
  int ans = fact[n];
  ans = mul(ans, ifact[k]);
  ans = mul(ans, ifact[n - k]);
  return ans;
}

void precompute() {
  fact[0] = 1;
  for (int i = 1; i <= MAXN; i++) fact[i] = mul(i, fact[i - 1]);
  ifact[MAXN] = power(fact[MAXN], MOD - 2);
  for (int i = MAXN - 1; i >= 0; i--) ifact[i] = mul(i + 1, ifact[i + 1]);
  heap[0] = 1; 
  sz[0] = 1;
  for (int i = 1; i <= MAXLOG; i++) {
    sz[i] = 2 * sz[i - 1] + 1;
    heap[i] = mul(C(sz[i] - 1, sz[i - 1]), mul(heap[i - 1], heap[i - 1]));
  }
}

int calc(int N, int S, int K) {
  int height = 0;
  while (sz[height] <= N) height++;
  if (K > height) return 0;

  int under[height + 1] = {0};
  under[0] = 0;
  vector<int> path(height + 1);
  for (int i = 0, idx = N + 1; i <= height; i++, idx /= 2) {
    path[i] = idx;
  }
  for (int i = 1; i <= height; i++) {
    under[i] = under[i - 1] + 1;
    if (path[i - 1] & 1) under[i] += sz[i - 1];
    else if (i >= 2) under[i] += sz[i - 2];
  }

  int ret = C(S - 1, under[K]);
  for (int i = 1; i <= height; i++) {
    if (path[i - 1] & 1) {
      ret = mul(ret, heap[i - 1]);
      if (i <= K) {
        ret = mul(ret, C(under[i] - 1, sz[i - 1]));
      }
    }
    else if (i >= 2) {
      ret = mul(ret, heap[i - 2]);
      if (i <= K) {
        ret = mul(ret, C(under[i] - 1, sz[i - 2]));
      }
    }
  }

  if (K != height) {
    DP[height][N + 1] = 1;
    for (int i = height - 1; i >= K + 1; i--) {
      int sum = 0;
      int other = sz[i - 1];
      if (path[i - 1] % 2 == 0) {
        if (i == 1) other = 0;
        else other = sz[i - 2];
      }
      int taken = under[i - 1] + 2;
      for (int j = N; j >= max(S + 1, under[i] + 1); j--) {
        sum += mul(DP[i + 1][max(j + 1, under[i + 1] + 1)], C(j - taken, other));
        sum %= MOD;
        DP[i][j] = sum;
      }
    }
    ret = mul(ret, DP[K + 1][max(S + 1, under[K + 1] + 1)]);
  }
  
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  precompute();
  int N, S, K;
  cin >> N >> S >> K;
  cout << calc(N, S, K) << endl;
  return 0;
}