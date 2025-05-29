

// [[Array]]
// Subarray with given sum
// Count the triplets
// Kadane's Algorithm
// Missing number in array
// Merge two sorted arrays
// Rearrange array alternatively
// Number of pairs
// Inversion of Array
// Sort an array of 0s, 1s and 2s
// Equilibrium point
// Leaders in an array
// Minimum Platforms
// Reverse array in groups
// K’th smallest element
// Trapping Rain Water
// Pythagorean Triplet
// Chocolate Distribution Problem
// Stock buy and sell
// Element with left side smaller and right side greater
// Convert array into Zig-Zag fashion
// Last Index of 1
// Spirally traversing a matrix
// Largest Number formed from an Array


class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        
        long long res=INT_MIN;
        long long sum=0;
        
        for(int i=0;i<n;i++){
            
            sum += arr[i];
            
            res = max(res,sum);
            sum = max(sum,(long long)0);
            
        }
        
        return res;
    }
};


class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        
        vector<int> res({-1,-1});
        
        
        int l=0;
        long long sum=0;
        
        for(int r=0;r<n;r++){
            
            sum+=arr[r];
         
            while(l<r && sum>s){
                sum-=arr[l];
                l++;
            }
            
            if(sum==s){
                res[0]=l+1;
                res[1]=r+1;
                return res;
            }
           
        }
        
        return {-1};
    }
};


//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    
	    int count=0;
	    
	    sort(arr,arr+n);
	    
	    for(int i=n-1;i>=0;i--){
	        
	       
	       int target=arr[i];
	       int l=0;
	       int h=i-1;
	       
	       while(l<h){
	           
	           int t=arr[l]+arr[h];
	           
	           if(t==target){
	               count++;
	               l++;h--;
	           }else if(t<target){
	               l++;
	           }else{
	               h--;
	           }
	           
	           
	       }
	       
	    }
	    
	    return count;
	}
};



//122bbaf9a198e9566cea191f6b11c451__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() 
{
    
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        vector<int> arr(n);
        int ans=0;
        int temp;
        for(int i=0;i<n-1;i++)
        {
            cin>>temp; 
            ans=ans^temp;
        }
        
       
        
        for(int i=1;i<=n;i++)
        {
            ans=ans^i;
        }
        
        cout<<ans<<endl;
        
        
    }




	return 0;
}

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            for(int i=0;i<n;i++){
                
                if(arr1[i]>arr2[0]){
                    
                    swap(arr1[i],arr2[0]);
                    // int k=arr2[0];
                    // arr2[0]=arr1[i];
                    // arr1[i]=k;
                    
                    int t=arr2[0];
                    int j;
                    for(j=0; j+1<m && t>arr2[j+1];j++){
                         arr2[j]=arr2[j+1]; 
                    }
                    arr2[j]=t;
                }
                if(i==n)
                    return;
            }
        } 
};


class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        // code here 
        
        
        int lo=0,mid=0,hi=n-1;
        
        while(mid<=hi){
            
            if(arr[mid]==0){
                swap(arr[lo++],arr[mid++]);
                
            }else if(arr[mid]==1){
                mid++;
            }else if(arr[mid]==2){
                swap(arr[mid],arr[hi--]);
            }
        }
    }
    
};



    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        
        int rightMax=a[n-1];
        vector<int> res;
        
        for(int i=n-1;i>=0;i--){
            
            
            if(rightMax<=a[i]){
                rightMax=a[i];
                res.push_back(rightMax);
            }
            
            
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};


class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	
    	int res=0;
    	int platform=0;
    	
    	int i=0;
    	int j=0;
    	
    	while(i<n){
    	    
    	    if(arr[i]<=dep[j]){
    	        i++;
    	        platform++;
    	        res=max(res,platform);
    	    }else{
    	        j++;
    	        platform--;
    	    }
    	}
    	
    	return res;
    }
};

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	
    	multiset<pair<int,char>> ms;
    	
    	for(int i=0;i<n;i++){
    	    ms.insert({arr[i],'a'});
    	    ms.insert({dep[i],'d'});
    	}
    	
    	
    	int res=0;
    	int platform=0;
    	
    	
    	for(auto it:ms){
    	    char t = it.second;
    	    
    	    if(t=='a'){
    	        platform++;
    	    }else{
    	        platform--;
    	    }
    	    
    	    res=max(res,platform);
    	}
    	
    	return res;
    }
};


//94088b67a65e8e28d9fbcac3b7bd8e27__C3
172.31.29.111
#include <bits/stdc++.h>


using namespace std;


void reverse_array(vector<int> input,int k)
{
    
    int n=input.size();
    
    for(int i=0;i<n;i+=k)
    {
        int l=i;
        int j=min(n-1,i+k-1);
        while(l<j)
        {
            swap(input[l],input[j]);
            l++;
            j--;
        }

    }
    
    
    for(int i=0;i<n;i++)
    {
        cout<<input[i]<<" ";
    }
    
}

int main() {
	//code
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    
	    int n;
	    cin>>n;
	    
	    vector<int>input(n);
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>input[i];
	    }
	    
	    int k;
	    cin>>k;
	    
	    reverse_array(input,k);
	    
	    cout<<"\n";
	    	        
	}
	
	return 0;
}



class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        
        vector<int> L(n);
        vector<int> R(n);
        
        L[0] = arr[0];
        R[n-1] = arr[n-1];
        
        for(int i=1;i<n;i++){
            L[i] = max(L[i-1],arr[i]);
        }
        
        
        for(int i=n-2;i>=0;i--){
            R[i] = max(R[i+1],arr[i]);
        }
        
        
        long long water=0;
        
        for(int i=0;i<n;i++){
            water += min(L[i],R[i])-arr[i];
        }
        
        return water;
    }
};


//27a21c901149d0aff108c8d66b70876d__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() {



    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            arr[i]*=arr[i];
        }
        
        
        
        sort(arr.begin(),arr.end());
               
        int flag=0;
        for(int i=n-1;i>=2;i--)
        {                        
            int l=0;
            int r=i-1;
            
            while(l<r)
            {
                                
                if(arr[l]+arr[r]==arr[i])
                {
                   flag=1;
                    break;
                }
                                
                if(arr[l]+arr[r]<arr[i])
                {
                    l++;
                }
                else
                {
                    r--;
                }                                                
            }
                        
            if(flag)
                break;            
        }
        
        if(flag)
        {
            cout<<"Yes";
        }
        else
        {
            cout<<"No";
        }
        
        cout<<endl;   
    }

	return 0;
}


//d7d051757cfae79f57c466eb5f47f31b__C3
172.31.29.111
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    
    
    int t;
    cin>>t;
    
    
    while(t--)
    {
        
        int n;
        
        cin>>n;
        
        vector<int> input(n,0);
        
        for(int i=0;i<n;i++)
        {
            cin>>input[i];
            
            // cout<<input[i];
        }
        
        int s;
        cin>>s;
           
        
        // if(n<s)
        // {
        //     cout<<-1<<"\n";
        //     continue;
        // }
        
        // cout<<"sorted array\n";
        sort(input.begin(),input.end());
        
        // for(int i:input)
        //     cout<<i<<" ";
        
        // cout<<"\n";
        
        int diff=INT_MAX;
        
        for(int i=0;i+s-1<n;i++)
        {
            diff=min(diff,(input[i+s-1]-input[i]));
        }
        
       

        cout<<diff;
        cout<<"\n";
        
    }
	return 0;
}



int findElement(int arr[], int n) {
    
    int res=-1;
    
    
    vector<int> leftMax(n,0);
    vector<int> rightMin(n,0);
    
    leftMax[0]=INT_MIN;
    rightMin[n-1]=INT_MAX;
    
    for(int i=1;i<n;i++){
        leftMax[i]=max(leftMax[i-1],arr[i-1]);
    }
    
    for(int i=n-2;i>=0;i--){
        rightMin[i]=min(rightMin[i+1],arr[i+1]);
    }
    
    // for(int t:leftMax){
    //     cout<<t<<" ";
    // }
    
    // cout<<endl;
    
    // for(int t:rightMin){
    //     cout<<t<<" ";
    // }
    
    // cout<<endl;
    
    for(int i=1;i<n-1;i++){
        if(arr[i]>=leftMax[i] && arr[i]<=rightMin[i]){
            res=i;
            break;
        }
    }
    
    
    if(res==-1)
        return -1;
    
    return arr[res];
   
    
}


//8e3268bc07745751f5eedae5dff7301c__C3
172.31.29.111
#include <bits/stdc++.h>

using namespace std;

int main() 
{
    
    
    
    int t;
    cin>>t;
    
    while(t--)
    {
        
        int n;
        cin>>n;
        
        vector<int> input(n);
        
        
        for(int i=0;i<n;i++)
        {
            cin>>input[i];
        }
        
        int flag=1;
        
        
        for(int i=0;i<n-1;i++)
        {
 
            
            if(flag)
            {
                if(input[i]>input[i+1])
                {
                    swap(input[i],input[i+1]);
                }
                flag=0;
            }
            else
            {
                
                if(input[i]<input[i+1])
                {
                    swap(input[i],input[i+1]);
                }
                flag=1;
                
            }
     
        }

        for(int i=0;i<n;i++)
        {
            cout<<input[i]<<" ";
        }
        cout<<"\n";
        
        
    }

	return 0;
}


//25adbbb96ae19b7c7b614daf38243485__C3
172.31.38.5
#include <bits/stdc++.h>

using namespace std;

void print_matrix(vector<vector<int>> mat,int m,int n)
{
    
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<mat[i][j]<<" ";
        //     }
        // }
        
        
        int rb=0;
        int re=m-1;
        int cb=0;
        int ce=n-1;
        
        int k;
        
        while(rb<=re && cb<=ce)
        {
            
            for(k=cb;k<=ce;k++)
            {
                cout<<mat[rb][k]<<" ";
            }
            
            
           
            rb++;
            
            
            for(k=rb;k<=re;k++)
            {
                cout<<mat[k][ce]<<" ";
            }
            
            ce--;
           
            
            if(rb<=re)
            {
                
                            for(k=ce;k>=cb;k--)
                            {
                                cout<<mat[re][k]<<" ";
                            }
                            re--;
          
            }
            
            
            //  break;
            
            if(cb<=ce)
            {
                
                            for(k=re;k>=rb;k--)
                            {
                                cout<<mat[k][cb]<<" ";
                            }
                            cb++;
          
            }
    
        }    
}



int main() 
{
    
    
    int t;
    cin>>t;
    
    
    while(t--)
    {
        
        int m,n;
        cin>>m;
        cin>>n;
        
        vector<vector<int>> mat(m,vector<int>(n));
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>mat[i][j];
            }
        }


        print_matrix(mat,m,n);
        
        cout<<"\n";
        
        
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<mat[i][j]<<" ";
        //     }
        // }
        
    
        
    }
	
	return 0;
}



//User function template for C++
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(vector<string> &arr) {
	    // code here
	    
	    sort(arr.begin(),arr.end(),[&](string a,string b){
	        return a+b > b+a;
	    });
	    
	    
	    string res="";
	    
	    for(auto &it:arr){
	        res+=it;
	    }
	    
	    return res;
	}
};




// [[string]]
// Reverse words in a given string
// Permutations of a given string
// Longest Palindrome in a String
// Recursively remove all adjacent duplicates
// Check if string is rotated by two places
// Roman Number to Integer
// Anagram
// Remove Duplicates
// Form a Palindrome
// Longest Distinct Characters in the string
// Implement Atoi
// Implement strstr
// Longest Common Prefix


//dd32f44321b7c1226c6e882fd17fb275__C3
14.139.82.6
#include <bits/stdc++.h>
using namespace std;


void reverse(string &str,int i,int j)
{
    int l=i;
    int h=j;
    
    while(l<h)
    {
        char t=str[l];
        str[l]=str[h];
        str[h]=t;
        
        l++;
        h--;
    }
}

int main() 
{
    int t;
    
    cin>>t;
    
    while(t--)
    {
        
        string str;
        
        cin>>str;
                        
        int n=str.size();
        
        int i=0;
        int j=0;
        int wc=0;
        
        // cout<<"input "<<str<<endl;
        
        // reverse(str,0,n-1);
        
        // cout<<"reverse "<<str<<endl;
        
        while(i<n)
        {
            
            j=i;
            while(i<n && str[i]!='.')
            {
                i++;
                
                // cout<<str[i]<<" ";
            }
            
            reverse(str,j,i-1);
            
            str[i]='.';
            i++;
 
        }
                
        reverse(str.begin(),str.end());
        
        cout<<str<<endl;
        
    }
    return 0;
}

//74700b9d6be32900408cadf0adf657f9__C3
14.139.82.6
#include <bits/stdc++.h>
using namespace std;

