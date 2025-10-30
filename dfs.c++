#include<bits/stdc++.h>
#define FOR() for (int i = 0; i < n; i++)
using namespace std;
#define ll long long
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define stop return

//      Free Palestine
const int N=1e5+7;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int node,edg; bool vis[N]; vector<int>adj[N]; //adjacency list 
void dfs(int x){//x is the node 
vis[x]=1;
///
for(auto it:adj[node]){
    if(!vis[it]){
        dfs(it);
    }
}
}

int main(){
cin>>node>>edg;
int a,b;
while(edg--){
cin>>a>>b;
adj[a].push_back(b);
adj[b].push_back(a);
}
dfs(1);// ببدا من عند اي نود

}



//longest path
/*
int dfs(int i){
vis[i]=1;
int ans=0;
for(int j=0;j<v[i].size();j++){
  if(!vis[v[i][j]]){
    ans=max(dfs(v[i][j])+1,ans);
}
}
return ans;
}
*/