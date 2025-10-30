
/*

    just for DIRICTED ACYLIC GRAPH (DAG) 

*/


// THIS SOL USING BFS





#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define stop return


void solve(){
    
    int n,m; cin>>n>>m; 

    int a,b; vector<int>inDegree(n,0);
    vector<vector<int>>nod(n);
    for(int i=0;i<m;i++){
        cin>>a>>b; 
        a--; b--;
        nod[a].push_back(b);
        inDegree[b]++;
    }

    queue<int>q;
    for(int i=0;i<n;i++){
        if(inDegree[i]==0)q.push(i);
    }

    while(q.size()){
        int num=q.front(); q.pop();
        cout<<num+1<<' ';
        for(auto x:nod[num]) { inDegree[x]--; if(inDegree[x]==0) q.push(x); }
    }


}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}

