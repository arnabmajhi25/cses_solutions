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

void bfs(vector<string> &map,vector<vector<bool>> &visited,int i,int j,int n,int m){
    queue<pair<int,int>> q;
    q.push({i,j});
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,1,-1};
    while(!q.empty()){
        pair<int,int> u = q.front();q.pop();
        int r = u.first;
        int c = u.second;
        for(int i = 0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !visited[nr][nc] && map[nr][nc]=='.'){
                visited[nr][nc] = true;
                q.push({nr,nc});
            }
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> map(n);
    for(int i = 0;i<n;i++){
        cin>>map[i];
    }
    int room=0;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(map[i][j]=='.' && !visited[i][j]){
                visited[i][j]=true;
                room++;
            bfs(map,visited,i,j,n,m);
            }
        }
    }
    cout<<room<<endl;
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