void permute_sequence(string str,int start,int end,vector<string> &res)
{
    
    if(start==end)
    {
        // cout<<str<<" ";
        res.push_back(str);
    }
    
    
    for(int i=start;i<=end;i++)
    {
        swap(str[i],str[start]);
        permute_sequence(str,start+1,end,res);
        swap(str[i],str[start]);
    }
    
}

int main() 
{
	//code
	
	int t;
	cin>>t;
	
	t=t+1;
	while(t--)
	{
	    
	    
	    string str;
	    
	    getline(cin,str);
	    
	    if(str.empty())
	        continue;
	        
	   vector<string> res;
	        
	    permute_sequence(str,0,str.size()-1,res);
	    
	    sort(res.begin(),res.end());
	    
	    for(string t:res)
	        cout<<t<<" ";
	    
	    
	    cout<<endl;
	    	    	    
	}
	
	return 0;
}


class Solution {
  public:
    string longestPalin (string S) {
        // code here
        
        
        // int res=0;
        int st=0;
        int n = S.size();
        string res="";
        
        for(int i=0;i<n;i++){
            
            int l=i;
            int r=i;
            
            while(l>=0 && r<n && S[l]==S[r]){
                
                if(res.size()<r-l+1)
                    res=S.substr(l,r-l+1);
                
                // cout<<res<<endl;
                
                l--;
                r++;
            }
            
            l=i;
            r=i+1;
          
           while(l>=0 && r<n && S[l]==S[r]){
                
                if(res.size()<r-l+1)
                    res=S.substr(l,r-l+1);
            
                // cout<<res<<endl;
                l--;
                r++;
            }
          
            
            
        }
        
        return res;
    }
};


//1d2fa413e362cf55346fda4012eacf11__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() {
	//code

    int t;
    cin>>t;
    
    while(t--)
    {
        
        string str;
        cin>>str;
        
        
        int flag=1;
        
        while(flag)
        {
            
            int i=0;
            int j=0;
            int n=str.size();
            flag=0;
            
            for(;i<n;)
            {
                
                char temp=str[i];
                int c=0;
                while(temp==str[i])
                {
                    c++;
                    i++;
                }
                
                if(c==1)
                {
                    str[j++]=temp;
                }
                
            }
            
            str.resize(j);
            
            if(n!=str.size())
            {
                flag=1;
            }
                
            
        }        
        cout<<str<<endl;
    }
	return 0;
}


class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        
        int n=str1.size();
        
        string leftRotate = str1.substr(2)+str1.substr(0,2);
        string rightRotate = str1.substr(n-2,2)+str1.substr(0,n-2);
        
        if(leftRotate==str2 || rightRotate==str2){
            return 1;
        }
        
        return 0;
    }

};

//3378a0a8b9b3ca718713b12006995cb9__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() {
	//code
	
	int t;
	cin>>t;
	
	
	
	unordered_map<char,int> m={
	                            {'M',1000},
	                           
	                            {'D',500},
	                           
	                            {'C',100},
	                           
	                            {'L',50},
	                            
	                            {'X',10},
	                            
	                            {'V',5},
	                            
	                            {'I',1},
	                        
	
                            	};
	
	
	t=t+1;
	while(t--)
	{
	    
	    string s;
	    
	    getline(cin,s);
	    
	    if(s.empty())
	        continue;
	    
	    int val=m[s.back()];
	    
	    int n=s.size();
	    
        for(int i=n-2;i>=0;i--)
	    {
	        
	        
	        if(m[s[i]]<m[s[i+1]])
	        {
	            
	            val-=m[s[i]];
	            
	        }
	        else
	        {
	            
	            val+=m[s[i]];
	            
	        }
	        
	    }
	    
	    cout<<val<<endl;
	    
	}
	
	return 0;
}

//80d667ded88c982ba7616faaa83a4a21__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() {
	//code
	
	int t;
	cin>>t;
	
	
	
	
	while(t--)
	{
	    string str1;
	    string str2;
	    
	    cin>>str1;
	    cin>>str2;
	    
        vector<int>count(256,0);
        
        if(str1.size()!=str2.size())
        {
            cout<<"NO"<<endl;
            continue;
        }
            
            
        
        for(int i=0;i<str1.size();i++)
        {
            count[str1[i]]++;
            count[str2[i]]--;
        }
        
        int flag=0;
        for(int i:count)
        {
            if(i!=0)
            {
                flag=1;
                break;
            }
        }
	    
	    if(flag)
	    {
	        cout<<"NO";
	    }
	    else
	    {
	        cout<<"YES";
	    }
		    
	}

	return 0;
}


//37a19d0e3f1ab378daf89f2d223a10b9__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin>>t;
    
    t=t+1;
    while(t--)
    {
        
        string str;
        // cin>>str;
        
        getline(cin,str);
        
        if(str.empty())
            continue;
            
        vector<int> dp(256,0);
        
        int j=0;
        int flag;
        for(int i=0;i<str.size();i++)
        {
            
          
            
            if(dp[str[i]]==0)
            {
                str[j]=str[i];
                j++;
                dp[str[i]]=1;
                flag=0;
            }
        }
        
        str.resize(j);
        
        cout<<str<<endl;
    }
    
    
	return 0;
}


//350c9b71aa8ed98b671c45d7250b3807__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;


int lcs(string str1,string str2)
{
    
    int m=str1.size();
    int n=str2.size();
    
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            
            
            if(i==0 ||j==0)
            {
                dp[i][j]=0;
            }
            else if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
            
            
            
            
        }
    }
    
    return dp[m][n];
    
    
    
}




int main() {

    int t;
    cin>>t;
    
    while(t--)
    {
        
        string str;
        cin>>str;
        
        string rev(str);
        
        reverse(str.begin(),str.end());
        
        int n=str.size();
        
        int l=lcs(str,rev);
        
        
       
        // cout<<str<<"  ";
        cout<<n-l<<endl;
        
        
    }
	return 0;
}


int longestSubstrDistinctChars (string S)
{
    // your code here
    
    
    unordered_map<char,bool> umap;
    
    int res=0;
    int l=0;
    int r=0;
    int n=S.size();
    
    for(;r<n;r++){
        
        
        if(umap[S[r]]){
            
            
            while(umap[S[r]] && l<r){
                 umap[S[l]]=0;
                 l++;
            }
            
        }
        
        umap[S[r]]=1;
        res=max(res,r-l+1);
        
    }
    
    
    return res;
    
}


//549c888cb643add8db9fd293b4f0a2e4__C3
14.139.82.6

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method */
int atoi(string str)
{
    //Your code here
    
    int sign=1;
    if(str[0]=='-')
    {
        sign=-1;
    }
    
    int res=0;
    
    for(char c:str)
    {
        if(c=='-')
            continue;
        
        if(c>='0' && c<='9')
        {
            res=res*10+(c-'0');
        }
        else
        {
            return -1;
        }
    }
        
    return sign*res;
    
}



//eb706152bbcdd9d999783ac1f34e1bfb__C3
14.139.82.6

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
     //Your code here
     
     int m=s.size();
     int n=x.size();
     int j;
     for(int i=0;i<m-n+1;i++)
     {
         
         
         for(j=0;j<n;j++)
         {
             
             if(s[i+j]!=x[j])
             {
                 break;
             }
             
         }
         
         if(j==n)
         {
             return i;
         }
     }
     
     return -1;  
     
}


//a36336120563b843977c4d2f7a1caad2__C3
14.139.82.6
#include <bits/stdc++.h> 

using namespace std;

int main() 
{

    int t;
    
    cin>>t;
    
    while(t--)
    {
        
        int n;
        cin>>n;
        
        vector<string> str;
        
        string ans;
        
        while(n--)
        {
            string s;
            cin>>s;
            str.push_back(s);
            // cout<<str.back()<<endl;
        }
        
        // cout<<endl;
        ans=str[0];
        
        int sn=str.size();
        
        for(int i=1;i<sn;i++)
        {
            
            // ans.resize(str[i].size());
            
            for(int j=0;j<ans.size();j++)
            {
                
                
                if(ans[j]!=str[i][j])
                {
                    ans.resize(j);
                    break;
                }
            }
            
            
        }
        
        
        if(ans.empty())
        {
            cout<<"-1";
        }
        cout<<ans<<endl;
        
    }
	return 0;
}


// [[Linked List]]
// Finding middle element in a linked list
// Reverse a linked list
// Rotate a Linked List
// Reverse a Linked List in groups of given size
// Intersection point in Y shaped linked lists
// Detect Loop in linked list
// Remove loop in Linked List
// n'th node from end of linked list
// Flattening a Linked List
// Merge two sorted linked lists
// Intersection point of two Linked Lists
// Pairwise swap of a linked list
// Add two numbers represented by linked lists
// Check if Linked List is Palindrome
// Implement Queue using Linked List
// Implement Stack using Linked List
// Given a linked list of 0s, 1s and 2s, sort it
// Delete without head pointer


//d6f352d5b3ae2acbe73c65d7191c0b4d__C3
172.31.38.5

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node 
struct Node {
    int data;
    Node* next;
}; */
/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   // Your code here
   struct Node* slow=head;
   struct Node* fast=head;
   
   struct Node* prev;
   
   while(fast && fast->next)
   {
       prev=slow;
       slow=slow->next;
       fast=fast->next->next;
   }
   
   if(fast!=NULL)
   {
       return slow->data;
   }
   
   return slow->data;
   
   
}

/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        struct Node* curr,*prev=NULL,*next=NULL;
        curr=head;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    
};
    

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        Node* temp=head;
        Node* prev=NULL;
        
        for(int i=0;i<k;i++){
            prev=temp;
            temp = temp->next;
        }
        
        if(!temp){
            return head;
        }
        
        prev->next=NULL;
        
        Node* temp1 = temp;
        
        while(temp1->next!=NULL){
            temp1 = temp1->next;
        }
        
        temp1->next = head;
        
        return temp;
        
    }
};

/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        
        if(!head){
            return head;
        }
        
        struct node* current=head;
        struct node* prev=NULL;
        struct node* next=NULL;
        
        int c=0;
        
        while(current!=NULL && c<k){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            c++;
        }
        
        if(head){
            head->next=reverse(next,k);
        }
        
        return prev;
        
        
    }
};


//6d63e3e3efb3bf002b336f592a5412bb__C3
14.139.82.6

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node 
struct Node {
    int data;
    struct Node* next;
}; */
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    struct Node* current1=head1;
    struct Node* current2=head2;
    
    
    while(current1!=current2)
    {
        current1=current1?current1->next:head2;
    
        current2=current2?current2->next:head1;
    }
    
    
    if(current1)
        return current1->data;
        
    return -1;

    
}

//373d4f5d3430ea8030c4dbf3b726fede__C3
14.139.82.6

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of linked list is the following
struct node
{
int data;
node* next;
};*/
int detectloop(struct node *list){
// your code goes here

    struct node * slow=list;
    struct node * fast=list;
    
    
    while(fast && fast->next)
    {
        
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast)
            return 1;
        
        
    }
    
    return 0;
}

//388cf951d82754a582fdff71a3b9b93f__C3
14.139.82.6

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of linked list is the following
struct Node
{
int data;
Node* next; 
};*/
/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *node)
{
     //Your code here
     
    unordered_map<Node*,int>m;
    
    
    struct Node* current=node;
    struct Node* last;
    
    while(current!=NULL)
    {
        
        if(m.find(current)==m.end())
        {
            last=current;
            m[current]++;
            current=current->next;
            
        }
        else
        {
            last->next=NULL;
            current=current->next;
        }
        
    }     
     
}

/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
           // Your code here
           
           Node* one=head;
           
           while(n--){
               
               if(!one){
                   return -1;
               }
               
               one = one->next;
           }
           
           Node* two=head;
           
           while(one!=NULL){
               one = one->next;
               two = two->next;
           }
           
           return two->data;
    }
};




/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node* flatten_merge(Node* root1,Node* root2){
    
    if(!root1){
        return root2;
    }
    
    if(!root2){
        return root1;
    }
    
    if(root1->data<root2->data){
        root1->bottom = flatten_merge(root1->bottom,root2);
        return root1;
    }else{
        root2->bottom = flatten_merge(root1,root2->bottom);
        return root2;
    }
}
    
Node *flatten(Node *root)
{
   // Your code here
   
   if(!root || !root->next){
       return root;
   }
   
   return flatten_merge(root,flatten(root->next));
}


/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    if(head1==NULL)
        return head2;
    
    if(head2==NULL)
        return head1;
        
    if(head1->data<head2->data){
        head1->next=sortedMerge(head1->next,head2);
        return head1;
    }else{
        head2->next=sortedMerge(head1,head2->next);
        return head2;
    }
        
}  

