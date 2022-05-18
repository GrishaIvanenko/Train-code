#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, vector<int>> mm;
    for (int i= 0; i < n; ++i) {
        int x;
        cin >> x;
        mm[x].push_back(i);
    }
    int ans = 0;
    for (auto x : mm) {
        int A228 = x.second.size();
        ans = max(ans, A228);
        if (k == 0)
            continue;
        if (mm.find(x.first - k) != mm.end()) {
            vector<pair<int, int>> comm;
            for (auto y : x.second)
                comm.push_back({y, -1});
            for (auto y : mm[x.first - k])
                comm.push_back({y, 1});
            sort(comm.begin(), comm.end());
            vector<int> pref = {0};
            for (auto y : comm) {
                int nw = pref.back() + y.second;
                pref.push_back(nw);
            }
            int mn = 0;
            for (auto y : pref) {
                ans = max(ans, A228 + y - mn);
                mn = min(mn, y);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
#ifdef LOCAL
    freopen("../main/input.txt", "r", stdin);
#else
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
#endif
    int t = 1; //cin >> t;
    while (t--)
        solve();
    return 0;
}
