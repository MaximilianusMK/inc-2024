#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  vector<int> diff;
  for (int i = 1; i < s.size();i++) {
    diff.push_back(((s[i] - s[i - 1]) % 3 + 3) % 3);
  }

  int parity = 0;
  for (int i = 0; i < diff.size(); i++) {
    int end = diff.size() - 1;
    if(diff[i] == 0) {
      // Count the number of consecutives zero.
      for (int j = i + 1; j < diff.size();j++) {
        if (diff[j] != 0) {
          end = j - 1;
          break;
        }
      }
      int move = end - i + 1;
      // The total allowed action is 'move - 1' times.
      parity = (parity + move - 1) % 2;
    } else {
      int sum = 0;
      // Count the number of non-consecutives zero.
      for (int j = i; j < diff.size(); j++) {
        if (diff[j] == 0) {
          end = j - 1;
          break;
        }
        sum += diff[j];
      }
      int move = end - i + 1;
      if(sum % 3) {
        // Ends with odd length.
        // If the move is even, then the parity will change.
        parity = (parity + 1 - (move % 2)) % 2;
      } else {
        // Ends with even length.
        // If the move is odd, then the parity will change.
        parity = (parity + move % 2) % 2;
      }

    }
    i = end;
  }

  if (parity) {
    cout << "Anda" << endl;
  } else {
    cout << "Kamu" << endl;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tc;
  cin >> tc;
  while(tc--) {
    solve();
  }
}