/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        
        Node* ans=NULL;
        Node* cur=ans;
        unordered_map<int,Node*> ump;
        
        while(head2!=NULL){
            ump[head2->data]=head2;
            head2=head2->next;
        }
        
        while(head1!=NULL){
            
            if(ump[head1->data]!=NULL){
                // cout<<head1->data<<" "<<endl;;
                if(ans==NULL){
                    ans=ump[head1->data];
                    cur=ans;
                }else{
                    
                    // cout<<"in "<<head1->data<<endl;
                    
                    // if(cur!=NULL){
                                        cur->next=ump[head1->data];
                    cur=cur->next;
                    // }

                }
                
            }
            
            head1=head1->next;
        }
        
        if(cur)
            cur->next=NULL;
            
        return ans;
    }
};


/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        
        if(!head || !head->next){
            return head;
        }
        
        Node* temp = head->next;
        
        head->next = pairWiseSwap(temp->next);
        
        temp->next = head;
        
        return temp;
        
    }
};

//c87ea5a50ba82c682f33034954a6a356__C3
14.139.82.6

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*struct Node
{
    int data;
   Node* next;
}; */
//write a function returns the resultant linked list

struct Node* reverse(struct Node* head)
{
    
    struct Node* prev=NULL;
    struct Node* current=head;
    struct Node* next;
    
    
    while(current!=NULL)
    {
        struct Node* next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    
    return prev;
}


void print(struct Node* head)
{
    
  
    struct Node* current=head;
    
    
    while(current!=NULL)
    {
        cout<<current->data<<"  ";
        current=current->next;
    }
    
    cout<<"\n";
   
}


Node*  addTwoLists(Node* first, Node* second)
{
  // Code here
  struct Node* current1=first;
  struct Node* current2=second;
  
  
//   print(current1);
//   print(current2);
  
  int carry=0;
  struct Node* head=NULL;
  struct Node* prev=NULL;
  
  int val1,val2,t;
  
  
  while(current1 || current2)
  {
      
      val1=current1?current1->data:0;
      val2=current2?current2->data:0;
      
      t=val1+val2+carry;
      
      struct Node* temp=newNode(t%10);
      
      carry=t/10;
      
      if(!prev)
      {
          head=temp;
      }
      else
      {
          prev->next=temp;
      }
      
      
      prev=temp;
      
      current1=current1?current1->next:NULL;
      current2=current2?current2->next:NULL;
      
      
  }
  
  if(carry>0)
  {
      struct Node* temp=newNode(carry);
      
      prev->next=temp;
  }
  
  return head;

    
}

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
 
    
    bool helper(Node *head,Node *&head1){
        
        if(!head)
            return 1;
            
            
        bool r=helper(head->next,head1);
        
        if(!r){
            return 0;
        }
        
        
        if(head->data==head1->data){
            head1=head1->next;
            return 1;
        }
        
        return 0;
    }
    
    
    bool isPalindrome(Node *head)
    {
       Node* head1=head;
       
       return helper(head,head1);
            
 
        
    }
};

//4d6cd87bee74ca96645cf14783637e42__C3
14.139.82.6

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list node 
struct Node
{
    int data;
    Node* next;
}*/
// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
void deleteNode(Node *node)
{
   // Your code here
   struct Node* temp=node->next;
   
   node->data=temp->data;
   node->next=temp->next;
   
   delete temp;   
}



// [[Stack and Queue]]
// Parenthesis Checker
// Next larger element
// Queue using two Stacks
// Stack using two queues
// Get minimum element from stack
// LRU Cache
// Circular tour
// First non-repeating character in a stream
// Rotten Oranges
// Maximum of all subarrays of size k


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        
        stack<char> st;
        
        
        for(char c:x){
            
            
            if(c=='(' || c=='{' || c=='['){
                
                st.push(c);
            
                
            }else{
                
                
                if(st.empty()){
                    return 0;
                }
                
                if(c==')' && st.top()!='(')
                    return 0;
                    
                if(c==']' && st.top()!='[')
                    return 0;
                
                if(c=='}' && st.top()!='{')
                    return 0;
                
                st.pop();
            }
        }
        
        return st.empty();
    }

};

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        
        stack<int> st;
        vector<long long> res(n,-1);
        
        for(int i=0;i<n;i++){
            
            
            while(!st.empty() && arr[st.top()]<arr[i]){
                res[st.top()]=arr[i];
                st.pop();
            }
            
            st.push(i);
            
        }
        
        return res;
    }
};


/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       
       int st=0;
       int current=0;
       int deficit=0;
       
       for(int i=0;i<n;i++){
           
           current+=(p[i].petrol-p[i].distance);
           
           
           if(current<0){
               deficit+=current;
               st=i+1;
               current=0;
           }
           
       }
       
       if(current+deficit>=0){
           return st;
       }
       
       return -1;
    }
};

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        int m=grid.size();
        int n=grid[0].size();
        
        int freshOrange=0;
        
        queue<pair<int,int>> qu;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                    freshOrange++;
                }
                
                if(grid[i][j]==2){
                    qu.push({i,j});
                }
            }
        }
        
        
        if(freshOrange==0){
            return 0;
        }
        
        int res=0;
        
        // cout<<freshOrange<<"  "<<res<<endl;
        
        vector<int> dirX({-1,0,1,0});
        vector<int> dirY({0,-1,0,1});
        
        
        
        while(!qu.empty()){
            int s=qu.size();
            int flag=0;
            for(int i=0;i<s;i++){
                
                flag=1;
                
                auto t = qu.front();qu.pop();
                int x=t.first;
                int y=t.second;
                
                for(int j=0;j<4;j++){
                    
                    int tx=x+dirX[j];
                    int ty=y+dirY[j];
                    
                    if(tx<0 || ty<0 || tx>=m || ty>=n || grid[tx][ty]==2){
                        continue;
                    }
                    
                    if(grid[tx][ty]==1){
                        qu.push({tx,ty});
                        grid[tx][ty]=2;
                        freshOrange--;
                    }
                }
                
            }
            
            if(flag)
             res++;
            
        }
        
        // cout<<freshOrange<<"  "<<res<<endl;
        
        return freshOrange==0?res-1:-1;
        
        
    }
};

//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        
        vector<int> res;
        
        deque<int> dq(k);
        
        int i;
        for(i=0;i<k;i++){
            
            while(!dq.empty() && arr[dq.back()]<arr[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        
        for(i=k;i<n;i++){
            res.push_back(arr[dq.front()]);
            
            
            while(!dq.empty() && i-k>=dq.front()){
                dq.pop_front();
            }
            
            while(!dq.empty() && arr[dq.back()]<arr[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            
        }
        
        res.push_back(arr[dq.front()]);
        
        return res;
    }
};


// [[Tree]]
// Print Left View of Binary Tree
// Check for BST
// Print Bottom View of Binary Tree
// Print a Binary Tree in Vertical Order
// Level order traversal in spiral form
// Connect Nodes at Same Level
// Lowest Common Ancestor in a BST
// Convert a given Binary Tree to Doubly Linked List
// Write Code to Determine if Two Trees are Identical or Not
// Given a binary tree, check whether it is a mirror of itself
// Height of Binary Tree
// Maximum Path Sum
// Diameter of a Binary Tree
// Number of leaf nodes
// Check if given Binary Tree is Height Balanced or Not
// Serialize and Deserialize a Binary Tree







/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */




void helper(Node* root,vector<int> &res,int hd){
    
    if(!root){
        return;
    }
    
    if(res.size()==hd){
        res.push_back(root->data);
    }
    
    helper(root->left,res,hd+1);
    helper(root->right,res,hd+1);
    
}



//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   
   vector<int> res;
   
   helper(root,res,0);
   return res;
}


//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
  
//   void helper(Node* root,map<int,int> &mp,int hd){
       
//       if(!root){
//           return;
//       }
       
       
//       mp[hd]=root->data;
       
//       helper(root->left,mp,hd-1);
//       helper(root->right,mp,hd+1);
//   }
  
    vector <int> bottomView(Node *root) {
        // Your Code Here
        
        map<int,int> mp;
        vector<int> res;
        
        // helper(root,mp,0);
        

        
        queue<pair<Node*,int>>qu;
        
        qu.push({root,0});
        
        while(!qu.empty()){
            
            Node* temp = qu.front().first;
            int lvl = qu.front().second;
            
            mp[lvl]=temp->data;
            
            qu.pop();
            
            if(temp->left){
                qu.push({temp->left,lvl-1});
            }
            
            if(temp->right){
                qu.push({temp->right,lvl+1});
            }
            
            
        }
        
        
        
        
        for(auto it:mp){
            res.push_back(it.second);
        }
                
        return res;
        
    }
};


class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    
    void helper(Node* root,map<int,vector<int>> &mp,int hd){
        
        if(!root){
            return;
        }
        
        mp[hd].push_back(root->data);
        
        helper(root->left,mp,hd-1);
        helper(root->right,mp,hd+1);
        
    }
    
    
    
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        
        map<int, vector<int>> mp;
        
        // helper(root,mp,0);
        
        
        
        queue<pair<Node*,int>> qu;
        
        qu.push({root,0});
        
        while(!qu.empty()){
            
            Node* tnode = qu.front().first;
            int d=qu.front().second;
            
            qu.pop();
            
            mp[d].push_back(tnode->data);
            
            if(tnode->left){
                qu.push({tnode->left,d-1});
            }
            
            if(tnode->right){
                qu.push({tnode->right,d+1});
            }
            
        }
        
        
        
        
        
        vector<int> res;
        
        for(auto t:mp){
            for(auto v:t.second){
                res.push_back(v);
            }
        }
        
        
        return res;
    }
};

/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */


class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       
       
       queue<Node*> qu;
       qu.push(root);
       
       
       while(!qu.empty()){
            
            int n = qu.size();
            
            Node *prev=NULL;
            
            while(n--){
                
                Node* temp = qu.front();qu.pop();
                
                
                
                if(temp->left){
                    qu.push(temp->left);
                }
                
                if(temp->right){
                    qu.push(temp->right);
                }
                
               if(prev!=NULL){
                   prev->nextRight=temp;
               }
                
                prev=temp;
                // n--;
                
            }
            
            prev->nextRight=NULL;
       }
    }    
      
};


//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            
            
            while(root){
                
                if(root->data > n1 && root->data > n2){
                    root = root->left;
                }else if(root->data < n1 && root->data < n2){
                    root = root->right;
                }else{
                    return root;
                }
            }
            
            return NULL;
        }

};


/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    
    
    void convert(Node* root,Node* &prev,Node* &head){
        
        if(!root){
            return;
        }
        
        convert(root->right,prev,head);
        
        if(prev!=NULL){
            prev->left=root;
            root->right=prev;
        }
        
       
        
        prev=root;
        head=root;
        
        convert(root->left,prev,head);
    }
    
    
    
    
    Node * bToDLL(Node *root)
    {
        // your code here
        
        
        Node* prev=NULL;
        Node* head=NULL;
        
        convert(root,prev,head);
        
        return head;
    }
};


/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    
    
    bool helper(Node* root1,Node* root2){
        
        if(!root1 && !root2){
            return 1;
        }
        
        if(!root1 || !root2){
            return 0;
        }
        
        if(root1->data==root2->data){
            return helper(root1->left,root2->right) && helper(root1->right,root2->left);
        }
        
        return 0;
    }
    
    
    
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    return helper(root,root);
    }
};

//User function template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    //Function to find the height of a binary tree.
    
    int helper(Node* node){
        
        if(!node){
            return 0;
        }
        
        int l=helper(node->left);
        int r=helper(node->right);
        
        return max(l,r)+1;
        
    }
    
    int height(struct Node* node){
        // code here 
        
        return helper(node);
    }
};


/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:


    int helper(Node* root,int &res){
    
        if(!root){
            return 0;
        }
        
        if(!root->left && !root->right){
            return root->data;
        }
        
        int left  = helper(root->left,res);
        int right = helper(root->right,res);
        
        
        if(root->left && root->right){
            
            res = max(res,root->data+left+right);
            
            return root->data+max(left,right);
        }
        else if(!root->left){
            return root->data + right;    
        }else if(!root->right){
             return root->data + left; 
        }
        
        return INT_MIN;
        // return max(left,rig/ht)+root->data;
    }
    
    
    
    
    int maxPathSum(Node* root)
    {
        // code here
        
        int res=INT_MIN;
        
        int k = helper(root,res);
        
        if(!root->left || !root->right){
            return max(k,res);
        }
        
        return res;
    }
};


