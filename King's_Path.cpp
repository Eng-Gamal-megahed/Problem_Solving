// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/242/C
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

int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
char di[] = {'U', 'R', 'D', 'L'};
int knightx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int knighty[] = {1, 2, 2, 1, -1, -2, -2, -1};

ll x , y , X , Y;

map<pair<ll , ll> , bool>allowable;
map<pair<ll , ll> , ll>dis;

bool valid(int nx , int ny)
{
    return nx >= 1 && nx < 1e9 && ny >= 1 && ny < 1e9 && allowable.find({nx , ny}) != allowable.end();
}

void bfs()
{
    queue<pair<ll , ll>>q;
    q.emplace(x , y);
    dis[{x , y}] = 0;

    while (!q.empty())
    {
        auto [a , b] = q.front();
        q.pop();

        for (ll i = 0; i < 8; ++i) {
            int nx = a + dx[i] , ny = b + dy[i];
            if(valid(nx , ny) && dis.find({nx , ny}) == dis.end())
            {
                dis[{nx , ny}] = dis[{a , b}] + 1;
                q.emplace(nx , ny);
                if(nx == X && ny == Y)
                    return;
            }
        }
    }
}

void solve() {
    int n;
    cin >> x >> y >> X >> Y >> n;
    for (ll i = 0; i < n; ++i) {
        ll a , b , r;
        cin >> r >> a >> b;
        for (ll j = a; j <= b; ++j) {
            allowable[{r , j}] = true;
        }
    }
    bfs();
    if(dis.find({X , Y}) == dis.end())
        cout << -1 << nl;
    else
        cout << dis[{X ,Y}] << nl;
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