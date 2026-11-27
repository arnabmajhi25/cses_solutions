#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define mae max_element
#define mie min_element
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define srt(x) sort(all(x))
#define rev(x) reverse(all(x))
#define rsrt(x) sort(rall(x))
#define sz(x) (int)(x.size())
#define lb(v,x) (int)(lower_bound(all(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(all(v),x)-v.begin())
#define uni(v) v.resize(unique(all(v))-v.begin())
#define FOR(i, s, n) for (auto i = s; i < n; i++)
#define get(v, n) for(auto i = 0; i < n ; ++i) cin >> v[i]
#define give(v, n) for(auto i = 0; i < n; ++i){ cout << v[i] << ' ';} cout << endl

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using qi = queue<int>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vb>;


constexpr ll MOD = 1e9+7;
constexpr ll BIG18 = 1e18;
constexpr ll BIG9 = 1e9;
constexpr int MX = (int)2e5+5;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i =1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n+1,false);
    vector<int> par(n+1,-1);
    vis[1]=true;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int node = q.front();q.pop();
        for(int i : adj[node]){
            if(!vis[i]){
                vis[i]= true;
                par[i]=node;
                q.push(i);
            }
        }
    }
    vi route;
    if(vis[n]){
        int n1=n;
        route.pb(n1);
        while(n1!=1){
            route.pb(par[n1]);
            n1= par[n1];
        }
    cout<<route.size()<<endl;
    reverse(route.begin(),route.end());
    give(route,route.size());
    }
    else cout<<"IMPOSSIBLE"<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t=1 ;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}