/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    
    
    int helper(Node* root,int &res){
        
        if(!root){
            return 0;
        }
        
        
        int left  = helper(root->left,res);
        int right = helper(root->right,res);
        
        res = max(res,left+right+1);
        
        return max(left,right)+1;
    }
    
    
    int diameter(Node* root) {
        // Your code here
        
        int res=0;
        
        helper(root,res);
        
        return res;
    }
};

/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    int dfs(Node* root){
        
        if(!root){
            return 0;
        }
        
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        
        if(l==-1 || r==-1 || abs(l-r)>1){
            return -1;
        }
        
        return max(l,r)+1;
    }
    
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return dfs(root)==-1?0:1;
    }
};


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */


class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    
    void helper(Node* root,vector<int> &A){
        
        if(!root){
            A.push_back(-1);
            return;
        }
        
        A.push_back(root->data);
        helper(root->left,A);
        helper(root->right,A);
    }
    
    
    
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int> res;
        
        helper(root,res);
        
        return res;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       
       if(A.size() && A[0]!=-1){
           Node* root=new Node(A[0]);
           A.erase(A.begin());
           root->left=deSerialize(A);
           root->right=deSerialize(A);
           return root;
       }else{
            A.erase(A.begin());
            return NULL;
       }
    }

};



class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    
    
    bool helper(Node* root,Node* min,Node* max){
        
        if(!root){
            return 1;
        }
        
        
        
        if((min && min->data>=root->data) || (max && max->data<=root->data)){
            return 0;
        }
        
        
        bool l=helper(root->left,min,root);
        bool r=helper(root->right,root,max);
        
        return l&&r;
    }
    
    bool isBST(Node* root) 
    {
        // Your code here
        
        return helper(root,NULL,NULL);
    }
};



/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


void dfs(Node* root,int level,vector<int> &res,bool flag){
   
    if(!root)
        return;
    
    
    if(level==1){
        res.push_back(root->data);
        return;
    }
    
    if(flag){
        dfs(root->left,level-1,res,flag);
        dfs(root->right,level-1,res,flag);
    }else{
        dfs(root->right,level-1,res,flag);
        dfs(root->left,level-1,res,flag);
    }
}

int height(Node* root){
    
    if(!root)
        return 1;
    
    return 1+max(height(root->left),height(root->right));
}



//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    
    int h=height(root);
    
    vector<int> res;
    int i=1;
    bool flag=false;
    while(i<h){
        
        dfs(root,i,res,flag);
        flag=!flag;
        i++;
    }
    
    return res;
    
    
}


/* A binary tree node


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/


   
class Solution
{
    public:
    //Function to check if two trees are identical.
    
    
    
    
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        
        if(!r1 && !r2){
            return 1;
        }
        
        
        if(!r1 || !r2){
            return 0;
        }
        
        
        if(r1->data==r2->data){
            return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
        }else{
            return 0;
        }
        
    }
};



//User function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/* Should return count of leaves. For example, return
    value should be 2 for following tree.
         10
      /      \ 
   20       30 */
int countLeaves(Node* root)
{
  // Your code here
    if(!root){
        return 0;
    }
    
    if(!root->left && !root->right){
        return 1;
    }
  
    return countLeaves(root->left)+countLeaves(root->right);
  
}



// [[Heap]]
// Find median in a stream
// Heap Sort
// Operations on Binary Min Heap
// Rearrange characters
// Merge K sorted linked lists
// Kth largest element in a stream



class Solution
{
    
    
    priority_queue<int> maxhp;
    priority_queue<int, vector<int>, greater<int>> minhp;
    
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        maxhp.push(x);
        balanceHeaps();
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        minhp.push(maxhp.top()); maxhp.pop();
        
        if(minhp.size()>maxhp.size()){
            maxhp.push(minhp.top());minhp.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxhp.size()>minhp.size()){
            return maxhp.top();
        }else{
            return (minhp.top()+maxhp.top())*0.5;
        }
        
    }
};

//58ecce9353b2527a54371ee7b239de05__C3
14.139.82.6

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Linked list Node structure
struct Node
{
    int data;
    Node* next;
};*/ 
/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
Node *mergek(Node* list1,Node* list2)
{
    
    if(!list1)
        return list2;
        
    if(!list2)
        return list1;
        
        
        
    if(list1->data<list2->data)
    {
        list1->next=mergek(list1->next,list2);
        return list1;
    }
    else
    {
         list2->next=mergek(list1,list2->next);
         return list2;
    }
    
    
}
  
  
  
  
Node * mergeKList(Node *arr[], int N)
{
    
    
    Node* head=arr[0];
    
    int i=1;
    while(i<N)
    {
        head=mergek(head,arr[i]);
        i++;
    }
    
    return head;
       
}


class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        
        vector<int> res(n,-1);
        
        priority_queue<int,vector<int>,greater<>> pq;
        
        for(int i=0;i<n;i++){
            
            pq.push(arr[i]);
            
            if(pq.size()>k){
                pq.pop();
                res[i]=pq.top();
            }else if(pq.size()==k){
                res[i]=pq.top();
            }
            
            
        }
        
        return res;
    }
};



// [[Recursion]]
// Flood fill Algorithm
// Number of paths
// Combination Sum - Part 2
// Special Keyboard
// Josephus problem


long long  numberOfPaths(int m, int n)
{
    // Code Here
    if(m==1||n==1)
        return 1;
        
    return numberOfPaths(m-1,n)+numberOfPaths(m,n-1);
}

/*You are required to complete this method */

class Solution
{
    public:
    
    // int N;
    int recur(int n,int k){
        
        if(n==1){
            return 1;
        }
        
        
        
        return (recur(n-1,k)+k-1)%n+1;
    }
    
    
    int josephus(int n, int k)
    {
       //Your code here
       
      
       
       return recur(n,k);
    }
};


// [[Hashing]]
// Relative Sorting
// Sorting Elements of an Array by Frequency
// Largest subarray with 0 sum
// Common elements
// Find all four sum numbers
// Swapping pairs make sum equal
// Count distinct elements in every window
// Array Pair Sum Divisibility Problem
// Longest consecutive subsequence
// Array Subset of another array
// Find all pairs with a given sum
// Find first repeated character
// Zero Sum Subarrays
// Minimum indexed character
// Check if two arrays are equal or not
// Uncommon characters
// Smallest window in a string containing all the characters of another string
// First element to occur k times
// Check if frequencies can be equal



//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        //Your code here
        
        map<int,int> ump;
        
        for(int n:A1){
            ump[n]++;
            // cout<<n<<" ";
        }
        // cout<<endl;
        
        vector<int> res;
        for(int i=0;i<M;i++){
            if(ump.count(A2[i])){
                while(ump[A2[i]]>0){
                    res.push_back(A2[i]);
                    ump[A2[i]]--;
                }
            }
            
            ump.erase(A2[i]);
            
        }
        
        for(auto t:ump){
            if(ump.count(t.first)){
                while(ump[t.first]>0){
                    res.push_back(t.first);
                    ump[t.first]--;
                }
            }
        }
     return res;   
    } 
};



#include<bits/stdc++.h>
using namespace std;

bool  comp(pair<int,int>a,pair<int,int>b){
    if(a.second!=b.second)
    return a.second>b.second;
    
    return a.first<b.first;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i=0;i<n;i++) cin>>arr[i];
	    
	    unordered_map<int,int> mp;
	    for(auto it:arr) mp[it]++;
	    vector<pair<int,int>> v;
	    for(auto it:mp)
	        v.push_back({it.first,it.second});
	        
	    sort(v.begin(),v.end(),comp);
	    vector<int> ans;
	    
	    for(int i=0;i<v.size();i++){
	        for(int j=1;j<=v[i].second;j++)
	            ans.push_back(v[i].first);
	    }
	    
	    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
	}
	return 0;
}

/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        
        unordered_map<int,int> ump;
        
        int sum=0;
        
        ump[0]=-1;
        
        int res=0;
        
        for(int i=0;i<n;i++){
            
            sum+=A[i];
            
            if(ump.find(sum)==ump.end()){
               
                ump[sum]=i;
                // cout<<sum<<i<<" ";
                
            }else{
                res=max(res,i-ump[sum]);
            }
            
            
        }
        
        return res;
    }
};


//Back-end complete function Template for C++

class Solution{
    public:
        vector<int> common_element(vector<int>v1,vector<int>v2)
    {
        // Your code here
        unordered_map<int,int> numCount;
        
        for(auto i:v1){
            numCount[i]++;
        }
        
        multiset<int> res;
        
        for(auto t:v2){
            if(numCount[t]>0){
                res.insert(t);
                numCount[t]--;
            }
        }
        
        return vector<int>(res.begin(),res.end());
    }
};


//dec6bf5c4e32fdc1df7c324dc18bbde2__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    
    cin>>t;
    
    while(t--)
    {
        int n1,n2;
        
        cin>>n1>>n2;
        
        vector<int> arr1(n1);
        vector<int> arr2(n2);
        
        int sum1=0;
        int sum2=0;
        
        for(int i=0;i<n1;i++)
        {
            cin>>arr1[i];
            sum1+=arr1[i];
        }
        
        for(int i=0;i<n2;i++)
        {
            cin>>arr2[i];
            sum2+=arr2[i];
        }
        int flag=0;
        
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                
                if(sum1-arr1[i]+arr2[j]==sum2+arr1[i]-arr2[j])
                {
                   flag=1;
                   break;
                }
                
            }
        }
        
        
        
        
        if(flag)
        {
            cout<<"1";
        }
        else
        {
            cout<<"-1";
        }
        cout<<endl;
        
        
        
        
        
        
        
        
        
    }





	return 0;
}



class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        
        unordered_map<int,int> ump;
        
        int dist_count=0;
        vector<int> res;
        
        for(int i=0;i<k;i++){
            
            
            if(ump[A[i]]==0){
                dist_count++;
            }
            
            ump[A[i]]++;
        }
        
        res.push_back(dist_count);
        
        for(int i=k;i<n;i++){
            
            ump[A[i-k]]--;
            
            if(ump[A[i-k]]==0){
                dist_count--;
            }
            
            
            
            if(ump[A[i]]==0){
                dist_count++;
            }
            
            ump[A[i]]++;
            
            res.push_back(dist_count);
    
        }
        
        return res;
    }
};

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        
        int n=nums.size();
        if(n&1)
            return 0;
        

        
        map<int,int> m;
        
        for(int i=0;i<n;i++){
           
           nums[i]=nums[i]%k; 
           m[nums[i]]++;    
           
        }
       
       if(m[0]&1)
            return 0;
            
       
        for(int i=0;i<n;i++){
           
           if(nums[i]%k!=0 && m[nums[i]%k]!=m[k-(nums[i]%k)])
                return 0;
           
        }
        
        
        return 1;
    }
};


class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      
      unordered_set<int> uset(arr,arr+N);
      int res=0;
      int len=0;
      
      for(auto t:uset){
          
        //   cout<<t<<" ";
          
          if(uset.find(t-1)==uset.end()){
              len=0;
              int val=t;
              while(uset.find(val)!=uset.end()){
                  len++;
                  val=val+1;
                  res=max(res,len);
              }
          }
          
          
      }
      
      return res;
    }
};

//bc469af977d4dba37cb2a478d9c49a5f__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() 
{
    
    
    int t;
    cin>>t;
    
    while(t--)
    {
        
        int n,m;
        cin>>n>>m;
        
        set<int> s;
        
        for(int i=0;i<m+n;i++)
        {
            int temp;
            cin>>temp;
            s.insert(temp);
        }
        
        
        int e=s.size();
        
        if(e<=n)
        {
            cout<<"Yes";
        }
        else
        {
            cout<<"No";
        }
        
        cout<<endl;
        
        
    }




	return 0;
}


class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here   
        
        set<pair<int,int>> res;
        
        set<int> AS(A,A+N);
        
        for(int i=0;i<M;i++){
            
            if(AS.find(X-B[i])!=AS.end()){
                
                res.insert({X-B[i],B[i]});
                
            }
        
        }
        
        return vector<pair<int,int>>(res.begin(),res.end());
    }
};


//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        
        unordered_map<int,int>ump;
        int count=0;
        int sum=0;
        
        for(int i=0;i<n;i++){
            
            sum+=arr[i];
            
            if(sum==0){
                count++;
            }
            
            if(ump.count(sum)){
                count+=ump[sum];
                
            }
            
            ump[sum]++;
        }
        
        return count;
        
    }
};


//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        // Your code here
        set<char> patSet;
        for(char c:patt){
            patSet.insert(c);
        }
        
        
        for(int i=0;i<str.size();i++){
            if(patSet.find(str[i])!=patSet.end()){
                return i;
            }
        }
        
        return -1;
    }
};


