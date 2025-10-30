
// question link: https://codeforces.com/contest/690/problem/C1
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "yes" << endl
#define no cout << "no" << endl
#define nl return

vector<int>vx={-1,1,0,0,-1,1,-1,1};
vector<int>vy={0,0,1,-1,1,1,-1,-1};
vector<vector<int>>nod;
vector<int>vis;


void dfs(int idx){
    
    vis[idx]=1;
    for(auto x:nod[idx]) if(vis[x]==0)dfs(x);
}

void solve(){

    int n,m; cin>>n>>m; 
    nod=vector<vector<int>>(n);
    vis=vector<int>(n,0);
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--; y--;
        nod[x].push_back(y);
        nod[y].push_back(x);
    }

    bool f=1;
    dfs(0);

    for(int i=0;i<n;i++){
        if(vis[i]==0){
            f=0;
            break;
        }
    }

    if(n>m&&f) yes;
    else no;
 
}   


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}

