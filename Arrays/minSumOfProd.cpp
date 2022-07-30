//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>
class Solution{
    public:
    long long int minValue(int a[], int b[], int n)
    {
        sort(a, a + n);
        sort(b, b + n);
        long long sum = 0;
        int j = n - 1;
        for(int i =0; i<n; i++){
            int temp = a[i] * b[j];
            sum += temp;
            j--;
        }
        return sum;
    }
    
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, i;
         cin>>n;
         int a[n], b[n];
         for(i=0;i<n;i++)
         cin>>a[i];
         for(i=0;i<n;i++)
         cin>>b[i];
         Solution ob;
         cout<< ob.minValue(a, b, n) <<endl;
     }
	
	return 0;
}
// } Driver Code Ends
