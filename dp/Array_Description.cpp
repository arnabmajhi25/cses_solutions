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
    ll n,m;
    cin>>n>>m;
    vll x(n+1);
    FOR(i,1,n+1)cin>>x[i];
    vector<vector<ll>> dp(n+1,vll(m+2,0));
    if(x[1]==0)FOR(i,1,m+1)dp[1][i]=1;
    else dp[1][x[1]]=1;
    FOR(i,2,n+1){
        FOR(v,1,m+1){
            if(x[i]!=0 && v!=x[i])continue;
            dp[i][v]=(dp[i-1][v]+dp[i-1][v+1]+dp[i-1][v-1])%MOD;
        }
    }
    ll ans=0;
    FOR(i,1,m+1){
        ans = (ans+dp[n][i])%MOD;
    }
    cout<<ans%MOD<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t =1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}