// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2021/C2
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    ll n , m , q;
    cin >> n >> m >> q;
    vector<ll>a(n) , b(m);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < m; ++i) {
        cin >> b[i];
    }
    vector<int>free(n + 1 , inf);
    int idx = 0;
    bool valid = true;
    for (ll i = 0; i < m; ++i) {
        if(free[b[i]] != inf)
            continue;
        if(b[i] == a[idx])
        {
            free[b[i]] = i + 1;
            idx++;
        }
        else
        {
            valid = false;
            break;
        }
    }
    cout << (valid ? "YA" : "TIDAK") << nl;
    for (ll i = 0; i < q; ++i) {
        ll s , t;
        cin >> s >> t;
        b[s - 1] = t;
        if(b[s-1] == t)
        {
            cout << (valid ? "YA" : "TIDAK") << nl;
        }
        else
        {
            free = vector<int>(n + 1 , inf);
            idx = 0;
            valid = true;
            for (ll i = 0; i < m; ++i) {
                if(free[b[i]] != inf)
                    continue;
                if(b[i] == a[idx])
                {
                    free[b[i]] = i + 1;
                    idx++;
                }
                else
                {
                    valid = false;
                    break;
                }
            }
            cout << (valid ? "YA" : "TIDAK") << nl;
        }
    }

}
void file()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
}

int main() {
    file();
    ENG_GAMAL
// test-independent code ——————————————————————
// ————————————————————————————————————————————
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}