
// q link: https://codeforces.com/contest/144/problem/D
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


int n,m,l,src; 
vector<vector<pair<ll,ll>>>nod;
vector<ll>d;
ll inf=2e18;


void dij(){

    priority_queue<pair<ll,ll>>q;
    q.push({0,src});
    d[src]=0;
    while(q.size()){
        int fnt=q.top().second, c=-q.top().first;
        q.pop();
        if(c>d[fnt])continue;
        for(auto it:nod[fnt]){
            int cost=c+it.second;
            if(d[it.first]<cost)continue;
            q.push({-cost,it.first});
            d[it.first]=cost;
        }
        
    }

}


void solve(){

    cin>>n>>m>>src;
    src--;
    d=vector<ll>(n,inf);
    nod=vector<vector<pair<ll,ll>>>(n);

    int x,y,z;
    vector<pair<pair<ll,ll>,ll>>v;
    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        x--; y--;
        v.push_back({{x,y},z});
        nod[x].push_back({y,z});
        nod[y].push_back({x,z});
    }
    cin>>l;
    dij();

    ll ans=0;

    for(int i=0;i<n;i++){
        if(d[i]==l)ans++;
    }


    for(int i=0;i<m;i++){
        
        int fs=v[i].first.first, se=v[i].first.second;
        int cost=v[i].second;
        bool f1=0,f2=0;
       
        if(d[fs]<l&&(l-d[fs])<cost){
            int dif=l-d[fs];
            int dif2=cost-dif;
            if((d[fs]+dif)<=dif2+d[se]){
                x=dif;
                f1=1;
            }
        }
        
        if(d[se]<l&&(l-d[se])<cost){
            int dif=l-d[se];
            int dif2=cost-dif;
            if((d[se]+dif)<=dif2+d[fs]){
                y=dif;
                f2=1;
            }
        }

        if(f1&&f2){
            if(y+x==cost)ans++;
            else ans+=2;
        }
        else if(f1||f2)ans++;

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


