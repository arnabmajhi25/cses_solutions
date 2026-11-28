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


constexpr ll MOD = 998244353;
constexpr ll BIG18 = 1e18;
constexpr ll BIG9 = 1e9;
constexpr int MX = (int)2e5+5;

void solve(){
    int n,m;
    cin>>n>>m;
    vi a(n),b(m);
    get(a,n);get(b,m);
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<endl;
    vector<int> lcs;
    int i=n,j=m;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            lcs.pb(a[i-1]);
            i--;j--;
        }
        else if(dp[i][j-1]>dp[i-1][j])j--;
        else i--;
    }
   rev(lcs);
   give(lcs,lcs.size());

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