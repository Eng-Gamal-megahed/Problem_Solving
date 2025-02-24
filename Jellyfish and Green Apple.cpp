// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1875/C
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

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
ll gcd_Vector(const std::vector<ll>& nums) {
    ll result = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        result = gcd(result, nums[i]);
        if (result == 1) {
            return 1; // GCD is 1, no need to continue
        }
    }
    return result;
}
void solve() {
    ll n , m;
    cin >> n >> m;
    ll n_copy = n , m_copy = m;
    while (m % 2 == 0)
        m /= 2;
    while (n % 2 == 0)
        n /= 2;
    if(n % m)
        return void(cout << -1 << nl);
    double each = (double)n_copy / m_copy;
    each -= (ll)each;
//    cout << each << nl;
    ll ans = 0;
    for (ll i = 1; i <= 32; ++i) {
        each *= 2;
        ans += (ll)each * (powl(2 , i) - 1) * (m_copy / powl(2 , i));
        each -= (ll)each;
    }
    cout << ans << nl;
}

void good_solve()
{
    ll n , m;
    cin >> n >> m;
    n %= m;
    ll a = n / gcd(n , m) , b = m / gcd(n , m);
    if(__builtin_popcount(b) > 1)
        return void(cout << -1 << nl);
    cout << __builtin_popcount(a) * m - n << nl;
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
        good_solve();
    }

    return 0;
}