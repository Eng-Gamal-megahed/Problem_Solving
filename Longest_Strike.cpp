//
// DATE : Created by Gamal on 6/11/2024.
// LINK : https://vjudge.net/contest/588093#problem/B

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
using namespace std;
using namespace __gnu_pbds;
struct un_ordered
{
    bool operator()(const long long &a, const long long &b) const
    {
        return true;
    }
};
template <class T>
using ordered_set = tree<T, null_type, un_ordered, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    ll n , k;
    cin >> n >> k;
    set<ll>s;
    map<ll,ll>freq;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        s.insert(x);
        freq[x]++;
    }
    ll l = 1, r = 0;
    bool found = false;
    for (auto i = s.begin(); i != s.end(); ++i) {
        if(freq[*i] >= k)
        {
            found = true;
            ll cur_l , cur_r , last = *i;
            cur_l = *i;
            while (freq[*i] >= k && i != s.end())
            {
                i++;
                if(*i - last != 1)
                {
                    break;
                }
                last = *i;
            }
            i--;
            cur_r = *i;
            if(cur_r - cur_l >= r - l)
            {
                l = cur_l;
                r = cur_r;
            }
        }
    }
    if(!found)
    {
        cout << -1 << nl;
        return;
    }
    cout << l << ' ' << r << nl;
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
    file();
    fast();
    ll t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
