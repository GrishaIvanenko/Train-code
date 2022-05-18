#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bool plus = false, minus = false;
    int minind = -1, maxind = -1;
    ll mn = 1e9 +1, mx = -1e9 - 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 0) {
            plus = true;
        }
        if ( a[i] <= 0 ) {
            minus = true;
        }
        if (a[i] < mn) {
            mn = a[i];
             minind = i;
        }
        if (a[i] > mx) {
            mx = a[i];
            maxind = i;
        }
    }
    if (plus && minus) {
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += abs(a[i]);
        }
        cout << ans << '\n';
        return;
    }
    if (plus) {
        ll ans = mn;
        int ind = (minind+1)%n;
        while (ans > 0 && ind != minind) {
            ans -= a[ind];
            ind = (ind+1)%n;
        }
        ans = abs(ans);
        while (ind != minind) {
            ans += a[ind];
            ind = (ind+1)%n;

        }
        cout << ans << '\n';
        return;
    }
    if (minus) {
        ll ans = mx;
        int ind = (maxind+1)%n;
        while (ans < 0 && ind != maxind) {
            ans -= a[ind];
            ind = (ind+1)%n;
        }
        while (ind != maxind) {
            ans -= a[ind];
            ind = (ind+1)%n;

        }
        cout << ans << '\n';
        return;
    }

}

int main() {
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
