// DP : Space optimized , edit-distance algorithm

#include <bits/stdc++.h>

#define ull         unsigned long long int
#define ll          long long int
#define pb(x)       push_back(x)
#define ALLONS_Y    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define debug(x)    cout << #x << " = " << x << endl

// #define DEBUG 1

using namespace std;

int editDistance(string s1,string s2){
    
    int m = s1.size();
    int n = s2.size();

    int table[2][n+1];            
        
    for(int i = 0; i <= n; i++)
        table[0][i] = i;    
        
    
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= n; j++){

            if(j == 0){
                table[i%2][j] = i;             
            }
            else if(s1[i-1] == s2[j-1]){
                table[i%2][j] = table[(i-1) % 2][j-1];
            }else{
                table[i%2][j] = min(table[(i-1)%2][j-1],table[(i-1)%2][j]);
                table[i%2][j] = min(table[i%2][j],table[i%2][j-1]) + 1;                
            }
        }                
    }

    return table[m%2][n];
}

int main() {
    ALLONS_Y;
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    string s1,s2;

    cin >> s1 >> s2;

    cout << editDistance(s1,s2) << endl;

    return 0;
}