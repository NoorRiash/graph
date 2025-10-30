
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

vector<vector<pair<int,int>>>nod;
int n,m; 
int idx=-1;
vector<int>dep;
ll inf=2e9+10;
vector<int>d;




// time com O(n+m)+log2(n)

void dij(int sour){

    for(int i=0;i<n;i++) d[i]=inf;
    
    d[sour]=0;

    priority_queue<pair<int,int>>q; 
    // or حتى يرتب تصاعدي تلقائي 
    // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; 
    // here there is no need to use -1
 

    q.push({0,sour});
    while(q.size()){
        int fs=-q.top().first; int se=q.top().second;
        q.pop();
        for(auto x:nod[se]){

            if(d[x.first]<(fs+x.second))continue;
            q.push({-(fs+x.second),x.first});
            d[x.first]=(fs+x.second);
        } 

    }


}





void solve(){

    cin>>n>>m; 
    int x,y,z; 
    nod=vector<vector<pair<int,int>>>(n);
    d=vector<int>(n);
    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        x--; y--;
        nod[x].push_back({y,z});
        nod[y].push_back({x,z});
    }

    int source; cin>>source;
    dij(source);


}   


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}



















