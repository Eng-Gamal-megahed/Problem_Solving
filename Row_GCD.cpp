#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n";
#define yes cout<<"YES\n";
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

/*
 ███████╗███╗   ██╗ ██████╗       ██████╗  █████╗ ███╗   ███╗ █████╗ ██╗
 ██╔════╝████╗  ██║██╔════╝      ██╔════╝ ██╔══██╗████╗ ████║██╔══██╗██║
 █████╗  ██╔██╗ ██║██║  ███╗     ██║  ███╗███████║██╔████╔██║███████║██║
 ██╔══╝  ██║╚██╗██║██║   ██║     ██║   ██║██╔══██║██║╚██╔╝██║██╔══██║██║
 ███████╗██║ ╚████║╚██████╔╝     ╚██████╔╝██║  ██║██║ ╚═╝ ██║██║  ██║███████╗
 ╚══════╝╚═╝  ╚═══╝ ╚═════╝       ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝
*/
template <typename T>
void get_vec(vector<T>& v) {
    for (ll i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
}
template <typename T>
void out_vec(vector<T>& v) {
    for (ll i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << nl;
}

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
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void solve() {
    ll n ,m;
    cin >> n >> m;
    vector<ll>a(n) , b(m);
    get_vec(a);
    get_vec(b);
    ll Gcd = gcd_Vector(a);
    for (ll i = 0; i < m; ++i)
    {
        ll ans = a[0] + b[i];
        for (ll j = 0; j < n && a[0] % 2 == a[j] % 2; ++j) {
            if(a[0] % 2 != a[j] % 2)
            {
                ans = gcd(ans, a[j] + b[i]);
            }
        }
        cout << ans << ' ';
    }
    cout << nl;
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
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}