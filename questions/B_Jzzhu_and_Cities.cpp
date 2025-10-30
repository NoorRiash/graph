
// q link: https://codeforces.com/contest/449/problem/B
// dijkstra

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


ll n,m,k; 
ll inf=2e18;
vector<vector<pair<pair<ll,ll>,ll>>>nod;
vector<ll>d;
ll cnt=0;
vector<ll>train;


void dij(ll src){

    d[src]=0;

    priority_queue<pair<ll,ll>>q;
    q.push({0,0});

    while(q.size()){
        ll c=-q.top().first, fnt=q.top().second; 
        q.pop();
        if(c>d[fnt])continue;
    
        for(auto it:nod[fnt]){
            ll cost=it.first.second+c;
            ll num=it.first.first;
            ll chk=it.second;
            if(d[num]<cost)continue;
            if(d[num]>cost){
                q.push({-cost,num});
                train[num]=chk;
                d[num]=cost;
            }
            else if(cost==d[num]&&!chk){
                train[num]=0;
            }
        
        }
    }

}


void solve(){
    
    cin>>n>>m>>k;

    d=vector<ll>(n,inf);
    train=vector<ll>(n,0);
    nod=vector<vector<pair<pair<ll,ll>,ll>>>(n);
    ll x,y,z;
    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        x--; y--;
        nod[x].push_back({{y,z},0});
        nod[y].push_back({{x,z},0});

    }

    for(int i=0;i<k;i++){
        cin>>x>>y;
        x--; 
        nod[0].push_back({{x,y},1});
    }
    dij(0);
   
    for(int i=0;i<n;i++){
        if(train[i])cnt++;
    }
    cout<<k-cnt<<endl;

}   


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}


