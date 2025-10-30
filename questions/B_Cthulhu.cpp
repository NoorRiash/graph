

// question link: https://codeforces.com/problemset/problem/103/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nl return

 
// sol using bfs 
void solve(){
    
    ll n,m; cin>>n>>m; 

    vector<vector<ll>>nod(n);
    vector<ll>indeg(n);
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--; y--;
        nod[x].push_back(y);
        nod[y].push_back(x);
        indeg[x]++;
        indeg[y]++;

    }

    int c=0;
    queue<ll>q;
    vector<ll>vis(n,0);
    for(int i=0;i<n;i++){
        if(indeg[i]==1) q.push(i);
    }
    
    //بتخلص من كل الفروع
    while(q.size()){
        c++;
        int num=q.front();
        vis[num]=1;
        q.pop();
        for(auto z:nod[num]) { 
            indeg[z]--; 
            if(indeg[z]==1&&!vis[z]){
                q.push(z); vis[z]=1;
            }
        }
    }
 
    bool f=0;

    // المفروض يضل عندي بس لوب وحدة 
    for(int i=0;i<n;i++){
        if(indeg[i]==2){
            f=1;
            q.push(i);
            break;
        }
    }
 
   
    // بمشي ع السيركل 
    while(q.size()){
        c++;
        int num=q.front();
        vis[num]=1;
        q.pop();
        for(auto z:nod[num]) { 
            indeg[z]--; 
            if(indeg[z]==1&&!vis[z]){
                q.push(z); vis[z]=1;
            }
        }
    }
 
    // the graph have to be 1 component to print fhtagn
    if((c==n&&f&&n==m)) cout<<"FHTAGN!"<<endl;
    else cout<<"NO"<<endl;  
    
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}





























// sol using dfs 
// اذا الجراف كونكتيد وعدد النودز بساوي عدد الاجيز معناها اكيد في سايكل وحدة
int n=10,m=10;
vector<vector<ll>>nod;
vector<ll>vis; 
 
void dfs(int idx){

    vis[idx]=1;
    for(auto child:nod[idx]){
        if(vis[child]==0) dfs(child);
    }

}


void solve(){
    
    cin>>n>>m; 

    nod=vector<vector<ll>>(n);
    vis=vector<ll>(n,0);
    vector<ll>indeg(n);
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--; y--;
        nod[x].push_back(y);
        nod[y].push_back(x);

    }

    dfs(0);  

    bool f=1;
    for(int i=0;i<n;i++){
        if(vis[i]==0) f=0;
    }
    // cout<<f<<endl;
    if(f&&n==m)cout<<"FHTAGN!"<<endl;
    else cout<<"NO"<<endl;
    
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}

