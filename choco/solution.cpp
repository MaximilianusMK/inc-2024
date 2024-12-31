#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  unordered_map<int, int> sum_count;
  int last_sum = -1;
  for (int i = 0; i < n - 1; i++) {
    int sum = v[i] + v[i + 1];
    if (sum == last_sum) {
      last_sum = -1;
    } else {
      sum_count[sum]++;
      last_sum = sum;
    }
  }

  int answer = 0;
  for (pair<int, int> p : sum_count) {
    answer = max(answer, p.second);
  }
  cout << answer << endl;

  return 0;
}