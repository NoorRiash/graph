
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nl return


// bfs
void solve1(){
    
    int n,m; cin>>n>>m; 

    int a,b; vector<int>inDegree(n,0);
    vector<vector<int>>nod(n);
    for(int i=0;i<m;i++){
        cin>>a>>b; 
        a--; b--;
        nod[a].push_back(b);
        inDegree[b]++;
    }
    
    vector<int>ans;
    int cnt=0;
    queue<int>q;
    for(int i=0;i<n;i++){
        if(inDegree[i]==0)q.push(i);
    }

    while(q.size()){
        int num=q.front(); q.pop();
        cnt++;
        ans.push_back(num+1);
        for(auto x:nod[num]) { inDegree[x]--; if(inDegree[x]==0) q.push(x); }
    }

    // to check if it is acyclic 
    if(cnt==n){
        cout<<"acyclic"<<endl;
        return;
    }

    cout<<"cyclic"<<endl;

}











// dfs

vector<bool>inStack; // to check if the node still in the internal stack 
vector<bool>vis;
vector<vector<int>>nod;
int n,m;
bool f=1;




void dfs1(int idx){

    vis[idx]=1;
    inStack[idx]=1;
    for(auto it:nod[idx]){
        if(!vis[it]){
            dfs1(it);
        }
        else if(inStack[it]){
            f=0;
            return;
        }
    }

    inStack[idx]=0;


}














set<pair<int,int>>s;
void dfs2(int idx,int x){

    vis[idx]=1;
    inStack[idx]=1;
    s.insert({idx,x});
    for(auto it:nod[idx]){
        if(!vis[it]){
            dfs2(idx+1,it);
        }
        else if(inStack[it]){
            f=1;
            cout<<"there is a cycle"<<endl;
            for(auto num:s){
                cout<<num.second<<' ';
                cout<<endl;
            }
            return;
        }
    }

    inStack[idx]=0;
    s.erase({idx,x});

}







void solve2(){

    cin>>n>>m;
    nod=vector<vector<int>>(n);
    inStack=vector<bool>(n);
    vis=vector<bool>(n);

    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        x--; y--;
        nod[x].push_back(y);
    }


    // if i just want to check if there cycle or not
    /*
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs1(i);
        if(f){
            cout<<"there is a cycle"<<endl;
            nl;
        }
    }
    */


    // if i want to print the cycle 
    /*
    f=0;
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs2(0,i);
        if(f){
           
            nl;
        }
    }
    */


}


 

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve1(); //bfs
        solve2(); //dfs
    }
    return 0;
}


