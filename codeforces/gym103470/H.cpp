#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int long long

void dfs(vector<set<int>> &gr, vector<bool>&used, int v, vector<int> &tops){
    used[v]= true;
    for (auto u:gr[v]){
        if (!used[u]) {
            gr[u].erase(v);
            dfs(gr, used, u, tops);
        }
    }
    tops.push_back(v);
}


void solve() {
    vector<set<int>> gr;
    vector<ll> a, t;
    int n;

    gr.clear();
    cin >> n;

    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    t.resize(n);
    for (int i = 0; i < n; ++i) cin >> t[i];

    vector<int> tops;

    gr.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y; cin >> x >> y;
        --x, --y;
        gr[x].insert(y);
        gr[y].insert(x);
    }
    vector<bool>used(n, false);
    vector<ll> dp(n, INT_MIN);

    dfs(gr, used, 0, tops);
    vector<int> child_sum(n, 0);

    for (auto &i : tops) {

        ll tmp1 = 0;
        ll mx = 0;
        ll a_mx = 0;
        for (auto &u : gr[i]) {
            tmp1 += dp[u] - a[u];
            if (a[u] > mx) {
                mx = a[u];
                //a_mx = a[u];
            }
        }

        vector<pair<int, int>> kids;
        map<int, int> dp_a;
        int sum228 = 0;
        for (auto &kid : gr[i]) {
            if (t[kid] == 3)
                kids.push_back({a[kid], kid});
            dp_a[kid] = dp[kid] - a[kid];
            sum228 += dp_a[kid];
        }
        sort(kids.begin(), kids.end());

        for (auto &ch : gr[i]) {
            int tmp2 = 0;
            for (auto &kid : gr[ch])
                tmp2 += dp[kid] - a[kid];
            tmp2 += a[ch];
            tmp2 += a[i];
            if (kids.size()) {
                int toto = kids.back().second;
                if (toto == ch) {
                    if (kids.size() == 1)
                        toto = -1;
                    else
                        toto = kids[kids.size() - 2].second;
                }
                if (toto != -1) {
                    tmp2 += a[toto];
                    tmp2 += sum228 - dp_a[ch];
                    dp[i] = max(dp[i], tmp2);
                }
                //берем макс дп
                //tmp += то дп + сумма по остальным dp[v] - a[v]
            }

        }

        /*mx = -1;
        int idx_max = -1;
        for (auto &u : gr[i]) {
            if (t[u] == 3 && dp[u] > mx) {
                mx = dp[u];
                idx_max = u;
            }
        }

        if (idx_max != -1) {

            /*mx = 0;
            int idx2_max = -1;
            for (auto &u : gr[i]) {
                if (u != idx_max) {
                    int tmp = a[u];
                    for (auto &v : gr[u]) {
                        tmp += dp[v] - a[v];
                    }
                    if (tmp > mx) {
                        mx = tmp;
                        idx2_max = u;
                    }
                }
            }

            tmp1 += mx;

            for (auto &u : gr[i]) {
                if (u != idx_max && u != idx2_max) {
                    tmp1 += dp[u] - a[u];
                }
            }
        }*/
        dp[i] = max(tmp1 + a[i] + mx, dp[i]);
        //cout << i << " " << dp[i] << " " << tmp1 + a[i] + mx << endl;
    }

    cout << dp[0] << endl;
}


signed main() {
#ifdef LOCAL
    freopen("../main/input.txt", "r", stdin);
#else
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
#endif
    int t = 1; cin >> t;
    while (t--)
        solve();
    return 0;
}
