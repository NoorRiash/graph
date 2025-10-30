
// q link: https://codeforces.com/contest/1433/problem/G

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


vector<vector<pair<ll,ll>>> nod;
ll n,m,k; 
vector<pair<ll,ll>>v,vn;
vector<ll>d;
ll inf=1e18;
 
vector<vector<ll>>dis;

void dij(ll src){


    priority_queue<pair<ll,ll>>q;
    q.push({0,src});
    d=vector<ll>(n,inf);
    d[src]=0;

    while(q.size()){
        ll c=-q.top().first , nd=q.top().second;
        q.pop();
        for(auto it:nod[nd]){
            ll cost=c+it.second;
            if(d[it.first]<cost)continue;
            q.push({-cost,it.first});
            d[it.first]=cost;
        }
 
    }
        
    for(int i=0;i<n;i++){
        dis[src][i]=d[i];
    }
 
}


void solve(){

    cin>>n>>m>>k; 
    ll x,y,z; 

    nod=vector<vector<pair<ll,ll>>>(n);
    d=vector<ll>(n);
    dis=vector<vector<ll>>(n,vector<ll>(n,inf));

    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        x--; y--;
        if(x>y)swap(x,y);
        vn.push_back({x,y});
        nod[x].push_back({y,z});
        nod[y].push_back({x,z});
    }
    
    for(int i=0;i<k;i++){
        cin>>x>>y;
        x--; y--;
        if(x>y)swap(x,y);
        v.push_back({x,y});
    }   

    for(int i=0;i<n;i++){
        dij(i);
    }

    ll res=inf;
    for(int i=0;i<m;i++){ 
        x=vn[i].first, y=vn[i].second;
        ll ans=0;
        for(int j=0;j<k;j++){
            ll fs=v[j].first, se=v[j].second;
            ans+=min({dis[fs][se],dis[fs][x]+dis[se][y],dis[fs][y]+dis[se][x]});
        }
        res=min(res,ans);
    }
  
    cout<<res<<endl;

}   


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}

