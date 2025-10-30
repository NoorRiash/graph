
// question link: https://codeforces.com/problemset/problem/242/C
//bfs

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nl return

vector<int>vx={-1,1,0,0,-1,1,-1,1};
vector<int>vy={0,0,1,-1,1,1,-1,-1};

void solve(){
    
    int x0,y0,x1,y1; cin>>x0>>y0>>x1>>y1;

    int k,r,c1,c2; cin>>k; 
    map<ll,set<ll>>mp;
    for(int i=0;i<k;i++){
        cin>>r>>c1>>c2;
        for(int j=c1;j<=c2;j++){
            mp[r].insert(j);
        }
    }

    set<pair<ll,ll>>s;
    queue<pair<pair<ll,ll>,ll>>q;
    q.push({{x0,y0},0});

    while(q.size()){
        int fr=q.front().first.first, se=q.front().first.second;
 
        int num=q.front().second;
        if(fr==x1&&se==y1){
            cout<<num<<endl;
            return;
        }
        q.pop();

        for(int i=0;i<8;i++){
            if(((vx[i]+fr)>=1&&(vx[i]+fr)<=1e9)&&((vy[i]+se)>=1&&(vy[i]+se)<=1e9)){
                if(mp[vx[i]+fr].count(se+vy[i])&&(s.count({vx[i]+fr,se+vy[i]})==0)){
                    s.insert({vx[i]+fr,se+vy[i]});
                    q.push({{vx[i]+fr,se+vy[i]},num+1});
                }
            }
        }

    }

    cout<<-1<<endl;

}   


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}

