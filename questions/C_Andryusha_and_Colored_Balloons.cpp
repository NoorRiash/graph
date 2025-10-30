 
// question link: https://codeforces.com/problemset/problem/780/C
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "yes" << endl
#define no cout << "no" << endl
#define nl return

vector<vector<int>>nod;
vector<int>vis;
vector<int>vx={-1,1,0,0};
vector<int>vy={0,0,1,-1};
vector<pair<int,int>>vpos;

int n,m; 

void solve(){

    int n; cin>>n; 
    nod=vector<vector<int>>(n+1);
    vis=vector<int>(n+1,0);

    int x,y; 
    vector<int>par(n+1);
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        nod[x].push_back(y);
        nod[y].push_back(x);
    }
    

    // to determine the parent for every node
    queue<int>q;
    q.push(1); par[1]=-1;

    while(q.size()){
        int fnt=q.front();
        vis[fnt]=1;
        q.pop();
        for(auto it:nod[fnt]){
            if(!vis[it]){
                par[it]=fnt;
                q.push(it);
            }
        }
    }


    vis=vector<int>(n+1,0);
    q.push(1);

    vector<ll>ans(n+1,-1);
    ans[1]=1;
    int num=1;
    ll mx=0;
    while(q.size()){
        int fnt=q.front();
        q.pop(); 
        vis[fnt]=1;
   
        int fst=par[fnt], lst=fnt;
        if(fst==-1)fst=0;

        ll cnt=1;
        for(auto it:nod[fnt]){
            if(!vis[it]){
                q.push(it);
                while(cnt==ans[fst]||cnt==ans[lst])cnt++;
                if(cnt!=ans[fst]&&cnt!=ans[lst]){
                    ans[it]=cnt;
                }
                cnt++;
                mx=max(mx,ans[it]);
            }
        }
    }

    cout<<mx<<endl;
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    
}   


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}

