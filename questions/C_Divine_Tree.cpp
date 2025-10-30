
// q link: https://codeforces.com/problemset/problem/2120/C

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

    ll n,k; cin>>n>>k; 
    vector<ll>v;  

    ll mx=n*(n+1)/2;
    if(mx<k||k<n){
        cout<<-1<<endl;
        nl;
    }   

    vector<ll>mp(n+1,0);  ll cnt=1;
    for(ll i=n;i>=1;i--){
        mp[i]=cnt;
        cnt++;
    }

    ll num=n; //  الرقم الي وصلته وبدي اجرب اوخذه
    ll tem=n-1; // المتبقي على فرض اني بدي احط واحد للي ضايل
    ll c=0;// مجموع الارقام الي اخذتها 
    cnt=0;
    bool f=1;
  
    while(tem){

        if(c+num+tem<=k&&(mp[num]-cnt)>0){
            v.push_back(num);
            tem--;
            c+=num;
            mp[num]--;
            cnt++;
        }

        else{
            while(c+num+tem>k||(mp[num]-cnt)<=0){
                num--;
                if(num==1)f=0;
            }
            if(f){
                c+=num;
                v.push_back(num);
                tem--;
                mp[num]--;
                cnt++;
            }
        }

        if(!f)break;

    }

    while(v.size()!=n) v.push_back(1);
    

    set<ll>s;
    for(int i=1;i<=n;i++)s.insert(i);

    int si=v.size();
    ll lst=-1;
    int i=0;
    vector<ll>ans;
    f=0;

    while(i<si){

        if(s.count(v[i])){
            ans.push_back(v[i]);
            s.erase(v[i]);
            f=0;
        }
        else{
            ans.push_back(*s.rbegin());
            lst=*s.rbegin();
            s.erase(lst);
            f=1;
        }
        i++;

    }

    int siz=ans.size();
    cout<<v[0]<<endl;
    for(int i=0;i<siz-1;i++)cout<<ans[i]<<' '<<ans[i+1]<<endl;

}
 

int main(){
    SLAY
    int t=1;
    cin>>t;
    while(t--) solve();
}