//326c049f0c7977cab4f19341db3b6f4a__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    
    
    int t;
    
    while(t--)
    {
        int n;
        
        vector<int> arr1(n);
        vector<int> arr2(n);
        
        for(int i=0;i<n;i++)
        {
            cin>>arr1[i];
        }
        
        for(int i=0;i<n;i++)
        {
            cin>>arr2[i];
        }
        
        
        
        sort(arr1.begin(),arr1.end());
        
        sort(arr2.begin(),arr2.end());
        
        
        
        int flag=0;
        for(int i=0;i<n;i++)
        {
            
            if(arr1[i]!=arr2[i])
            {
                flag=1;
                break;
            }
        }
        
        
        
        
        
        
        
        
        if(flag)
        {
            cout<<"0";
        }
        else
        {
            cout<<"1";
        }
        cout<<endl;
        
        
        
        
    }
    
    return 0;
}


//493d4ae7aacfa9217755911f947b17d1__C3
183.83.156.2
#include<bits/stdc++.h>

using namespace std;



void printString(string s,string t)
{
    
    int hash_pat[256]={0};
    
    for(int i=0;i<t.size();i++)
    {
        char c=t[i];
        hash_pat[c]++;
        
        // cout<<hash_pat[c-'a']<<endl;
    }
    
    
    int hash_str[256]={0};
     
    int count=0;
    
    int st=-1;
    
    int start=0;
    
    int len=INT_MAX;
    
    int tl=t.size();
    
    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        hash_str[c]++;
        
        
        
        if(hash_pat[c]!=0 && hash_str[c]<=hash_pat[c])
        {
            count++;
            
            // cout<<"c "<<c<<endl;
        }
        if(count==tl)
        {
            
            
            
            
            while(((hash_str[s[start]]>hash_pat[s[start]])||hash_str[s[start]]==0))
            {
                    
                    if(hash_str[s[start]]>hash_pat[s[start]])
                    {
                        hash_str[s[start]]--;
                    }
                    
                    // cout<<"start "<<start<<endl;
                    start++;
            }
            
            
            if((i-start+1)<len)
            {
                len=i-start+1;
                st=start;
                
                // cout<<"st "<<st<<endl;
                
            }
            
            
            
            
            
            
        }
        
        
        
        
    }
    
    
    
    
    if(st!=-1)
    {
        // cout<<st<<endl;
        cout<<s.substr(st,len)<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
    
    // cout<<"123\n";
    
    
}

int main() 
{

    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        string t;
        cin>>s>>t;
        
        if(s.size()<t.size())
        {
            cout<<"-1"<<endl;
            continue;
        }
        
        printString(s,t);
        
    }



	return 0;
}

//f19a7e0492065ae442284bc5c00cd207__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() 
{
    
    int t;
    
    cin>>t;
    
    
    while(t--)
    {
        int n,k;
        
        cin>>n>>k;
        
        vector<int> arr(n);
        
        
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        unordered_map<int,int> dp;
        
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            dp[arr[i]]++;
        }
        
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(dp[arr[i]]==k)
            {
                f=1;
                cout<<arr[i];
                break;
            }
        }
        
        if(f==0)
        {
            cout<<"-1";
        }
        cout<<endl;
        
        
        
        
        
        
        
        
        
    }




	return 0;
}

//b2fb7357b499ba8d7429496e80619c49__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;


int check(vector<int> dp)
{
    
        int i;
        int f;
        for(i=0;i<26;i++)
        {
            if(dp[i]>0)
            {
               f=dp[i];  
                break;
            }
        }
        
        for(int j=i+1;j<26;j++)
        {
            if(dp[j]>0 && dp[j]!=f)
            {
                return 0;
            }
        }
        
        return 1;
    
    
}



int main() 
{


    int t;
    
    cin>>t;
    
    while(t--)
    {
        string str;
        cin>>str;
        
        int n=str.length();
        
        vector<int> dp(26,0);
        
        for(int i=0;i<n;i++)
        {
            
            dp[str[i]-'a']++;
        }
        
        
        
        if(check(dp))
        {
            cout<<"1"<<endl;
            continue;
        }
        
        int f=0;
        
        for(int i=0;i<26;i++)
        {
           
           if(dp[i]>0)
           {
                dp[i]--;
                if(check(dp))
                {
                    f=1;
                    break;
                }
                dp[i]++;
           }
            
         
        
            
            
        }
                
        
        if(f)
        {
            cout<<"1"<<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }
              
    }

	return 0;
}


// [[Graph]]
// Depth First Traversal
// Breadth First Traversal
// Detect cycle in undirected graph
// Detect cycle in a directed graph
// Topological sort
// Find the number of islands
// Implementing Dijkstra
// Minimum Swaps
// Strongly Connected Components
// Shortest Source to Destination Path
// Find whether path exist
// Minimum Cost Path
// Circle of Strings
// Floyd Warshall
// Alien Dictionary
// Snake and Ladder Problem




class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    
    void dfs(int u,vector<int> &visited,vector<int> adj[],vector<int> &res){
        
        
        visited[u]=1;
        res.push_back(u);
        
        for(auto v:adj[u]){
            if(visited[v]==0){
                dfs(v,visited,adj,res);
            }
        }
        
        
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        
        
        vector<int> visited(V,0);
        vector<int> res;
        
        for(int i=0;i<V;i++){
            
            if(visited[i]==0){
                dfs(i,visited,adj,res);    
            }
            
        }
        
        
        return res;
    }
};

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        
        vector<int> res;
        vector<int>  vis(V,0);
        
        queue<int> qu;
        qu.push(0);
        vis[0]=1;
        
        while(!qu.empty()){
            
            int v = qu.front();qu.pop();
            res.push_back(v);
            
            for(int t:adj[v]){
                
                if(vis[t]==0){
                    qu.push(t);
                    vis[t]=1;
                }
            }
        }
        
        
        
        return res;
    }
};

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    
    
    bool dfs(int u, vector<int> &vis, vector<int> adj[],int parent){
        
        
        vis[u]=1;
        
        for(int v:adj[u]){
            
            if(vis[v]==0){
                
                bool t = dfs(v,vis,adj,u);
                
                if(t){
                    return 1;
                }
                
            }else if(v != parent){
                return 1;
            }
            
        }
        
        return 0;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            
            if(vis[i]==0){
            
                bool r=dfs(i,vis,adj,-1);
                
                if(r){
                    return 1;
                }
            
            }
        }
        
        return 0;
        
    }
};

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool helper(int u,vector<int> &visited, vector<int> &stack,vector<int> adj[]){
        
        
        visited[u] = 1;
        stack[u] = 1;
        
        for(int v:adj[u]){
            
            if(visited[v]==0){
                
                bool r = helper(v,visited,stack,adj);
                
                if(r){
                    return 1;
                }
            }else if(stack[v]==1){
                return 1;
            }
        }
        
        stack[u] = 0;
        return 0;
    }
    
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int> visited(V,0);
        vector<int> stack(V,0);
        
        for(int i=0;i<V;i++){
            
            if(visited[i]==0){
                
                bool t = helper(i,visited,stack,adj);
                
                if(t){
                    return 1;
                }
            }
        }
        
        return 0;
        
    }
};


class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs(int u,vector<int> adj[],vector<int> &ans,vector<int> &vis){
	    
	    vis[u]=1;
	    
	    for(auto v:adj[u]){
	        if(!vis[v]){
	           dfs(v,adj,ans,vis); 
	        }
	    }
	    
	    ans.push_back(u);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	    vector<int> indegree(V,0);
	    
	    for(int i=0;i<V;i++){
	        for(auto v:adj[i]){
	            indegree[v]++;
	        }
	    }
	    
	    vector<int> vis(V,0);
	    vector<int> ans;
	    
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            dfs(i,adj,ans,vis);
	        }
	    }
	    
	    reverse(ans.begin(),ans.end());
	    return ans;
	    
	}
};

class Solution {
  public:
    // // Function to find the number of islands.
    //     const vector<int> dirX({-1,0,1,0,-1,1,-1,1});
    //     const vector<int> dirY({0,-1,0,1,-1,-1,1,1});
    
    void dfs(vector<vector<char>> &grid,vector<vector<int>> &vis,int i,int j){
        
        // if(vis[i][j])
        //     return;
        
            if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]=='0'){
                return;
            }
        
        
        vis[i][j]=1;
        grid[i][j]='0';
        
        // // cout<<"c "<<i<<" "<<j<<endl;
         int dirX[8]={-1,0,1,0,-1,1,-1,1};
         int dirY[9]={0,-1,0,1,-1,-1,1,1};

        
        for(int k=0;k<8;k++){
            int tx=i+dirX[k];
            int ty=j+dirY[k];
            

            
            
            // if(grid[tx][ty]=='1')
            //     cout<<tx<<" "<<ty<<endl;
            
            // i
                dfs(grid,vis,tx,ty);
        }
        
        // dfs(grid,vis,i-1,j);
        // dfs(grid,vis,i+1,j);
        // dfs(grid,vis,i,j+1);
        // dfs(grid,vis,i,j-1);
        
        
        // dfs(grid,vis,i-1,j-1);
        // dfs(grid,vis,i+1,j-1);
        // dfs(grid,vis,i-1,j+1);
        // dfs(grid,vis,i+1,j+1);
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int res=0;
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    res++;
                    // cout<<i<<" "<<j<<endl<<endl;
                    dfs(grid,vis,i,j);
                }
            }
        }
        
        return res;
    }
};


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        vector<int> res(V,INT_MAX);
        
        res[S] = 0;
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,S});
        
        while(!pq.empty()){
            
            auto t = pq.top();pq.pop();
            
            int d = t.first;
            int u = t.second;
            
            for(auto tv:adj[u]){
                
                int v = tv[0];
                int w = tv[1];
                
                if(res[v]>d+w){
                    res[v] = d+w;
                    pq.push({res[v],v});
                }
            }
        }
        
        return res;
    }
};



class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
            
            vector<pair<int,int>> numPair;
            
            int n=nums.size();
            
            for(int i=0;i<n;i++){
                numPair.push_back({nums[i],i});    
            }
            
            sort(numPair.begin(),numPair.end());
            
            int res=0;
            for(int i=0;i<n;i++){
                
                // cout<<nums[i]<<"     "<<numPair[i].first<<"  "<<numPair[i].second<<endl;
                // if(nums[i]==)
                auto t=numPair[i];
                int val=t.first;
                int index=t.second;
                
                if(i!=index){
                    // cout<<nums[i]<<"     "<<numPair[i].first<<"  "<<numPair[i].second<<endl;
                    res++;
                    swap(numPair[i],numPair[index]);
                    i--;
                }   
            }
            
            
            return res;
    
	}
};


// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        
        int res=0;
        queue<vector<int>> qu;
        
        
        if(A[0][0]==0){
            return -1;
        }
        
        qu.push({0,0,0});
        
        int dirX[4]={-1,0,1,0};
        int dirY[4]={0,-1,0,1};
        
        while(!qu.empty()){
            auto t=qu.front();qu.pop();
            int i=t[0];
            int j=t[1];
            int d=t[2];
            
            
            if(i==X && j==Y){
                return d;
            }
            
            for(int k=0;k<4;k++){
                int tx=i+dirX[k];
                int ty=j+dirY[k];
               
                if(tx<0 || ty<0 || tx>=N || ty>=M || A[tx][ty]==0){
                    continue;
                }
                
                
                qu.push({tx,ty,d+1});
                A[tx][ty]=0;
                
                
            }
        }
        
        return -1;
    }
};



// User function Template for C++

class Solution
{
    public:
    
    void dfs(map<int,vector<int>> adj,vector<int> &visited,int u){
        
        visited[u]=1;
        
        for(auto v:adj[u]){
            if(visited[v]==0){
                dfs(adj,visited,v);
            }
        }
    }
    
    
    
    int isCircle(int N, vector<string> A)
    {
        // code here
        map<int,vector<int>> adj;
        vector<int> mark(26,0);
        
        vector<int> indegree(26,0);
        vector<int> outdegree(26,0);

        for(int i=0;i<N;i++){
            
            int s=A[i][0]-'a';
            int d=A[i][A[i].size()-1]-'a';
            
            
            mark[s]=1;
            mark[d]=1;
            indegree[d]++;
            outdegree[s]++;
            
            adj[s].push_back(d);
        }
        
        
        vector<int> visited(26,0);



        for(auto t:adj){
            if(visited[t.first]==0){
                dfs(adj,visited,t.first);
                break;
            }
        }
                
        
        for(int i=0;i<26;i++){
            if(mark[i]!=visited[i]){
                return 0;
            }
            if(indegree[i]!=outdegree[i]){
                return 0;
            }
        }

        

        
        return 1;
        
    }
};


// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        
        unordered_map<char,vector<char>> adj;
        // string res;
        unordered_map<char,int> indegree;
        set<char> vertex;
        
        for(int i=0;i<N-1;i++){
                int j=i+1;
                int sl=min(dict[i].size(),dict[j].size());
                for(int k=0;k<sl;k++){
                    
                    if(dict[i][k]!=dict[j][k]){
                        adj[dict[i][k]].push_back(dict[j][k]);
                        indegree[dict[j][k]]++;
                        vertex.insert(dict[i][k]);
                        vertex.insert(dict[j][k]);
                        break;
                    }
                }
        }
        
        queue<char> qu;
        string res="";
        for(auto t:vertex){
            // cout<<t<<" "<<indegree[t]<<endl;
            if(indegree[t]==0){
                qu.push(t);
                res+=t;
            }
        }
        
        int c=0;
        while(!qu.empty()){
            char u=qu.front();qu.pop();
            
            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    qu.push(v);
                    res+=v;
                }
            }
            
        }
        
        return res;
    }
};


// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        
        unordered_map<int,int> ump;
        
        for(int i=0;i<2*N;i=i+2){
            int src=arr[i];
            int dst=arr[i+1];
            ump[src]=dst;
        }
        
        unordered_set<int> visited;
        
        
        
        queue<int> qu;
        
        qu.push(1);
        int res=0;
        int end=30;
        visited.insert(1);
        
        while(!qu.empty()){
            
            int n=qu.size();
            
            while(n>0){
                
                int front=qu.front();qu.pop();
                // cout<<front<<" ";
                if(front>=end){
                    return res;
                }
                
            for(int i=1;i<7;i++){
                
                int temp=front+i;
                
                if(visited.count(temp)==0){
                
                    if(ump.count(temp)){
                        if(ump[temp]>=front){
                        qu.push(ump[temp]);
                        visited.insert(ump[temp]);
                        }
                    }else{
                        qu.push(temp);
                        visited.insert(temp);
                    }
                }
                
            }  
                n--;
            }
            // cout<<endl;
            res++;
        }
        
        return res;
    }
};


// [[Greedy]]
// Activity Selection
// N meetings in one room
// Coin Piles
// Maximize Toys
// Page Faults in LRU
// Largest number possible
// Minimize the heights
// Minimize the sum of product
// Huffman Decoding
// Minimum Spanning Tree
// Shop in Candy Store
// Geek collects the balls



class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        
        // vector<pair<int,int>> vecPair;
        
        priority_queue< pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i=0;i<n;i++){
            // vecPair.push_back({start[i],end[i]});
            pq.push({end[i],start[i]});
        }
        
        int res=0;
        int en=-1;
        
        while(!pq.empty()){
            auto t=pq.top();pq.pop();
            int e=t.first;
            int s=t.second;
            if(t.second>en){
                res++;
                en=t.first;
            }    
            
        }
        
        
        
        // sort(vecPair.begin(),vecPair.end(),[](pair<int,int> p1,pair<int,int> p2){
            
        //     if(p1.first==p2.first)
        //         return p1.second < p2.second;
        //     return p1.first < p2.first;
            
        // });
        
        
        // int e=vecPair[0].second;
        // int res=1;
        
        // for(int i=1;i<n;i++){
            
        //     if(e<vecPair[i].first){
        //         res++;
        //         e=vecPair[i].second;
        //     }
        // }
        
        return res;
        
    }
};

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int res = 0;
        
        for(int i=0;i<n;i++){
            pq.push({end[i],start[i]});
        }
        
        int en = -1;
        
        while(!pq.empty()){
           
            auto t = pq.top();pq.pop();
            
            if(t.second > en){
                res++;
                en = t.first;
            }
        
        }
        
        return res;
    }
};

//9cc57488123e291ce4a32cb088dfa910__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin>>t;
    
    
    while(t--)
    {
        int n,k;
        
        cin>>n;
        cin>>k;
        
        vector<int> arr(n);
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
    
        int ans=INT_MAX;
        int temp=0;
        for(int i=0;i<n;i++)
        {
            temp=0;
            for(int j=0;j<n;j++)
            {
                if(arr[j]<arr[i])
                {
                   temp+=arr[j]; 
                }
                else if(arr[j]>arr[i]+k)
                {
                    temp+=arr[j]-arr[i]-k;
                }
            }
            
            if(temp<ans)
            {
                ans=temp;
            }
        }
        
        cout<<ans<<endl;
    
               
        
    }



	return 0;
}


//User function Template for C++

class Solution{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        // code here
        sort(arr.begin(),arr.end());
        
        int s=0;
        int c=0;
        int i;
        for(i=0;i<N;i++){
            
            if(K<arr[i]){
                break;
            }
            K=K-arr[i];
        }
        
        return i;
    }
};


//069f8fa692453d9e5d0f9d23c0cebf7d__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() 
{


    int t;
    cin>>t;
    
    while(t--)
    {
        
        
        int n;
        
        cin>>n;
        
        vector<int> arr(n);
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        
        
        int k;
        
        cin>>k;
        
        
        deque<int> dp;
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            ans++;
            bool flag=false;
            for(auto it=dp.begin();it!=dp.end();it++)
            {
                if(*it==arr[i])
                {
                    dp.erase(it);
                    dp.push_front(arr[i]);
                    ans--;
                    flag=true;
                    break;
                }
            }
            
            
            
            
            if(flag)
            {
                continue;
            }
            else
            {
                
                if(dp.size()<k)
                {
                    dp.push_front(arr[i]);
                }
                else
                {
                    dp.pop_back();
                    dp.push_front(arr[i]);
                }
                
            }
            
        }
        
         cout<<ans<<endl;
        
             
    }

	return 0;
}


// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        
        string res;
        // while(S>10){
        //     S=S-9;
        //     res=res+to_string(9);
        // }
        
        // if(S>0)
        //     res+=to_string(S);
        
        // for(int i=res.size();i<N;i++){
        //     res+=to_string(0);
        // }
        
        
        
        
        if((S==0 && N>=1)){
            
            if(N==1){
                return "0";
            }
            return "-1";
        }
        
        if(S>9*N){
            return "-1";
        }
        

        
        while(N>0){
            
            if(S>9){
                 S=S-9;
            res=res+to_string(9); 
            }else{
                
                if(S>0){
                    res=res+to_string(S);
                     S=S-9;
                }
                else if(S<=0){
                   res=res+to_string(0); 
                }
            }
            
            N--;
        }
        

        
        return res;
        
        
        
    }
};



// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        
        sort(arr,arr+n);
        
        // int left=arr[0]+k;
        // int right=arr[n-1]-k;
        
        // int diff=arr[n-1]-arr[0];
        
        
        // for(int i=0;i<n-1;i++){
          
        //   int max1=max(right,arr[i]+k);
        //   int min1=min(left,arr[i+1]-k);
            
        //     diff=min(diff,max1-min1);
            
            
        // }
         int left=arr[0]+k;
        int right=arr[n-1]-k;
        
        int res=arr[n-1]-arr[0];
        
        for(int i=0;i<n-1;i++)
        {
            int maxi=max(right,arr[i]+k);
            int mini=min(left,arr[i+1]-k);
            
            if(mini<0)
                continue;
            
            res=min(res,maxi-mini);
        }
 
        
        return res;
        
    }
};


class Solution{
    public:
    long long int minValue(int a[], int b[], int n)
    {
        // Your code goes here
        
        sort(a,a+n);
        sort(b,b+n);
        
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i]*b[n-1-i];
        }
        
        return sum;
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<int> vis(V,0);
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,0});
        
        int sum = 0;
        
        while(!pq.empty()){
            
            auto temp = pq.top();pq.pop();
            
            int u = temp.second;
            int d = temp.first;
            
            if(vis[u]==1){
                continue;
            }
            
            vis[u]=1;
            sum += d;
            
            for(auto t:adj[u]){
                if(vis[t[0]]==0){
                    pq.push({t[1],t[0]});
                }
            }
        }
        
        return sum;
    }
};

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        
        sort(candies,candies+N);
        
        int one=0,two=0;
        int i=0;
        
        int n=N;
        
        // if(K==0||K==1){
            K=K+1;
        // }
        
        
        while(n>0){
            one+=candies[i];
            i++;
            n=n-K;
        }
        
        n=N;
        i=0;
        while(n>0){
            two+=candies[N-1-i];
            i++;
            n-=K;
        }
        
        return {one,two};
    }
};


// User function Template for C++

class Solution{
public:
    int maxBalls(int N, int M, vector<int> a, vector<int> b){
        // code here
     
     
        int i=0;
        int j=0;
        
        int s1=0;
        int s2=0;
        
        while(i<N && j<M){
            
            // cout<<s1<<"  "<<s2<<endl;
            
            if(a[i]<b[j]){
                s1+=a[i];i++;
            }else if(a[i]>b[j]){
                s2+=b[j];j++;
            }else{
             
                int c1=0,c2=0;
                
                int val=a[i];
                
                while(i<N && a[i]==val){c1++;i++;}
                while(j<M && b[j]==val){c2++;j++;}
                
                if(s1>s2){
                    s2=s1+((c1+c2-1)*val);
                    if(c1>1)s1=s1+(c1+c2-2)*val;
                    else s1+=val;
                }else{
                    s1=s2+((c1+c2-1)*val);
                    if(c2>1)s2=s2+(c1+c2-2)*val;
                    else s2+=val;
                }
             
            }
        }
        
        while(i<N){
            s1+=a[i];i++;
        }
        
        while(j<M){
            s2+=b[j];j++;
        }
       
       
       return max(s1,s2);
    }
};


// [[Dynamic Programming]]
// Minimum Operations
// Max length chain
// Minimum number of Coins
// Longest Common Substring
// Longest Increasing Subsequence
// Longest Common Subsequence
// 0 - 1 Knapsack Problem
// Maximum sum increasing subsequence
// Minimum number of jumps
// Edit Distance
// Coin Change Problem
// Subset Sum Problem
// Box Stacking
// Rod Cutting
// Path in Matrix
// Minimum sum partition
// Count number of ways to cover a distance
// Egg Dropping Puzzle
// Optimal Strategy for a Game
// Shortest Common Supersequence


//a273be612a1229505695ea8c520a5d91__C3
157.48.123.65
#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin>>t;
    
    while(t--)
    {
        
        int n;
        cin>>n;
        
        int count=0;
        while(n>0)
        {
            count+=n%2;
            n-=n%2;
            
            if(n<=0)
            {
                break;
            }
            
            n=n/2;
            count++;
            
        }
        
        cout<<count<<endl;
        
        
    }
    




	return 0;
}


#include <bits/stdc++.h>
using namespace std;

struct val 
{
    int first;
    int second;
};

//function that helps to sort the structure p in increasing order of second values
bool static comp(val fst, val sec){
        return fst.second<sec.second;
    }

//function to calculate the max length chain 
int maxChainLen(struct val p[],int n){
        //Your code here
        sort(p,p+n,comp);
        int prev=-1e9;
        int ans=0;
        for(int i=0;i<n;i++){
            if(p[i].first>prev){
                ans++;
                prev=p[i].second;
            }
        }
        return ans;
    }

int main() {


    int n = 5;
    val p[n];
    p[0].first = 5;
    p[0].second = 24;
  
    p[1].first = 39;
    p[1].second = 60;
  
    p[2].first = 15;
    p[2].second = 28;
  
    p[3].first = 27;
    p[3].second = 40;
  
    p[4].first = 50;
    p[4].second = 90;
      
    // Function Call
    cout << maxChainLen(p, n) << endl;
    return 0;
}


//76674ca8cc233ca2ed384bb4ad717bb0__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() 
{


    int t;
    cin>>t;
    
    
    vector<int> arr({1,2,5,10,20,50,100,200,500,2000});
    
    
   
    
    int n=arr.size();
    
    
    
    while(t--)
    {
            int val;
            
            cin>>val;
        
            vector<int> res;
        
            for(int i=n-1;i>=0;i--)
            {
                
                
                if(val>=arr[i])
                {
                    
                    while(val>=arr[i])
                    {
                        val-=arr[i];
                        res.push_back(arr[i]);
                    }
                    
                    
                }
                
                
            }
            
            
            
            
            for(int i:res)
            {
                cout<<i<<" ";
            }
            
            cout<<endl;
            
            
    }
 
	return 0;
}


class Solution{
    public:
    // int ans=0;
    int findCSTR(int i1,int i2,string &S1,string &S2,vector<vector<int>> &dp,int &ans){
        
        if(i1<0 || i2<0){
            return 0;
        }
        
     
        
        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }
        
        int r=0;
        
        if(S1[i1]==S2[i2]){
            r=1+findCSTR(i1-1,i2-1,S1,S2,dp,ans);
        }
        
