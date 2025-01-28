// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
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
    ll result = nums[1] - nums[0];
    for (size_t i = 2; i < nums.size(); ++i) {
        result = gcd(result, nums[i] - nums[0]);
        if (result == 1) {
            return 1;
        }
    }
    return result;
}

void solve() {
    ll n , m;
    cin >> n >> m;
    vector<ll>a(n) , b(m);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(all(a));
    ll Gcd;
    if(n == 1)
        Gcd = 0;
    else
        Gcd = gcd_Vector(a);
    for (ll i = 0; i < m; ++i) {
        cout << gcd(a[0] + b[i] ,Gcd) <<  sp;
    }
    return;

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
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}