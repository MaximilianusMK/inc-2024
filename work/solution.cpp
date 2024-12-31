#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    ll n, r, k;
    cin >> n >> r >> k;
    ll avg_r = r / n;
    ll avg_k = k / n;
    ll end_of_avg_r_plus_1 = r % n;
    ll start_of_avg_k_plus_1 = n - k % n;

    ll total = 0;
    // r: [0, a), [a, n)
    // k: [0, b), [b, n)
    // where a = r % n, and b = n - k % n

    // Case 1, where a <= b
    if (end_of_avg_r_plus_1 <= start_of_avg_k_plus_1) {
      // [0, a)
      total += (avg_r + 1) * avg_k * end_of_avg_r_plus_1;
      // [a, b)
      total += avg_r * avg_k * (start_of_avg_k_plus_1 - end_of_avg_r_plus_1);
      // [b, n)
      total += avg_r * (avg_k + 1) * (n - start_of_avg_k_plus_1);
    } else {
      // Case 2, where a > b
      // [0, b)
      total += (avg_r + 1) * avg_k * start_of_avg_k_plus_1;
      // [b, a)
      total += (avg_r + 1) * (avg_k + 1) * (end_of_avg_r_plus_1 - start_of_avg_k_plus_1);
      // [a, n)
      total += avg_r * (avg_k + 1) * (n - end_of_avg_r_plus_1);
    }

    cout << total << endl;
  }
}
