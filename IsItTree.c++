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
 

const int N=1e5+7;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int node,edg; bool vis[N]; vector<int>adj[N]; //adjacency list 



// i have to chk 3 conditions 1)Acyclic 2)1 component  3)edges=nodes-1
// i can just chk (1&2) or (2&3)  or (1&3)

// to chk 1
void dfs(int nod,int par){//x is the node 
    vis[nod]=1;
 
    for(auto neg:adj[nod]){
        if(neg==par)continue;
        if(!vis[neg]) dfs(neg,nod);
        else {no; exit (0);}
    }
}


void solve(){

    cin>>node>>edg;
    int n,m; 
    for(int i=0;i<edg;i++){
        cin>>n>>m;
        adj[n].push_back(m);
        adj[m].push_back(n);
    }

    dfs(1,-1);

    //to chk 2
    for(int i=1;i<=node;i++){
        if(!vis[i]){
            no; 
            return;
        }
    }


    yes;

    // // to chk 3 
    // if(n-1!=m) no;
    // else yes;

}


int main(){
    SLAY
    int t=1; 
    cin>>t;
    while(t--)
        solve();
    return 0;
}