        findCSTR(i1-1,i2,S1,S2,dp,ans);
        findCSTR(i1,i2-1,S1,S2,dp,ans);

        ans=max(ans,r);
        dp[i1][i2]=r;
        return r;
        
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        findCSTR(n-1,m-1,S1,S2,dp,ans);
        return ans;
    }
};



class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> dp;
       
       for(int i=0;i<n;i++){
           
           auto it = lower_bound(dp.begin(),dp.end(),a[i]);
           
           if(it==dp.end()){
               dp.push_back(a[i]);
           }else{
               *it = a[i];
           }
       }
       
       return dp.size();
    }
};

// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    int helper(int i, int j, int n, int m, string &s1, string &s2, vector<vector<int>> &dp){
        
        if(i>=n){
            return 0;
        }
        
        if(j>=m){
            return 0;
        }
        
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int r=0;
        
        if(s1[i]==s2[j]){
            r = 1+helper(i+1,j+1,n,m,s1,s2,dp);
        }else{
            
            int r1 = helper(i+1,j,n,m,s1,s2,dp);
            int r2 = helper(i,j+1,n,m,s1,s2,dp);
            
            r = max(r1,r2);
        }
        
        return dp[i][j]=r;
        
    }
    
    
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        return helper(0,0,n,m,s1,s2,dp);
    }
};

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    
    int helper(int i, int W,int wt[], int val[], int n, vector<vector<int>> &dp){
        
        if(W<=0){
            return 0;
        }
        
        if(i>=n){
            return 0;
        }
        
        if(dp[i][W]!=-1){
            return dp[i][W];
        }
        
        int pick=0,notpick=0;
        
        if(W-wt[i]>=0){
            pick=val[i]+helper(i+1,W-wt[i],wt,val,n,dp);
        }
        
        notpick = 0 + helper(i+1,W,wt,val,n,dp);
        
        
        dp[i][W]=max(pick,notpick);
        
        return dp[i][W];
    }
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
       vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
       
       return helper(0,W,wt,val,n,dp);
    }
};

class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    
	    vector<int> dp(n);
	    
	    for(int i=0;i<n;i++){
	        dp[i]=arr[i];
	    }
	    
	    
	    for(int i=0;i<n;i++){
	        
	        for(int j=0;j<i;j++){
	            
	            if(arr[j]<arr[i] && dp[i]<dp[j]+arr[i]){
	                dp[i]=dp[j]+arr[i];
	            }
	            
	        }
	    }
	    
	    
	    return *max_element(dp.begin(),dp.end());
	}  
};

// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        
       int current=0;
       int jumps=0;
       int farthest=0;
       
       
       for(int i=0;i<n;i++){
           
           farthest = max(farthest,i+arr[i]);
           
           if(i==current){
               jumps++;
               current=farthest;
           }
           
           if(current>=n-1){
               return jumps;
           }
       }
       
       return -1;
        
    }
};

//a2e1411be8925c04f907cb7ba0223a78__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() 
{
    
    
    int t;

    cin>>t;

    while(t--)
    {
        
        int n1,n2;
        
        cin>>n1;
        cin>>n2;
        
        
        string str1;
        string str2;
        
        
        cin>>str1;
        cin>>str2;
        
        
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        
        
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                
                if(i==0)
                {
                    dp[i][j]=j;
                }
                else if(j==0)
                {
                    dp[i][j]=i;
                }
                else if(str1[i-1]==str2[j-1])
                {
                 
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                }
                
                
            }
        }
        
        
        
        cout<<dp[n1][n2];
        
        cout<<endl;
        
        
        
    }


	return 0;
}

class Solution {
  public:
  
  
    long long helper(int ind,int coins[],int N,int sum, vector<vector<long long>> &dp){
        
        
        
          
        if(ind==0){
            return (sum%coins[0]==0);
        }
        
         if(sum<0){
            return 0;
        }
        
        if(sum==0){
            return 1;
        }
        
       
      

        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }        
        
        long long take=0,nottake=0;
        
        if(coins[ind]<=sum)
            take = helper(ind,coins,N,sum-coins[ind],dp);
        
        nottake = helper(ind-1,coins,N,sum,dp);
        
        return dp[ind][sum] = take+nottake;

    }
  
    long long int count(int coins[], int N, int sum) {

        // code here.
        
        vector<vector<long long>> dp(N,vector<long long>(sum+1,-1));
        
        return helper(N-1,coins,N,sum,dp);
    }
};

// User function Template for C++

class Solution{
public:
    
    int helper(int n,int i,int sum,int arr[],vector<vector<int>> &dp){
        
        if(i>=n){
            return 0;
        }
        
        if(sum<0){
            return 0;
        }
        
        if(sum==0){
            return 1;
        }
        
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        
        int pick,notpick;
        
        
        pick = helper(n,i+1,sum-arr[i],arr,dp);
        notpick = helper(n,i+1,sum,arr,dp);
        
        return dp[i][sum]=pick||notpick;
        
    }
    
    
    
    
    int equalPartition(int N, int arr[])
    {
        // code here
        
        
        
        int sum=0;
        
        for(int i=0;i<N;i++){
            sum += arr[i];
        }
        
        if(sum&1){
            return 0;
        }
        
        vector<vector<int>> dp(N,vector<int>(sum/2+1,-1));
        
        return helper(N,0,sum/2,arr,dp);
    }
};

//e1a197e20f925555f55fa69a9a0e893a__C3
14.139.82.6

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/

typedef struct Box
{
    int h;
    int l;
    int w;
}Box;

bool comparator(Box a,Box b)
{
    
    
    return a.l*a.w>b.l*b.w;
}




int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    
    vector<Box> v;
    
    
    for(int i=0;i<n;i++)
    {
        Box temp;
        
        temp.h=height[i];
        temp.l=max(width[i],length[i]);
        temp.w=min(width[i],length[i]);
        
        v.push_back(temp);
        
        temp.h=width[i];
        temp.l=max(height[i],length[i]);
        temp.w=min(height[i],length[i]);
        
        v.push_back(temp);
        
        temp.h=length[i];
        temp.l=max(height[i],width[i]);
        temp.w=min(height[i],width[i]);
        
         v.push_back(temp);
        
        
    }
    
    
    sort(v.begin(),v.end(),comparator);
    
    
    n=3*n;
    
    // cout<<"n "<<n<<endl;
    
    vector<int> h(n);
    
    for(int i=0;i<n;i++)
    {
        h[i]=v[i].h;
    }
    
    int ans=0;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            
            if(v[j].l>v[i].l && v[j].w>v[i].w)
            {
                // h[i]=h[j]+v[i].h;
                
                h[i]=max(h[i],h[j]+v[i].h);
               
                ans=max(ans,h[i]);
            }
            
            
            
        }
    }
    
    // cout<<ans<<endl;
    return ans;
    
    
    
    
    
    
}


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    
    
    
    int helper(int n,int x,int y,int z,vector<int> &dp){
        
        
        if(n==0){
            return 0;
        }
        
        if(n<0){
            return INT_MIN;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int c1=INT_MIN;
        int c2=c1;
        int c3=c1;
        
        c1=1+helper(n-x,x,y,z,dp);
        c2=1+helper(n-y,x,y,z,dp);
        c3=1+helper(n-z,x,y,z,dp);
        
        dp[n]=max(c1,max(c2,c3));
        
        return dp[n];
    }
    
    
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        
        vector<int> dp(n+1,-1);
        
        return helper(n,x,y,z,dp)<0?0:dp[n];
        
    }
};

// C++ program to find the longest path 
// in a matrix with given constraints
#include <bits/stdc++.h>
using namespace std;

int longestPath(int i, int j, vector<vector<int>> &matrix, 
vector<vector<int>> &memo) {
    
    // If value is memoized
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    
    int ans = 1;
    
    vector<vector<int>> dir = {{-1,0}, {1,0}, {0, -1}, {0, 1}};
    
    // Check for all 4 directions
    for (auto d: dir) {
        int x = i+d[0];
        int y = j+d[1];
        
        // If new cells are valid and 
        // increasing by 1.
        if (x>=0 && x<matrix.size() && y>=0 && 
        y<matrix[0].size() && matrix[x][y]==matrix[i][j]+1) {
            ans = max(ans, 1+longestPath(x, y, matrix, memo));
        }
    }
    
    return memo[i][j] = ans;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int ans = 0;
    
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> memo(n, vector<int>(m, -1));
    
    // Find length of longest path 
    // from each cell i, j
    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[0].size(); j++) {
            int val = longestPath(i, j, matrix, memo);
            ans = max(ans, val);
        }
    }
    
    return ans;
}

int main() {
    vector<vector<int>> matrix = 
    {{1, 2, 9},
    {5, 3, 8},
    {4, 6, 7}};
    cout << longestIncreasingPath(matrix);

    return 0;
}


//d72a2414ba9f04a2242ad8179f0a6703__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    
    int t;
    cin>>t;
    
    
    while(t--)
    {
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=1;i<=sum;i++)
        {
            dp[0][i]=0;
        }
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                
                
                dp[i][j]=dp[i-1][j];
                
                
                if(arr[i-1]<=j)
                {
                    dp[i][j]|=dp[i-1][j-arr[i-1]];
                }
                
                
            }
        }
        
        
        int diff=INT_MAX;
        
        
        for(int j=sum/2;j>=0;j--)
        {
            if(dp[n][j]==1)
            {
                diff=sum-2*j;
                break;
            }
        }
        
        cout<<diff<<endl;
         
    }
    
	return 0;
}



//d72a2414ba9f04a2242ad8179f0a6703__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    
    int t;
    cin>>t;
    
    
    while(t--)
    {
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=1;i<=sum;i++)
        {
            dp[0][i]=0;
        }
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                
                
                dp[i][j]=dp[i-1][j];
                
                
                if(arr[i-1]<=j)
                {
                    dp[i][j]|=dp[i-1][j-arr[i-1]];
                }
                
                
            }
        }
        
        
        int diff=INT_MAX;
        
        
        for(int j=sum/2;j>=0;j--)
        {
            if(dp[n][j]==1)
            {
                diff=sum-2*j;
                break;
            }
        }
        
        cout<<diff<<endl;
        
        

                
    }
    
    
    
	return 0;
}


class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long helper(int n,vector<long long> &dp){
        
        if(n==0 || n==1 || n==2){
            return n;
        }
        
        if(n==3){
            return 4;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        dp[n]=(helper(n-1,dp)+helper(n-2,dp)+helper(n-3,dp))%1000000007;
        
        return dp[n];
        
    }
    
    
    long long countWays(int n)
    {
        
        // your code here
        
        vector<long long> dp(n+1,-1);
        
        return helper(n,dp);
    }
};



//0d71043c4a63fbd06018bd3c80a02f2a__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() {
	
	
	
	int t;
	
	cin>>t;
	
	
	while(t--)
	{
	    
	    int n,k;
	    cin>>n;
	    cin>>k;
	    
	    
	    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
	    
	    
	    for(int i=1;i<=n;i++)
	    {
	        dp[i][0]=0;
	        dp[i][1]=1;
	    }
	    
	    for(int i=1;i<=k;i++)
	    {
	        dp[1][i]=i;
	    }
	    
	    
	    
	    
	    for(int i=2;i<=n;i++)
	    {
	        for(int j=2;j<=k;j++)
	        {
	            
	            dp[i][j]=INT_MAX;
	            
	            for(int x=1;x<=j;x++)
	            {
	                int res=max(dp[i-1][x-1],dp[i][j-x])+1;
	                
	                dp[i][j]=min(res,dp[i][j]);
	            }
	            
	        }
	    }
	    
	    cout<<dp[n][k]<<endl;
	    
	    
	    
	    
	    
	    
	    
	    
	}
	
	
	
	return 0;
}

//8bb594be5b9650c1385e5c75605cd3e9__C3
14.139.82.6
#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin>>t;
    
    while(t--)
    {
        
        
        string str1;
        string str2;
        
        cin>>str1;
        cin>>str2;
        
        
        int n1=str1.length();
        int n2=str2.length();
        
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        
        
        
        
        for(int i=0;i<=n1;i++)
        {
            dp[i][0]=i;
        }
        
        for(int i=0;i<=n2;i++)
        {
            dp[0][i]=i;
        }
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                
                
                
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                }
                
                
            }
        }
        
        
        cout<<dp[n1][n2]<<endl;
              
    }

	return 0;
}

// [[Divide and Conquer]]
// Find the element that appears once in sorted array
// Search in a Rotated Array
// Binary Search
// Sum of Middle Elements of two sorted arrays
// Quick Sort
// Merge Sort
// K-th element of two sorted Arrays

