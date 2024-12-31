#pragma GCC optimize "-O2"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 100005;
const int maxs = 200005;
const int mod  = 998244353;

int N, M;
int S[maxn];

int main(int argc, char *argv[]) {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; ++i)
    scanf("%d", &S[i]);

  int s_min = maxs+1;
  int s_max = 0;
  int flag[maxs] = {0};
  for (int i = 0; i < M; ++i) {
    ++flag[S[i]];
    s_min = min(s_min, S[i]);
    s_max = max(s_max, S[i]);
  }

  int p[maxs] = {0}; p[N] = 1;
  int sum = N == 1 ? 0 : 1;

  int ans = s_min >= N ? 1 : 0;

  for (int i = N+1; i <= s_max; ++i) {
    p[i] = sum;
    sum = (sum + p[i]) % mod;
    sum = (sum - p[i-N+1] + mod) % mod;
    for (int j = 0; j < flag[i]; ++j)
      ans = (ll)ans * p[i] % mod;
  }

  printf("%d\n", ans);

  return 0;
}
