#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

string ans;

pair<int, int> move(int n, int A, int B) {
    if (A == 0) {
        for (int i = 0; i < n - 1; ++i)
            ans += "U";
    } else {
        for (int i = 0; i < n - 1; ++i)
            ans += "D";
    }
    if (B == 0) {
        for (int i = 0; i < n - 1; ++i)
            ans += "L";
    } else {
        for (int i = 0; i < n - 1; ++i)
            ans += "R";
    }
    pair<int, int> kek = {0, 0};
    if (A == 1)
        kek.first = n - 1;
    if (B == 1)
        kek.second = n - 1;
    return kek;
}

void solve() {
    ans = "";
    int n, a, b;
    cin >> n >> a >> b;
    --a;
    --b;
    int A = 0;
    if (a >= n / 2)
        A = 1;
    int B = 0;
    if (b >= n / 2)
        B = 1;
    pair<int, int> fin = move(n, A, B);
    while (fin.first > a) {
        ans += "U";
        fin.first--;
    }
    while (fin.first < a) {
        ans += "D";
        fin.first++;
    }
    while (fin.second > b) {
        ans += "L";
        fin.second--;
    }
    while (fin.second < b) {
        ans += "R";
        fin.second++;
    }
    cout << ans << "\n";
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
