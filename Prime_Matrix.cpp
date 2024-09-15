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
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

const ll N = 1e6;
vector<bool> isPrime(N + 1, true);  // Initialize a boolean vector
vector<ll> primes;
void Sieve(ll n = N) {
    isPrime[0] = isPrime[1] = false;  // 0 and 1 are not primes

    for (ll i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                isPrime[j] = false;  // Mark multiples of i as non-prime
            }
        }
    }
    for (ll i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);  // Collect all prime numbers
        }
    }
}

void solve() {
    int n , m;
    cin >> n >> m;
    vector<vector<ll>>mat(n , vector<ll>(m)) , next_prime(n , vector<ll>(m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> mat[i][j];
            next_prime[i][j] = *lower_bound(all(primes) , mat[i][j]) - mat[i][j];
        }
    }
    ll ans = LLONG_MAX;
    for (ll i = 0; i < n; ++i) {
        ll temp_ans = 0;
        for (ll j = 0; j < m; ++j) {
            temp_ans += next_prime[i][j];
        }
        ans = min(ans , temp_ans);
    }
    for (ll i = 0; i < m; ++i) {
        ll temp_ans = 0;
        for (ll j = 0; j < n; ++j) {
            temp_ans += next_prime[j][i];
        }
        ans = min(ans , temp_ans);
    }
    cout << ans << nl;
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
    Sieve();
// ————————————————————————————————————————————
    ll t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}