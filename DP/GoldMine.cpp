// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#include <cmath>

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
         int DP[n][m] = {0};
        int maxi = 0;
        for(int q = 0; q<n; q++){
            for(int p = 0; p<m; p++){
                DP[q][p] = 0;
            }
        }
        int p = 0;
        int it = sqrt(n*m);
        while(p< it ){
            for(int i = 0; i<n; i++){
                for(int j =0; j<m; j++){
                    
                    if(j == 0 && p == 0 ){
                        DP[i][0] = M[i][0];
                    }
    
                    //For Right - Up 
                    if(j + 1 < m && i - 1 >= 0){
                        int temp = DP[i - 1][j + 1];
                        int temp2 = M[i - 1][j + 1] + DP[i][j];  
                        DP[i - 1][j + 1] = max(temp,temp2);
                    }
                    // For Right Down 
                    if(i + 1 < n && j + 1 < m){
                        int temp = DP[i + 1][j + 1];
                        int temp2 = M[i + 1][j + 1] + DP[i][j];
                        DP[i + 1][j + 1] = max(temp, temp2);
                    }            
                    // For Right 
                    if(j + 1 < m){
                        int temp = DP[i][j + 1];
                        int temp2 = M[i][j + 1] + DP[i][j];
                        DP[i][j + 1] = max(temp, temp2);
                    }
                }
            }
            p++;
        }   
        for(int k = 0; k<n; k++){
            // cout<<DP[k][m-1]<<endl;
            maxi = max(maxi, DP[k][m - 1]);
        }
        return maxi;
    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
