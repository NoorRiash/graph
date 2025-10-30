
// question link: https://codeforces.com/problemset/problem/377/A
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "yes" << endl
#define no cout << "no" << endl
#define nl return

vector<vector<int>>nod;
vector<vector<int>>vis;
vector<int>vx={-1,1,0,0};
vector<int>vy={0,0,1,-1};
vector<pair<int,int>>vpos;

int n,m; 

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==-1)cout<<'#';
            else if(vis[i][j]==0)cout<<'X';
            else cout<<'.';
        }
        cout<<endl;
    }
}


void solve(){

    int k; cin>>n>>m>>k;
    vector<string>v(n);
    queue<pair<int,int>>q;
    vis=vector<vector<int>>(n,vector<int>(m,-1));
    bool f=1;

    for(int i=0;i<n;i++){
        cin>>v[i];
        for(int j=0;j<m;j++){
            if(v[i][j]=='.'&&f){
                f=0;
                q.push({i,j});
                vpos.push_back({i,j});
                vis[i][j]=1;
            }
            else if(v[i][j]=='.'){
                vpos.push_back({i,j});
                vis[i][j]=0;
            }
        }        
    }
 
    int sz=vpos.size();
    int c=1;
   
    while(q.size()){

        int si=q.size();
 
        int fr=q.front().first; int se=q.front().second;
        q.pop();
 
        for(int i=0;i<4;i++){
            int x=fr+vx[i]; int y=se+vy[i];
            if(sz-c==k){
                print();
                return;
            }
            if(x>=0&&x<n&&y>=0&&y<m&&v[x][y]=='.'&&!vis[x][y]){
                q.push({x,y});
                c++;
                vis[x][y]=1;
            }
        }
    }
    
}   


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}

