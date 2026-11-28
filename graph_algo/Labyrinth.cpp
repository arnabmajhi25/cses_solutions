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
void bfs(vector<string> &grid,vector<vector<bool>>&vis,int sr,int sc,int er,int ec,int n,int m){
    int dr[4]={-1,1,0,0};
    int dc[4] = {0,0,1,-1};
    char dir[4] = {'U','D','R','L'};
    queue<pair<int,int>> q;
    q.push({sr,sc});
    vector<vector<char>> path(n,vector<char>(m,0));
    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        int r=curr.first;
        int c = curr.second;
        vis[r][c]=true;
        int flag=0;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc= c+dc[i];
            if(nr>=0 && nc>=0 &&  nr<n && nc<m &&!vis[nr][nc] && grid[nr][nc]!='#'&& nr<n && nc<m){
                vis[nr][nc]=true;
                path[nr][nc]=dir[i];
                q.push({nr,nc});
                if(nr==er && nc== ec){flag=1;break;}
            }
        }
        if(flag)break;
    }
    if(!vis[er][ec])cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        int r=er;
        int c = ec;
        string s="";
        while(r!=sr || c!= sc){
            char move = path[r][c];
            s+=move;
            if(move=='U')r++;
            else if(move=='D')r--;
            else if(move=='L')c++;
            else if(move=='R')c--;
        }
        reverse(s.begin(),s.end());
        cout<<s.length()<<endl<<s<<endl;
    }

}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;i++)cin>>grid[i];
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    int sr,sc,er,ec;
    for(int i= 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                sr=i;sc=j;
            }
            if(grid[i][j]=='B'){
                er=i;
                ec=j;
            }
        }
    }
    bfs(grid,vis,sr,sc,er,ec,n,m);
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