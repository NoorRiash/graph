
// q link: https://codeforces.com/contest/2112/problem/D

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
 

void solve(){

    // اذا في نود الدجري لالها 2 بعتمد الحل 
    // غير هيك نووو
 
 
    ll n; 
    cin>>n; 
    vector<vector<ll>>nod(n);
    vector<bool>vis(n,0);
    vector<int>deg(n,0); 
    vector<pair<ll,ll>>ans;
    vector<int>v;
    ll x,y;
    vector<int>par(n,-1);
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        x--; y--;
        nod[x].push_back(y);
        nod[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
 
    bool flg=0;

    for(int i=0;i<n;i++){
        if(deg[i]==2){
            ans.push_back({nod[i][0],i});
            ans.push_back({i,nod[i][1]});
            v.push_back(nod[i][0]);
            v.push_back(i);
            v.push_back(nod[i][1]);
            flg=1;
            break;
        }
    }


    if(!flg){
        no;
        nl;
    }

    yes;
    queue<pair<int,int>>q;  
    q.push({v[0],1});
    vis[v[1]]=1;

    while(q.size()){

        int fnt=q.front().first;
        int dir=q.front().second;
        vis[fnt]=1;
        q.pop();
        for(auto it:nod[fnt]){
            if(!vis[it]){
                if(dir){
                    ans.push_back({fnt,it});
                }
                else ans.push_back({it,fnt});
            
                q.push({it,1^dir});
            }
        }

    }


    q.push({v[2],1});


    while(q.size()){
        int fnt=q.front().first;
        int dir=q.front().second;
        vis[fnt]=1;
        q.pop();
        for(auto it:nod[fnt]){
            if(!vis[it]){
                if(!dir){
                    ans.push_back({fnt,it});
                }
                else ans.push_back({it,fnt});
                q.push({it,1^dir});
            }
        }

    }


    for(int i=0;i<n-1;i++)cout<<ans[i].first+1<<' '<<ans[i].second+1<<endl;


}
 

int main(){
    SLAY
    int t=1;
    cin>>t;
    while(t--) solve();
}


 