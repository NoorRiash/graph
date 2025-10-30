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
 

const int N=1e3+7;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int node,edg; bool col[N]; vector<int>adj[N]; //adjacency list 

//https://vjudge.net/problem/SPOJ-BUGLIFE
 
bool f=1;
 

void flush(){
    f=1;
    for(int i=0;i<N;i++){
        adj[i].clear();
        col[i]=-1;
    }

}

void dfs(int nod,int cur){//x is the node 

    col[nod]=cur;
    for(auto it:adj[nod]){
        int nxt=cur^1;
        if(col[it]==-1) dfs(it,nxt);
        else if(col[it]!=nxt){
            f=0;
            return;
        }
    }

}



void solve(){

    flush();
    cin>>node>>edg; 
    int n,m; 
    for(int i=0;i<edg;i++){
        cin>>n>>m;
        adj[n].push_back(m);
        adj[m].push_back(n);
    }

    dfs(1,0);
    
    for(int i=1;i<=node;i++){
        if(col[i]==-1) dfs(i,0);
        
    }
    f?cout<<"":cout<<"";
    // cout<<f?"":"";

}


int main(){
    SLAY
    int t=1; 
    cin>>t;
    while(t--)
        solve();
    return 0;
}

