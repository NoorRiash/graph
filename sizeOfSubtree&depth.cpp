
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "yes" << endl
#define no cout << "no" << endl
#define nl return

vector<vector<int>>nod;
vector<int>vis;

vector<int>depth,numsubtree;

void dfs(int idx,int par,int dep){

    depth[idx]=dep; 
    numsubtree[idx]=1;
    for(auto it:nod[idx]){
        if(it!=par){
            dfs(it,idx,dep+1);
            numsubtree[idx]+=numsubtree[it];
        }
    }
}



void solve(){

    int n,m; cin>>n>>m; 
    nod=vector<vector<int>>(n);
    vis=vector<int>(n,0);
    depth=vector<int>(n,0);
    numsubtree=vector<int>(n,0);
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--; y--;
        nod[x].push_back(y);
        nod[y].push_back(x);
    }

    dfs(0,-1,0);
}   


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}