class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        
        int i=0;
        int j=n-1;
        while(i<j){
            int mid=(i+j)/2;
            
            if(arr[mid]==arr[mid^1]){
                i=mid+1;
            }else{
                j=mid;
            }
            
        }
        
        return arr[i];
    }
};


class Solution{
    public:
    
    
 
    int helper(int *arr1,int *arr2,int *end1,int *end2, int k){
        
        if(arr1==end1){
            return arr2[k];
        }
        
        if(arr2==end2){
            return arr1[k];
        }
        
        
        int m1=(end1-arr1)/2;
        int m2=(end2-arr2)/2;
        
        
        if(m1+m2<k){
            
            if(arr1[m1]>arr2[m2]){
                return helper(arr1,arr2+m2+1,end1,end2,k-m2-1);
            }else{
                return helper(arr1+m1+1,arr2,end1,end2,k-m1-1);
            }
            
        }else{
            
            if(arr1[m1]>arr2[m2]){
                return helper(arr1,arr2,arr1+m1,end2,k);
            }else{
                return helper(arr1,arr2,end1,arr2+m2,k);
            }
            
        }
        
        
        
    }

    
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        
        return helper(arr1,arr2,arr1+n,arr2+m,k-1);
    }
    
    

};


// [[Backtracking]]
// N-Queen Problem
// Solve the Sudoku
// Rat in a Maze Problem
// Word Boggle
// Generate IP Addresses



#622f02c1301691f7d99fabda7ebefa58__C3
14.139.82.6

''' Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above. '''

def ok(s):
    a,b,c,d = s.split('.')
    # print(int(a),int(b),c,d)
    if int(a)>255 or int(b)>255 or int(c)>255 or int(d)>255 or (a[0]=='0' and len(a)>1)  or (b[0]=='0' and len(b)>1)  or (c[0]=='0' and len(c)>1)  or (d[0]=='0' and len(d)>1) :
        return False
    return True    
    

def genIP(s):
    n = len(s)
    l = []
    for i in range(n-3):
        for j in range(i+1, n-2):
            for k in range(j+1, n-1):
                st=s[:k+1]+"."+s[k+1:]
                st = st[:j+1] + "." + st[j+1:]
                st = st[:i+1] + "." + st[i+1:]
                
                if ok(st):
                    # print(st)
                    l.append(st)
    # print(l)
    return l


// [[Bit Magic]]

// Find first set bit
// Rightmost different bit
// Check whether K-th bit is set or not
// Toggle bits given range
// Set kth bit
// Power of 2
// Bit Difference
// Rotate Bits
// Swap all odd and even bits
// Count total set bits
// Longest Consecutive 1's
// Sparse Number
// Alone in a couple
// Maximum subset XOR

//User function Template for C++

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        unsigned int pos=1;
        // Your code here
        while(n>0){
            if(n&1)
                return pos;
            pos++;
            n=n>>1;
        }
        
        return 0;
    }
};


//User function Template for C++


class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // Your code here
        // It can be a one liner logic!! Think of it!!
        n=n>>k;
        
        return n&1;
    }
};


class Solution {
  public:
    int toggleBits(int N , int L , int R) {
        // code here
        
        for(int i=L-1;i<R;i++){
            N ^= (1<<i);
        }
        
        return N;
    }
};



class Solution
{
public:
    int setKthBit(int n, int K)
    {
        // Write Your Code here
        n|=(1<<K);
        return n;
    }
    
};

//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	// Your code here
    	
    	unsigned int odd=0x55555555;
    	unsigned int even=0xAAAAAAAA;
    	
    	return (n&even)>>1|(n&odd)<<1;
    }
};

//User function Template for C++

/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
class Solution
{
    public:
    int maxConsecutiveOnes(int N)
    {
        // code here
        
        int res=0;
        
        int c=0;
        
        while(N>0){
            
            if(N&1){
                c++;
                res=max(res,c);
            }else{
                c=0;
            }
            
            N=N>>1;
        }
        
        return res;
    }
};


// [[Some More Questions on Arrays]]

// Find Missing And Repeating
// Maximum Index
// Consecutive 1's not allowed
// Majority Element
// Two numbers with sum closest to zero
// Nuts and Bolts Problem
// Boolean Matrix Problem
// Smallest Positive missing number
// Jumping Caterpillars




class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code 
        
 
        // code here
        for(int i=0;i<n;i++){
            int corr=arr[i]-1;
            if(arr[corr]!=corr+1){
                swap(arr[corr],arr[i]);
                i--;
            }
        }
        
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                return {arr[i],i+1};
            }
        }
     
        
    }
};




//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code 
        unordered_map<int,int> ump;
        for(int i=0;i<size;i++){
            ump[a[i]]++;
        }
        
        for(auto t:ump){
            if(t.second>size/2){
                return t.first;
            }
        }
        
        return -1;
        
    }
};



// [[Some More Questions on Strings]]

// Most frequent word in an array of strings
// CamelCase Pattern Matching
// String Ignorance
// Smallest window in a string containing all the characters of another string
// Design a tiny URL or URL shortener
// Permutations of a given string
// Non Repeating Character
// Check if strings are rotations of each other or not
// Save Ironman
// Repeated Character
// Remove common characters and concatenate
// Geek and its Colored Strings
// Second most repeated string in a sequence

//493d4ae7aacfa9217755911f947b17d1__C3
183.83.156.2
#include<bits/stdc++.h>

using namespace std;



void printString(string s,string t)
{
    
    int hash_pat[256]={0};
    
    for(int i=0;i<t.size();i++)
    {
        char c=t[i];
        hash_pat[c]++;
        
        // cout<<hash_pat[c-'a']<<endl;
    }
    
    
    int hash_str[256]={0};
     
    int count=0;
    
    int st=-1;
    
    int start=0;
    
    int len=INT_MAX;
    
    int tl=t.size();
    
    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        hash_str[c]++;
        
        
        
        if(hash_pat[c]!=0 && hash_str[c]<=hash_pat[c])
        {
            count++;
            
            // cout<<"c "<<c<<endl;
        }
        if(count==tl)
        {
            
            
            
            
            while(((hash_str[s[start]]>hash_pat[s[start]])||hash_str[s[start]]==0))
            {
                    
                    if(hash_str[s[start]]>hash_pat[s[start]])
                    {
                        hash_str[s[start]]--;
                    }
                    
                    // cout<<"start "<<start<<endl;
                    start++;
            }
            
            
            if((i-start+1)<len)
            {
                len=i-start+1;
                st=start;
                
                // cout<<"st "<<st<<endl;
                
            }
            
            
            
            
            
            
        }
        
        
        
        
    }
    
    
    
    
    if(st!=-1)
    {
        // cout<<st<<endl;
        cout<<s.substr(st,len)<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
    
    // cout<<"123\n";
    
    
}

int main() 
{

    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        string t;
        cin>>s>>t;
        
        if(s.size()<t.size())
        {
            cout<<"-1"<<endl;
            continue;
        }
        
        printString(s,t);
        
    }



	return 0;
}

//74700b9d6be32900408cadf0adf657f9__C3
14.139.82.6
#include <bits/stdc++.h>
using namespace std;

void permute_sequence(string str,int start,int end,vector<string> &res)
{
    
    if(start==end)
    {
        // cout<<str<<" ";
        res.push_back(str);
    }
    
    
    for(int i=start;i<=end;i++)
    {
        swap(str[i],str[start]);
        permute_sequence(str,start+1,end,res);
        swap(str[i],str[start]);
    }
    
}

int main() 
{
	//code
	
	int t;
	cin>>t;
	
	t=t+1;
	while(t--)
	{
	    
	    
	    string str;
	    
	    getline(cin,str);
	    
	    if(str.empty())
	        continue;
	        
	   vector<string> res;
	        
	    permute_sequence(str,0,str.size()-1,res);
	    
	    sort(res.begin(),res.end());
	    
	    for(string t:res)
	        cout<<t<<" ";
	    
	    
	    cout<<endl;
	    
	    
	    
	}
	
	
	
	
	
	return 0;
}


class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        
        if(s1.size()!=s2.size())
            return 0;
        
        string temp = s1+s1;
        
        // cout<<s1<<" "s2;
        
        int t=temp.find(s2);
        
        if(t!=string::npos)
            return 1;
        
        return 0;
    }
};

class Solution
{
  public:
    char firstRep (string s)
    {
        //code here.
        map<char,int> ump;
        for(char c:s){
            ump[c]++;
        }
        
        // bool flag=false;
        for(int i=0;i<s.size();i++){
            
            if(ump[s[i]]>1){
                // cout<<i<<" ";
                // flag=true;
                return s[i];
            }
        }
        
       return '#';
    }
};

// User function Template for C++
class Solution {
  public:
    long long possibleStrings(int n, int r, int b, int g) {
        
        // code here
        long long int fact[21];
        fact[0]=1;
        fact[1]=1;
        
        for(int i=2;i<=20;i++){
            fact[i]=fact[i-1]*i;
        }
        
        long long int res=0;
        
        int left=n-(r+g+b);
        
        for(int i=0;i<=left;i++){
            for(int j=0;j<=left;j++){
                int k=left-(i+j);
                if(k>=0){
                    long long int temp=fact[r+i]*fact[b+j]*fact[g+k];
                    res+=(fact[n]/temp);
                }
            }
        }
        
        return res;
    }
};


class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        
        
        unordered_map<string,int> ump;
        
        string res="";
        
        int firstMax=0;
        
        for(int i=0;i<n;i++){
            
            ump[arr[i]]++;
            
            if(ump[arr[i]]>firstMax){
                firstMax=ump[arr[i]];
            }
            
        }
        
        
        int secondMax=0;
        
        
        for(int i=0;i<n;i++){
            
            int val=ump[arr[i]];
            
            if(val<firstMax && val>secondMax){
                secondMax=val;
                res=arr[i];
            }
        }
        
        
        return res;
    }
};





// [[Some more Questions on Trees]]
// Mirror Tree
// Longest consecutive sequence in Binary tree
// Bottom View of Binary Tree
// Lowest Common Ancestor in a Binary Tree
// Binary to DLL

/*
struct Node
{
	int data;
	Node *left, *right;
};
*/
class Solution{
  public:
    // your task is tp complete this function
    // function should return the length of the longestConsecutive
    // sequence
    
    
    void dfs(Node* root,int exp,int len,int &res){
        
        if(!root){
            return;   
        }
        
        
        if(root->data==exp){
            len++;
        }else{
            len=1;
        }
        
        res=max(res,len);
        
        dfs(root->left,root->data+1,len,res);
        dfs(root->right,root->data+1,len,res);
        
    }
    
    int longestConsecutive(Node* root)
    {
         //Code here
         int len=0;
         int res=0;
         
         dfs(root,root->data,len,res);
         
         if(res>1){
             return res;
         }
         
         return -1;
    }
};


//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
  
//   void helper(Node* root,map<int,int> &mp,int hd){
       
//       if(!root){
//           return;
//       }
       
       
//       mp[hd]=root->data;
       
//       helper(root->left,mp,hd-1);
//       helper(root->right,mp,hd+1);
//   }
  
    vector <int> bottomView(Node *root) {
        // Your Code Here
        
        map<int,int> mp;
        vector<int> res;
        
        // helper(root,mp,0);
        

        
        queue<pair<Node*,int>>qu;
        
        qu.push({root,0});
        
        while(!qu.empty()){
            
            Node* temp = qu.front().first;
            int lvl = qu.front().second;
            
            mp[lvl]=temp->data;
            
            qu.pop();
            
            if(temp->left){
                qu.push({temp->left,lvl-1});
            }
            
            if(temp->right){
                qu.push({temp->right,lvl+1});
            }
            
            
        }
        
        
        
        
        for(auto it:mp){
            res.push_back(it.second);
        }
        
        

             
        return res;
        
    }
};

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    
    Node* helper(Node* root,int n1,int n2){
        
        if(!root){
            return root;
        }
        
        if(root->data==n1 || root->data==n2){
            return root;
        }
        
        Node* left = helper(root->left,n1,n2);
        Node* right = helper(root->right,n1,n2);
        
        if(left && right){
            return root;
        }
        
        if(left){
            return left;
        }
        
        if(right){
            return right;
        }
        
    }
    
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       
       return helper(root,n1,n2);
    }
};

/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    
    
    void convert(Node* root,Node* &prev,Node* &head){
        
        if(!root){
            return;
        }
        
        convert(root->right,prev,head);
        
        if(prev!=NULL){
            prev->left=root;
            root->right=prev;
        }
        
       
        
        prev=root;
        head=root;
        
        convert(root->left,prev,head);
    }
    
    
    
    
    Node * bToDLL(Node *root)
    {
        // your code here
        
        
        Node* prev=NULL;
        Node* head=NULL;
        
        convert(root,prev,head);
        
        return head;
    }
};





