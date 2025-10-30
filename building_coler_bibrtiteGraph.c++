 
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

int n,m;
vector<vector<ll>>nod;
vector<ll>v;

void solve(){

    cin>>n>>m;
    
    vector<ll>coler(n,-1);
    nod=vector<vector<ll>>(n);
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--; y--;
        nod[x].push_back(y);
        nod[y].push_back(x);
    }


    for(int i=0;i<n;i++){

        if(coler[i]==-1){
            queue<ll>q;
            q.push(i);
            coler[i]=0;
            while(q.size()){

                ll fnt=q.front();
                q.pop();

                for(auto it:nod[fnt]){
                    if(coler[it]==coler[fnt]){
                        cout<<"IMPOSSIBLE"<<endl; // we reach odd cycle 
                        nl;
                    }
                    if(coler[it]!=-1)continue;
                    coler[it]=!coler[fnt];
                    q.push(it);
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<coler[i]+1<<' ';
    }

}
 

int main(){
    SLAY
    int t=1;
    // cin>>t;
    while(t--) solve();
}


