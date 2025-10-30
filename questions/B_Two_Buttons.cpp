
// question link: https://codeforces.com/problemset/problem/520/B
//bfs

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nl return

 

void solve(){
    
    ll n,m;  cin>>n>>m;  //i want to get m from n

    ll cnt=0, limit=max(n,m)*2;
    vector<ll>vis(limit+1,0);
    vis[n]=1;
    queue<pair<ll,ll>>q;
    q.push({n,0});
    ll c=0;
    while(q.size()){
        ll num=q.front().first;
        c=q.front().second;
        q.pop();
        if(num==m)break;
        if(num-1>=0&&!vis[num-1]) { vis[num-1]=1; q.push({num-1,c+1}); }
        if(num*2<=limit&&!vis[num*2]) { vis[num*2]=1; q.push({num*2,c+1}); }
       

    }

    cout<<c<<endl;

}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}

