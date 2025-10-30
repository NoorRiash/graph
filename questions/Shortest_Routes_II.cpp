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
ll inf=2e18;

// floyd, time: n*n*n
void solve() {


    // this input for undirected 
    int q;
    cin>>n>>m>>q;
    
    ll arr[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j]=inf;
        }
        arr[i][i]=0;
    }

    ll x,y,z; 
    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        // لانه ممكن يكون في طريقين وكل واحد وزن ف بوخذ الاقل 
        arr[x][y]=min(z,arr[x][y]);
        arr[y][x]=min(z,arr[y][x]);
    }

    for(int k=1;k<=n;k++){ // الوسيط
        for(int i=1;i<=n;i++){ // البداية 
            for(int j=1;j<=n;j++){ // النهاية
                arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]); 
            }
        }
    }

    while(q--){
        cin>>x>>y;
        if(arr[x][y]==inf){
            cout<<-1<<endl;
        }
        else cout<<arr[x][y]<<endl;
    }

}

int main(){

    SLAY
    int t=1;
    // cin>>t;
    while(t--) solve();

}


