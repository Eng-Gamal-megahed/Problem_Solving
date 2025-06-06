// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/Rilx5irOux/contest/526482/problem/H
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
ifstream infile("shift.in");

ll shift(ll x)
{
    return x * (x + 1) / 2;
}

void solve() {
    ll n , q;
    infile >> n;
    vector<ll>a(n);
    for (ll i = 0; i < n; ++i) {
        infile >> a[i];
    }
    infile >> q;
    while (q--)
    {
        ll k;
        infile >> k;
        ll shifts = shift((k - 1) / n);
        cout << a[(shifts % n + k - 1) % n] << nl;
    }
}
void file()
{
//#ifndef ONLINE_JUDGE
//    freopen("Input.txt", "r", stdin);
//    freopen("Output.txt", "w", stdout);
//    freopen("Error.txt", "w", stderr);
//#endif
}

int main() {
    file();
    ENG_GAMAL
// test-independent code ——————————————————————
// ————————————————————————————————————————————
    ll t = 1;
    infile >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}