// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int binarySearch(int a[], int s, int e, int num){

        if(s<=e){
            int mid = (s+e)/2;
            if(a[mid] == num){
                return mid;
            }
            else if(a[mid] > num){
                return binarySearch(a, s, mid - 1, num);
            }
            else{
                return binarySearch(a, mid + 1, e, num);
            }
        }
        else{
            return -1;
        }
    }
    int doUnion(int a[], int n, int b[], int m)  {
        int count = 0;
        if(n>m){
            bool flag = false;
            
            sort(b, b + m);
            for(int i =0; i<n; i++){
               flag = false;
                
                if(binarySearch(b, 0, m - 1, a[i]) == -1){
                   count += 1;
                }
              
            }
            count += m;
            sort(a,a+n);
            for(int i =0; i<n - 1; i++){
                if(a[i] == a[i + 1] ){
                    count -= 1;
                }
            }
            for(int i =0; i<m - 1; i++){
                if(b[i] == b[i + 1] ){
                    count -= 1;
                }
            }
        }
        
        else{
            bool flag = false;
            sort(a, a+n);
            for(int i =0; i<m; i++){
                flag = false;
                
                if(binarySearch(a, 0, n - 1, b[i]) == -1){
                    count++;
                }
               
            }
            count += n;
            
            sort(b,b+m);
            for(int i =0; i<m - 1; i++){
                if(b[i] == b[i + 1] ){
                    // cout<<"count decreased for"<<b[i];
                    count -= 1;
                    // cout<<"count is now"<<count;
                }
            }
            for(int i =0; i<n - 1; i++){
                if(a[i] == a[i + 1] ){
                    // cout<<"count decreased for"<<b[i];
                    count -= 1;
                    // cout<<"count is now"<<count;
                }
            }
        }
        
        
        
        return count;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
