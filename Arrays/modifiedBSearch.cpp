// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class pair{
    public:
    int f;
    int s;
};

void binarySearch(int arr[],int l, int r, int num, int *f, int *s)
{   
    if(l<=r){
        int mid = (l + r)/2;
        if(arr[mid] == num){
            if(mid < *f || *f == -1){
                *f = mid;
            }
            if(mid > *s){
                *s = mid;
            }
            binarySearch(arr, l, mid - 1, num, f, s);
            binarySearch(arr,mid + 1, r, num,f,s);
        }
        else if(arr[mid] > num){
            binarySearch(arr,l, mid - 1, num, f, s);
        }
        else{
            binarySearch(arr, mid + 1, r, num, f, s);
        }
    }
    
}
vector<int> find(int arr[], int n, int x)
{
    int m = -1;
    int p = -1;
    int *f = &m;
    int *s = &p;
    binarySearch(arr, 0, n - 1,x, f,s);
    
    vector <int> v = {m,p};
    return v;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends
