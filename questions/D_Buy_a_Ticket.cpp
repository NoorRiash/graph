

// q link: https://codeforces.com/contest/938/problem/D

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

vector<vector<pair<ll,ll>>>nod;
ll n,m; 
ll inf=2e18+10;
vector<ll>d;

// time com O(n+m)+log2(n)

void dij(){


    priority_queue<pair<ll,ll>>q; 
    
    for(int i=0;i<n;i++){
        q.push({-d[i],i});
    }


    while(q.size()){
        ll fs=-q.top().first; ll se=q.top().second;
        q.pop();
        if(d[se]<(fs))continue;
        for(auto x:nod[se]){
            ll cost=fs+x.second;
            if(d[x.first]<(cost))continue;
            q.push({-(cost),x.first});
            d[x.first]=(cost);
        } 
    }


}


void solve(){

    cin>>n>>m; 
    ll x,y,z; 
    nod=vector<vector<pair<ll,ll>>>(n);
    d=vector<ll>(n);
    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        x--; y--;
        nod[x].push_back({y,z*2});
        nod[y].push_back({x,z*2});
    }

    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    dij();

    for(int i=0;i<n;i++){
        cout<<d[i]<<' ';
    }


}   


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}

