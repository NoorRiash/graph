#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nl return
 
vector<bool>inStack; // to check if the node still in the internal stack 
vector<bool>vis;
vector<vector<int>>nod;
int n,m;
bool f=0;
set<pair<int,int>>s;
 
void dfs2(int idx,int x){
 
    if(f)return;
    vis[x]=1;
    inStack[x]=1;
    s.insert({idx,x});
    for(auto it:nod[x]){
        if(f)return;
        if(!vis[it]){
            dfs2(idx+1,it);
        }
        else if(inStack[it]&&!f){
            f=1;
            int y=0;
            for(auto num:s){
                if(num.second==it){
                    y=num.first; 
                    break;
                }
            }
            vector<ll>ans;
            for(auto num:s){
                if(num.first>=y){
                    ans.push_back(num.second);
                }
            }   
            cout<<ans.size()+1<<endl;
            for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
            cout<<ans[0]<<endl;
            return;
        }
    }
 
    inStack[x]=0;
    s.erase({idx,x});
 
}
 
 
void solve2(){
 
    cin>>n>>m;
    nod=vector<vector<int>>(n+1);
    inStack=vector<bool>(n+1);
    vis=vector<bool>(n+1);
 
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        nod[x].push_back(y);
    }
 
 
    f=0;
    for(int i=1;i<=n;i++){
        if(f){
            nl;
        }
        if(!vis[i]) dfs2(0,i);
       
    }
    
    cout<<"IMPOSSIBLE"<<endl;
 
 
}
 
 
 
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve2(); //dfs
    }
    return 0;
}
 

