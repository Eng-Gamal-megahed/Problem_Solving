//
// DATE : Created by Gamal on 6/27/2024.
// LINK : https://vjudge.net/contest/589623#problem/J

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define f1(n) for(int i=1;i<n;i++)
#define f0(n) for(int i=0;i<n;++i)
#define fe(v) for(auto & it:v)
#define pi 3.141592653589793238462643383279502884197
#define e 2.718281828459045
using namespace std;
using namespace __gnu_pbds;
struct un_ordered
{
    bool operator()(const long long &a, const long long &b) const
    {
        return true;
    }
};
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;  // Use the GCD to calculate the LCM
}

template <class T>
using ordered_set = tree<T, null_type, un_ordered, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    ll n , c;
    cin >> n >> c;
    set<ll>stalls;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        stalls.insert(x);
    }
    ll l = 1 , r = *prev(stalls.end()) , ans = LLONG_MIN;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        auto it = stalls.begin();
        ll c_copy = c ;
        while (c_copy-- && it != stalls.end())
        {
            it = stalls.lower_bound(*it + mid);
        }
        if(c_copy == -1)
        {
            ans = max(ans,mid);
            l = mid + 1;
        }
        else
        {
            r = mid -1;
        }
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
void fast()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

}

int main() {
    fast();
    file();
    ll t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}