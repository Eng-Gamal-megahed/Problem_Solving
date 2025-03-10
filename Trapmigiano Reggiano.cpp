// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2071/problem/C
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
const int N = 1e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
ll n , st , ed;
vector<vector<ll>>adj(N);
vector<ll>depth(N);

void dfs(ll v = ed , ll par = 0)
{
    depth[v] = depth[par] + 1;
    for(ll u : adj[v])
    {
        if(u == par)
            continue;
        dfs(u , v);
    }
}


void solve() {
    cin >> n >> st >> ed;
    for (ll i = 0; i <= n; ++i) {
        adj[i].clear();
        depth[i] = 0;
    }
    for (ll i = 0; i < n - 1; ++i) {
        ll a , b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs();
    vector<ll>ans(n);
    iota(all(ans) , 1);
    sort(all(ans) , [&](ll a , ll b){return depth[a] > depth[b];});
    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << sp;
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
     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}