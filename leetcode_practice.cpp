












class Solution {
public:
    // Helper function to find the kth element in merged sorted arrays
    double findKthElement(int k, vector<int>& nums1, vector<int>& nums2, int start1, int end1, int start2, int end2) {
        // Base cases when one array is exhausted
        if (start1 >= end1)
            return nums2[start2 + k];
        if (start2 >= end2)
            return nums1[start1 + k];

        // Calculate mid indices
        int mid1 = (end1 - start1) / 2;
        int mid2 = (end2 - start2) / 2;

        // Compare mid elements and recurse accordingly
        if (mid1 + mid2 < k) {
            if (nums1[start1 + mid1] > nums2[start2 + mid2])
                // Discard elements before mid2 and search in the remaining array
                return findKthElement(k - mid2 - 1, nums1, nums2, start1, end1, start2 + mid2 + 1, end2);
            else
                // Discard elements before mid1 and search in the remaining array
                return findKthElement(k - mid1 - 1, nums1, nums2, start1 + mid1 + 1, end1, start2, end2);
        } else {
            if (nums1[start1 + mid1] > nums2[start2 + mid2])
                // Discard elements after mid1 and search in the remaining array
                return findKthElement(k, nums1, nums2, start1, start1 + mid1, start2, end2);
            else
                // Discard elements after mid2 and search in the remaining array
                return findKthElement(k, nums1, nums2, start1, end1, start2, start2 + mid2);
        }
    }

    // Function to find the median of merged sorted arrays
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int totalSize = size1 + size2;

        // Check if the total size is odd or even and find the median accordingly
        if (totalSize % 2 == 1)
            // For odd total size, median is the kth element where k = total_size // 2
            return findKthElement(totalSize / 2, nums1, nums2, 0, size1, 0, size2);
        else {
            // For even total size, median is the average of kth and (kth - 1) elements
            int num1 = findKthElement(totalSize / 2, nums1, nums2, 0, size1, 0, size2);
            int num2 = findKthElement(totalSize / 2 - 1, nums1, nums2, 0, size1, 0, size2);

            return (num1 + num2) / 2.0;
        }
    }
};


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Merge the sorted arrays into a single array
        vector<int> mergedArray(nums1.size() + nums2.size());
        
        int idxNums1 = 0; // Index for nums1
        int idxNums2 = 0; // Index for nums2
        
        // Merge the arrays while maintaining the sorted order
        for(int i = 0; i < mergedArray.size(); i++) {
            if (idxNums2 != nums2.size() && (idxNums1 == nums1.size() || nums2[idxNums2] < nums1[idxNums1])) {
                mergedArray[i] = nums2[idxNums2++];
            } else {
                mergedArray[i] = nums1[idxNums1++];
            }
        }
        
        // Calculate the median of the merged array
        if (mergedArray.size() % 2 == 1) {
            return mergedArray[mergedArray.size() / 2];
        } else {
            return ((mergedArray[mergedArray.size() / 2]) + (mergedArray[mergedArray.size() / 2 - 1])) / 2.0;
        }
    }
};




// Construct Binary Tree from Preorder and Postorder Traversal | DFS

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int index = 0;
        return construct(pre, post, index, 0, pre.size() - 1);
    }
    
private:
    TreeNode* construct(vector<int>& pre, vector<int>& post, int& index, int l, int h) {
        if (index >= pre.size() || l > h) 
            return nullptr;

        TreeNode* root = new TreeNode(pre[index++]);
        if (l == h) return root;

        int i = l;
        while (i <= h && post[i] != pre[index]) i++;

        if (i <= h) {
            root->left = construct(pre, post, index, l, i);
            root->right = construct(pre, post, index, i + 1, h - 1);
        }

        return root;
    }
};


class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        stack<TreeNode*> nodes;
        TreeNode* root = new TreeNode(preorder[0]);
        nodes.push(root);

        int preIndex = 1, postIndex = 0;

        while (!nodes.empty()) {
            TreeNode* current = nodes.top();

            if (current->val == postorder[postIndex]) {
                nodes.pop();
                postIndex++;
            } else {
                TreeNode* newNode = new TreeNode(preorder[preIndex++]);
                if (!current->left) {
                    current->left = newNode;
                } else {
                    current->right = newNode;
                }
                nodes.push(newNode);
            }
        }
        return root;
    }
};

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int preIdx, postIdx;

    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        // Create the root node using the current preorder index
        TreeNode root=new TreeNode(preorder[preIdx]);
        preIdx++;
        
        // Construct the left subtree if the current node is not the postorder node
        if(root.val!=postorder[postIdx]){
            root.left=constructFromPrePost(preorder,postorder);
        }

        // Construct the right subtree if the current node is not the postorder node
        if(root.val!=postorder[postIdx]){
            root.right=constructFromPrePost(preorder,postorder);
        }

        // Move to the next postorder index
        postIdx++;

        return root;
    }
}


// class Solution {
// public:
//     string longestPalindrome(string s) {
        
//     }
// };


class Solution {
public:
    string longestPalindrome(string s) {
        int memo[1001][1001];
        memset(memo, -1, sizeof(memo));
        vector<int> answer = {0, 0, 1};
        helper(0, s.size() - 1, s, memo, answer);
        return s.substr(answer[0], answer[2]);
    }
    
    bool helper(int l, int r, string &s, int memo[][1001], vector<int> &answer) {
        // Check if [ L ... R ] is already calculated before
        if (memo[l][r] != -1) {
            return memo[l][r];         
        }
        
        // Base case, every single letter or empty string is also a palindrome
        if (l >= r) {
            return true;
        }
        
        // Possible palindrome beginning
        bool found = false;
        if (s[l] == s[r]) {
            found = true && helper(l + 1, r - 1, s, memo, answer);
        }
        
        // Try other possibilities
        helper(l + 1, r , s, memo, answer);
        helper(l, r - 1, s, memo, answer);
        
        // Update longest palindrome position and width
        if (found && (r - l + 1) > answer[2]) {
            answer = {l, r, (r - l + 1)};
        }
        
        // Memoization
        memo[l][r] = found;
        
        return found;
    }
};



































































































