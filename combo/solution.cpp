#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct DSU {
    int n;
    vector<int> par, val, l, r;
    DSU() {}
    DSU(int n, const vector<int> &a) { init(n, a); }
    void init(int _n, const vector<int> &a) {
        n = _n;
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        val = a;
        l.resize(n);
        iota(l.begin(), l.end(), 0);
        r.resize(n);
        iota(r.begin(), r.end(), 0);
    }
    int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
    int join(int x, int y) {
        int root_x = find(x), root_y = find(y);
        if (root_x == root_y)
            return 0;
        par[root_x] = root_y;
        val[root_y] &= val[root_x];
        l[root_y] = min(l[root_y], l[root_x]);
        r[root_y] = max(r[root_y], r[root_x]);
        return 1;
    }
    inline int get_left(int x) { return l[find(x)]; }
    inline int get_right(int x) { return r[find(x)]; }
    inline int get_val(int x) { return val[find(x)]; }
};

void init() {}

void solve(int tt = 0) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }

    DSU dsu(n, a);
    set<pair<int, int>> s;
    for (int i = 0; i < n - 1; i++) {
        s.insert({a[i] & a[i + 1], i});
    }

    ll ans = 0;
    for (int step = 0; step < n - 1; step++) {
        auto [val, x] = *s.rbegin();
        s.erase(prev(s.end()));
        ans += val;
        {
            int l = dsu.get_left(x) - 1;
            if (0 <= l) {
                s.erase({dsu.get_val(l) & dsu.get_val(x), l});
                s.insert({dsu.get_val(l) & val, l});
            }
        }
        {
            int r = dsu.get_right(x) + 1;
            if (r < n) {
                r = dsu.find(r);
                int rr = dsu.get_right(r) + 1;
                if (rr < n) {
                    s.erase({dsu.get_val(r) & dsu.get_val(rr), r});
                    s.insert({val & dsu.get_val(rr), r});
                }
            }
        }
        dsu.join(x, dsu.get_right(x) + 1);
    }
    cout << ans << endl;
}

void reset() {}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    init();
    for (int i = 1; i <= t; i++) {
        solve(i);
        reset();
    }
    return 0;
}
