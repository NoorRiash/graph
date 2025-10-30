
// question link: https://codeforces.com/contest/690/problem/C2
 
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

