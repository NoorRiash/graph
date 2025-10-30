 
// question link: https://codeforces.com/problemset/problem/369/C
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "yes" << endl
#define no cout << "no" << endl
#define nl return

vector<vector<int>>nod;
vector<int>vis;
 

int n,m; 

void solve(){

    cin>>n; 
    nod=vector<vector<int>>(n+1);
    vis=vector<int>(n+1,0);
    vector<int>ans;
    vector<int>deg(n+1);
    queue<int>q;
    int x,y,z;
    map<int,int>mp;
    set<int>s;

    for(int i=0;i<n-1;i++){
        cin>>x>>y>>z;
        nod[x].push_back(y);
        nod[y].push_back(x);
        deg[x]++;
        deg[y]++;
        mp[x]=z; mp[y]=z;
    }

    vector<int>nn;
    for(int i=n;i>=2;i--){
        if(deg[i]==1){
            if(mp[i]==2) { 
                vis[i]=1;
                ans.push_back(i);
            }
            else{
                if(i!=1)
                nn.push_back(i);
            }
        }
    }

 
    int j=0;
    if(nn.size()){
    q.push(nn[j]);
    j++;
    while(q.size()){
        
        int fnt=q.front();
        q.pop();
        vis[fnt]=1;
       
        for(auto it:nod[fnt]){

            if(it==1)continue;
            deg[it]--;
            if(deg[it]==1&&mp[it]==2&&!vis[it]){
                ans.push_back(it);
                vis[it]=1;
            }
            else if(deg[it]==1&&!vis[it]){
                vis[it]=1;
                nn.push_back(it);
            }
        }

        if(j<nn.size()){

        q.push(nn[j]);
        j++;}
    
    }
    }
    cout<<ans.size()<<endl;

    for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
    cout<<endl;

}   

llllllll


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}

