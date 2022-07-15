// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        
        int length[n + 1] = {0};
];
        
        for(int len = 1; len<=n; len++){
            
            for(int i = 1; i<=len; i++){
                
                int temp = price[i - 1] + length[len - i];
                
                if(temp > length[len]){
                    length[len] = temp;
                    // cut[len] = i;
                }
                
            }
        }
        
        return length[n];
        
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
