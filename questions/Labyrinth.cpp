

//question link:https: //cses.fi/problemset/task/1193

// the first solve in dfs and the second in bfs 



// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define yes cout << "YES" << endl;
// #define no cout << "NO" << endl;
 
// const int N=1e3+7;
// const int dx[]={0,0,1,-1};
// const int dy[]={1,-1,0,0};
// string dir="RLDU";
// int n,m,sx,sy,ex,ey; char s[N][N];
// string ans,x="";
// int node,edg; bool vis[N][N]; vector<int>adj[N]; //adjacency list 


// bool valid(int x,int y){

//     return x<n&&x>=0&&y<m&&y>=0&&!vis[x][y]&&s[x][y]!='#';
// } 

// void dfs(int x,int y,char ch){  //x is the node 
// vis[x][y]=1;
//     for(int i=0;i<4;i++){
//         if(valid(x+dx[i],y+dy[i]))dfs(x+dx[i],y+dy[i],s[x+dx[i]][y+dy[i]]);
//     }
// }

// int main(){
// cin>>n>>m;
// for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
//     cin>>s[i][j];
//     if(s[i][j]=='A'){
//         sx=i; sy=j;
//     }
//     if(s[i][j]=='B'){
//         ex=i;
//         ey=j;
//     }
// }
// dfs(sx,sy);
// ll ans=0;
// for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
//     if(valid(i,j)){
//         ans++;
//         dfs(i,j,s[i][j]);
//     }
// }
// cout<<ans<<endl;
 

// }





// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define yes cout << "YES" << endl;
// #define no cout << "NO" << endl;
 
// const int N=1e3+7;
// const int dx[]={0,0,1,-1};
// const int dy[]={1,-1,0,0};
// int n,m; char s[N][N];
// int node,edg; bool vis[N][N]; vector<int>adj[N]; //adjacency list 


// bool valid(int x,int y){

//     return x<n&&x>=0&&y<m&&y>=0&&!vis[x][y]&&s[x][y]!='#';
// } 

// void dfs(int x,int y,char ch){  //x is the node 
// vis[x][y]=1;
//     for(int i=0;i<4;i++){
//         if(valid(x+dx[i],y+dy[i]))dfs(x+dx[i],y+dy[i],s[x+dx[i]][y+dy[i]]);
//     }
// }

// int main(){
// cin>>n>>m;
// for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>s[i][j];
// ll ans=0;
// for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
//     if(valid(i,j)){
//         ans++;
//         dfs(i,j,s[i][j]);
//     }
// }
// cout<<ans<<endl;
 

// }



 
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

vector<int>vx={-1,1,0,0};
vector<int>vy={0,0,1,-1};
vector<string>nod;
int n,m; 
int idx=-1;
vector<int>dep;

void solve(){

    cin>>n>>m;
    string w; 
    int si,sj,ei,ej;
    nod=vector<string>(n);
    for(int i=0;i<n;i++){
        cin>>nod[i];
        for(int j=0;j<m;j++){
            if(nod[i][j]=='A'){
                si=i;
                sj=j;
            }
            else if(nod[i][j]=='B'){
                ei=i;
                ej=j;
            }
        }
    }



    vector<vector<pair<int,int>>>par(n,vector<pair<int,int>>(m));
    vector<vector<int>>vis(n,vector<int>(m,0));
    queue<pair<int,int>>q;
    q.push({si,sj});
    vector<char>ans;




    int c=0;
 
    while(q.size()){
        int fs=q.front().first, se=q.front().second;
        vis[fs][se]=1;
        q.pop();

        if(nod[fs][se]=='B'){
            while(fs!=si||se!=sj){
                // cout<<fs<<' '<<se<<endl;
                int prex=par[fs][se].first, prey=par[fs][se].second;
                if(prex-fs==-1&&prey-se==0)ans.push_back('D');
                else if(prex-fs==1&&prey-se==0)ans.push_back('U');
                else if(prex-fs==0&&prey-se==1)ans.push_back('L');
                else ans.push_back('R');
                fs=prex;
                se=prey;
            }
            break;
        }
    
        for(int k=0;k<4;k++){
            int x=fs+vx[k], y=se+vy[k];
            if(x>=0&&x<n&&y>=0&&y<m&&(!vis[x][y])&&nod[x][y]!='#'){
                q.push({x,y});
                vis[x][y]=1;
                par[x][y]={fs,se};
            }
        }
    }

       
    if(ans.size()){
        yes;
        cout<<ans.size()<<endl;
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
        }
        cout<<endl;
    }
    else no;

}   


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;

}



















