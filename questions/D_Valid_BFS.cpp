
// question link: https://codeforces.com/contest/1037/problem/D
// فكرته مهمة 

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

int n=10;
vector<set<ll>>nod;
vector<ll>v(n);

void solve(){

    cin>>n; 
    nod=vector<set<ll>>(n+1);
    v=vector<ll>(n+1);
    vector<ll>vis(n+1);
    ll x,y; 
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        nod[x].insert(y);
        nod[y].insert(x);
 
    }

    for(int i=0;i<n;i++) cin>>v[i];
    queue<ll>q;
    q.push(1);

    int j=1;
    bool f=0;
    while(q.size()){

        ll fnt=q.front();
        vis[fnt]=1;
        q.pop();
        while(j<n){
            if(nod[fnt].count(v[j])&&!vis[v[j]]){
                f=1;
                q.push(v[j]);
                nod[fnt].erase(v[j]);
            }
            else break;
            j++;
            
        }

    }
    if(j!=n) no;
    else yes;

}
 

int main(){
    SLAY
    int t=1;
    // cin>>t;
    while(t--) solve();
}


