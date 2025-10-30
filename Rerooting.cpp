
// q link: https://codeforces.com/problemset/problem/1187/E
// مهممممممممم الفكرة كالتالي: بوجد مجموع كل السب تري بعد ما اعمل دفس من اي نود يعني عادي بفرض اي وحدة الروت 
// بعدها بدي اجرب اعمل كل نود هي الروت يعني بعمل ريروتنج 
// وبدي ارجع احسب مجموع السب تري من عندها طبعا هاد الاشي بوخذ كثير وقت 
// باستخدام المعادة (عدد النود الخارجية ناقص عدد النود الداخلية) بقدر اوجد مقدار التغير على مجموع السب تري 
// اذا اعتبرت النود الي واقف عندها روت 





// باختصار بدي اوجد اكبر مجموع سب تري ولازم اجرب كل النودز ك روت ف المعادلة بتختصر علي وبس نود وحدة بوجدها بعدها بصير اوجد مقدار التغير اذا اعتبرت كل نود هي الروت 





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

 
vector<vector<int>>nod;
int n,m; 
vector<int> numsubtree;


ll c=0,ans=0;
void dfs1(int idx,int par,int dep){

    bool f=1;
    numsubtree[idx]=1;
    for(auto it:nod[idx]){
        if(it!=par){
            dfs1(it,idx,dep+1);
            numsubtree[idx]+=numsubtree[it];
        }
    }
    c+=numsubtree[idx];
 
}


void dfs2(ll all,int idx,int par){

    ans=max(ans,all);
    for(auto it:nod[idx]){
        if(it!=par){
            dfs2(1LL*all+(n-numsubtree[it]-numsubtree[it]),it,idx);
        }
    }

}


void solve(){

    cin>>n;
    m=n-1;
    nod=vector<vector<int>>(n);
    numsubtree=vector<int>(n,0);
    
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--; y--;
        nod[x].push_back(y);
        nod[y].push_back(x);
    }

    dfs1(0,-1,0);
    ans=c;
    dfs2(c,0,-1);
    
    cout<<ans<<endl;

}
 

int main(){
    SLAY
    int t=1;
    // cin>>t;
    while(t--) solve();
}

