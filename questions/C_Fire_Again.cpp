
// question link: https://codeforces.com/problemset/problem/35/C
//bfs

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nl return

// {-1,0} {1,0} {0,1} {0,-1}

vector<int>vx={-1,1,0,0};
vector<int>vy={0,0,1,-1};
int n,m;

bool check(int x,int y){

    if(x>=0&&x<n&&y>=0&&y<m)return 1;
    return 0;

}


void solve(){
    
    int x,y; cin>>n>>m;
    int amount; cin>>amount;
    vector<vector<int>>v(n,vector<int>(m,0));

    queue<pair<int,int>>q;
    for(int i=0;i<amount;i++){ 
        cin>>x>>y; x--; y--; 
        q.push({x,y}); v[x][y]=1;
     }
    
    pair<int,int> p;
    while(q.size()){
        p=q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            
            if(check(p.first+vx[i],p.second+vy[i])){
                if(v[p.first+vx[i]][p.second+vy[i]]==0){
                    q.push({p.first+vx[i],p.second+vy[i]});
                    v[p.first+vx[i]][p.second+vy[i]]=1;
                }
            }
        }


    }

    cout<<p.first+1<<' '<<p.second+1<<endl;



}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}

