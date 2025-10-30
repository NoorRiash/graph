
// q link: https://codeforces.com/contest/2114/problem/E

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


vector<vector<ll>>nod;
ll n; 
vector<ll>v,ans;


void dfs(ll idx,ll par,ll even,ll odd,ll f){
    
    if(f){ // even

        ans[idx]=max(v[idx]+even,v[idx]);
        even+=v[idx];
        odd=max(0LL,odd-v[idx]);
    }

    else{ //odd
        ans[idx]=max(v[idx],v[idx]+odd);
        odd+=v[idx];
        even=max(0LL,even-v[idx]);
    }

    for(auto it:nod[idx]){
        if(it!=par)
        dfs(it,idx,even,odd,f^1);
    }

}


void solve(){

    cin>>n; 

    v=vector<ll>(n);
    ans=vector<ll>(n);
    nod=vector<vector<ll>>(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    ll x,y;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        x--; y--;
        nod[x].push_back(y);
        nod[y].push_back(x);
    }

    dfs(0,-1,0,0,1);

    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;

}
 

int main(){
    SLAY
    int t=1;
    cin>>t;
    while(t--) solve();
}

