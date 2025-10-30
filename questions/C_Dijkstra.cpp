
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
vector<ll>par;

void dij(ll sour){

    for(ll i=0;i<n;i++){
        d[i]=inf;
    }
    
    d[sour]=0;
    par[sour]=-1;
    priority_queue<pair<ll,ll>>q;

    q.push({0,sour});
    while(q.size()){
        ll fs=-q.top().first, se=q.top().second;
        q.pop();
        if(se==n-1){
            break;
        }
        for(auto at:nod[se]){
            ll cost=at.second+fs;
            if(cost>d[at.first])continue;
            d[at.first]=cost;
            par[at.first]=se;
            q.push({-cost,at.first});
        }
        
    }


}





void solve(){

    cin>>n>>m; 
    ll x,y,z;
    par=vector<ll>(n);
    nod=vector<vector<pair<ll,ll>>>(n);
    d=vector<ll>(n);


    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        x--; y--;
        nod[x].push_back({y,z});
        nod[y].push_back({x,z});
    }

    // int sour; cin>>sour;
    dij(0);

    //to print path
    ll num=n-1;
    vector<ll>ans;
    ans.push_back(num);
    while(par[num]!=-1){
        ans.push_back(par[num]);
        num=par[num];
    }
    if(d[n-1]==inf){
        cout<<-1<<endl;
        nl;
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)cout<<ans[i]+1<<' ';

}   


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}

