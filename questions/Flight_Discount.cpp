
//q link: https://cses.fi/alon/task/1195
//dijkstra


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

// vector<ll>d1,d2;
vector<vector<pair<ll,ll>>>nod,nod2;
ll inf=2e18;
int n,m;


vector<ll> dij(ll src,vector<vector<pair<ll,ll>>>&nod){

    vector<ll>d(n,inf);
    d[src]=0;

    priority_queue<pair<ll,ll>>q;
    q.push({0,src});

    while(q.size()){

        ll fnt=q.top().second, c=-q.top().first;
        q.pop();
        if(c>d[fnt])continue;

        for(auto it:nod[fnt]){
            ll cost=it.second+c;
            if(cost<d[it.first]){
                q.push({-cost,it.first});
                d[it.first]=cost;
            }
        }

    }

    return d;

}

 
void solve(){

    cin>>n>>m;
    
    vector<ll>d1(n,inf);
    vector<ll>d2(n,inf);
    nod=vector<vector<pair<ll,ll>>>(n);
    nod2=vector<vector<pair<ll,ll>>>(n);
    vector<pair<pair<ll,ll>,ll>>ve;
    int x,y,z;
    for(int i=0;i<m;i++){
        cin>>x>>y>>z; 
        x--; y--;
        nod[x].push_back({y,z});
        nod2[y].push_back({x,z});
        ve.push_back({{x,y},z});
    }

    d1=dij(0,nod);
    d2=dij(n-1,nod2);
    
    ll ans=inf;
    for(int i=0;i<m;i++){
        int fs=ve[i].first.first, se=ve[i].first.second, c=ve[i].second;         
        ll cost=d1[fs]+d2[se]+c/2;
        ans=min(ans,cost);
    }

    cout<<ans<<endl;

}   


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}

