
 
// there are 2 ways to solve it either dfs or bfs ( i'll use bfs )



// question link: https://codeforces.com/contest/690/problem/C2 // هاد سؤال عليه بس تطبيق مباشر يعني ما في اضافة 
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "yes" << endl
#define no cout << "no" << endl
#define nl return

vector<vector<int>>nod;
vector<int>vis;

int j=0,maxdis=0;
vector<int>dis;

void bfs(int idx){

    queue<int>q; 
    q.push(idx);

    while(q.size()){
        int num=q.front();
        q.pop();
        vis[num]=1;
        for(auto x:nod[num]){
            if(!vis[x]){
                vis[x]=1;
                dis[x]=dis[num]+1;
                if(dis[x]>maxdis){
                    j=x;
                    maxdis=dis[x];
                }
                q.push(x);
            }
        }
    }
}



void solve(){

    int n,m; cin>>n>>m; 
    nod=vector<vector<int>>(n);
    vis=vector<int>(n,0);
    dis=vector<int>(n,0);
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--; y--;
        nod[x].push_back(y);
        nod[y].push_back(x);
    }

  
    bfs(0);
 
    vis=vector<int>(n,0);
    dis=vector<int>(n,0);
    maxdis=0;
    bfs(j);
    cout<<maxdis<<endl;
    
  
}   


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}













// dfs


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
 
 
vector<vector<int>>nod;
vector<bool>vis;
vector<bool>in;
set<pair<int,int>>s;
int n,m; 
int idx=-1;
vector<int>dep;
 
 
void dfs(int x,int par,int curdep){
    
    dep[x]=curdep;
    for(auto y:nod[x]){
        if(y!=par){
            dfs(y,x,curdep+1);
        }
    }
 
}
 
 
void solve(){
 
    cin>>n;
    m=n-1;
    int x,y;
 
    nod=vector<vector<int>>(n+1);
    dep=vector<int>(n);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--; y--;
        nod[x].push_back(y);
        nod[y].push_back(x);
    }    
    dfs(0,-1,0);
 
    int j=0, mx=0;
    for(int i=0;i<n;i++){
        if(dep[i]>mx){
            mx=dep[i];
            j=i;
        }
    }
    dfs(j,-1,0);
    mx=0;
    for(int i=0;i<n;i++){
        if(dep[i]>mx){
            mx=dep[i];
        }
    }
    cout<<mx<<endl;
 
}   
 
 
int main(){
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
 
}

