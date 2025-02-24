// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://www.spoj.com/problems/MAKETREE/
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

int n , k;
vector<vector<int>>adj(N);
vector<bool>vis(N);
vector<int>ans;
void dfs(int v)
{
    vis[v] = true;
    for(int u : adj[v])
    {
        if(!vis[u])
            dfs(u);
    }
    ans.emplace_back(v);
}

void solve() {
    cin >> n >> k;
    for (ll i = 0; i < k; ++i) {
        int w;
        cin >> w;
        for (ll j = 0; j < w; ++j) {
            int b;
            cin >> b;
            adj[i + 1].emplace_back(b);
        }
    }

    for (ll i = 1; i <= n; ++i) {
        if(!vis[i])
            dfs(i);
    }
    reverse(all(ans));
    vector<int>boss(n + 1);
    boss[ans[0]] = 0;
    for (ll i = 1; i < n; ++i) {
        boss[ans[i]] = ans[i - 1];
    }
    for (ll i = 1; i <= n; ++i) {
        cout << boss[i] << nl;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}