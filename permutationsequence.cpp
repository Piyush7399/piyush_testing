#include<bits/stdc++.h>
using namespace std;
string getPermutation(int n, int k) {
    map<int,int> mp;
    for(int i = 1;i <= n; i++){
        mp[i]++;
    }
    int fact[n];
    fact[0] = 1;
    
    for(int i = 1;i < n; i++){
        fact[i] = i*fact[i-1];
    }
    k--;
    int in;
    string ans;
    while(mp.size()>0){
        in = k/fact[n-1];
        auto it = mp.begin();
        int t = in;
        while(t--){
            it++;
        }
        int d = it->first;
        mp.erase(it);
        ans.push_back(d+'0');
        k -= in*fact[n-1];
        n--;
    }
    return ans;
}
int main(){
    int n,k;
    cin >> n >> k;
    string ans = getPermutation(n,k);
    cout << ans << "\n";
}