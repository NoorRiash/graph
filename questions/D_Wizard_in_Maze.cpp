

// q link: https://atcoder.jp/contests/abc176/tasks/abc176_d
// 0 1 bfs 


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define nl return
#define SLAY ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define dd double
#define ld long double
#define PI acos(-1)

vector<int>vx={-1,1,0,0};
vector<int>vy={0,0,1,-1};

 
void solve(){

    int n,m; cin>>n>>m;
    int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
    x1--; y1--; x2--; y2--;
    vector<string>v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    deque<pair<pair<int,int>,int>>q;
    q.push_front({{x1,y1},0});

    ll ans=0;
    bool f=1;
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    vector<vector<int>>vc(n,vector<int>(m,0));

    while(q.size()){    

        int fs=q.front().first.first, se=q.front().first.second;
        int cost=q.front().second;
        q.pop_front();
        vis[fs][se]=1;

        if(fs==x2&&se==y2){
            cout<<cost<<endl;
            f=0;
            break;
        }
 

        for(int i=0;i<4;i++){
            int x=vx[i]+fs, y=vy[i]+se;
            if(x>=0&&x<n&&y>=0&&y<m&&v[x][y]=='.'&&!vis[x][y]){
                q.push_front({{x,y},cost});
            }
        
        }

        for(int i=max(0,fs-2);i<=min(n-1,fs+2);i++){
            for(int j=max(0,se-2);j<=min(m-1,se+2);j++){
                if((i==fs&&j==se)||vis[i][j]||v[i][j]!='.')continue;
                q.push_back({{i,j},cost+1});
            }

        }

    }

    if(f)cout<<-1<<endl;
 
}   


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}  


