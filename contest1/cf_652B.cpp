#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    vector<int> res(n);
    int mid = (n+1)/2; // split point
    vector<int> small(a.begin(), a.begin()+mid);
    vector<int> large(a.begin()+mid, a.end());
    
    int s = 0, l = 0;
    for(int i=0;i<n;i++){
        if(i%2==0) res[i] = small[s++];
        else res[i] = large[l++];
    }
    
    // Check if the result is valid z-sorted
    bool ok = true;
    for(int i=1;i<n;i++){
        if(i%2==1){ // even index (1-based)
            if(res[i] < res[i-1]) ok = false;
        } else {    // odd index (i>1)
            if(res[i] > res[i-1]) ok = false;
        }
    }
    
    if(ok){
        for(int x: res) cout << x << " ";
    } else cout << "Impossible";
    
    return 0;
}

