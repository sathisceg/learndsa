

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























