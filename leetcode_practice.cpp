




https://kraa.io/302106244166192384







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




// C program to implement your own printf() function
#include <stdarg.h>
#include <stdio.h>

// your own printf
int myprintf(const char* str, ...)
{
    // initializing list pointer
    va_list ptr;
    va_start(ptr, str);

    // char array to store token
    char token[1000];
    // index of where to store the characters of str in
    // token
    int k = 0;

    // parsing the formatted string
    for (int i = 0; str[i] != '\0'; i++) {
        token[k++] = str[i];

        if (str[i + 1] == '%' || str[i + 1] == '\0') {
            token[k] = '\0';
            k = 0;
            if (token[0] != '%') {
                fprintf(
                    stdout, "%s",
                    token); // printing the whole token if
                            // it is not a format specifier
            }
            else {
                int j = 1;
                char ch1 = 0;

                // this loop is required when printing
                // formatted value like 0.2f, when ch1='f'
                // loop ends
                while ((ch1 = token[j++]) < 58) {
                }
                // for integers
                if (ch1 == 'i' || ch1 == 'd' || ch1 == 'u'
                    || ch1 == 'h') {
                    fprintf(stdout, token,
                            va_arg(ptr, int));
                }
                // for characters
                else if (ch1 == 'c') {
                    fprintf(stdout, token,
                            va_arg(ptr, int));
                }
                // for float values
                else if (ch1 == 'f') {
                    fprintf(stdout, token,
                            va_arg(ptr, double));
                }
                else if (ch1 == 'l') {
                    char ch2 = token[2];

                    // for long int
                    if (ch2 == 'u' || ch2 == 'd'
                        || ch2 == 'i') {
                        fprintf(stdout, token,
                                va_arg(ptr, long));
                    }

                    // for double
                    else if (ch2 == 'f') {
                        fprintf(stdout, token,
                                va_arg(ptr, double));
                    }
                }
                else if (ch1 == 'L') {
                    char ch2 = token[2];

                    // for long long int
                    if (ch2 == 'u' || ch2 == 'd'
                        || ch2 == 'i') {
                        fprintf(stdout, token,
                                va_arg(ptr, long long));
                    }

                    // for long double
                    else if (ch2 == 'f') {
                        fprintf(stdout, token,
                                va_arg(ptr, long double));
                    }
                }

                // for strings
                else if (ch1 == 's') {
                    fprintf(stdout, token,
                            va_arg(ptr, char*));
                }

                // print the whole token
                // if no case is matched
                else {
                    fprintf(stdout, "%s", token);
                }
            }
        }
    }

    // ending traversal
    va_end(ptr);
    return 0;
}

// driver code
int main()
{
    myprintf("Integer: %d\nString: %s\nFloat: %0.2f\n", 10,
             "GeeksforGeeks", 12.2548);
    return 0;
}


class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);

        auto leftA = head; // The left node to be swapped.
        auto leftB = head; // The right node to be swapped.
        auto prevA = dummy;
        auto prevB = dummy;
        auto right = head;

        while (nullptr != right->next) {
            if (k > 1) { // Move only 'leftA' pointer.
                prevA = prevA->next;
                leftA = leftA->next;
                --k;
            }
            else { // Then move 'leftB' pointer.
                prevB = prevB->next;
                leftB = leftB->next;
            }
            right = right->next;
        }

        // Swap the nodes.
        prevA->next = leftB;
        prevB->next = leftA;
        auto temp = leftB->next;
        leftB->next = leftA->next;
        leftA->next = temp;

        // return dummy->next;
        return NULL;
    }
};

ListNode **a = &head, **b = &head;
while (--k) { a = &(*a)->next; }
ListNode *x = (*a)->next;
while (x) { x = x->next; b = &(*b)->next; }
swap(*a, *b);
swap((*a)->next, (*b)->next);
return head;





// A C++ program to swap Kth node from beginning with kth
// node from end
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Utility function to insert a node at the beginning
void push(Node** head_ref, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Utility function for displaying linked list */
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

/* Utility function for calculating
   length of linked list */
int countNodes(struct Node* s)
{
    int count = 0;
    while (s != NULL) {
        count++;
        s = s->next;
    }
    return count;
}

// Utility function for calculating length of linked list
void swapKth(struct Node** head_ref, int k)
{
    // Count nodes in linked list
    int n = countNodes(*head_ref);
    // Check if k is valid
    if (n < k)
        return;
    // If x (kth node from start) and y(kth node from end)
    // are same
    if (2 * k - 1 == n)
        return;
    // Find the kth node from the beginning of the linked
    // list. We also find previous of kth node because we
    // need to update next pointer of the previous.
    Node* x = *head_ref;
    Node* x_prev = NULL;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }
    // Similarly, find the kth node from end and its
    // previous. kth node from end is (n-k+1)th node from
    // beginning
    Node* y = *head_ref;
    Node* y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++) {
        y_prev = y;
        y = y->next;
    }
    // If x_prev exists, then new next of it will be y.
    // Consider the case when y->next is x, in this case,
    // x_prev and y are same. So the statement "x_prev->next
    // = y" creates a self loop. This self loop will be
    // broken when we change y->next.
    if (x_prev)
        x_prev->next = y;
    // Same thing applies to y_prev
    if (y_prev)
        y_prev->next = x;
    // Swap next pointers of x and y. These statements also
    // break self loop if x->next is y or y->next is x
    Node* temp = x->next;
    x->next = y->next;
    y->next = temp;
    // Change head pointers when k is 1 or n
    if (k == 1)
        *head_ref = y;
    if (k == n)
        *head_ref = x;
}

// Driver code
int main()
{
    // Let us create the following linked list for testing
    // 1->2->3->4->5->6->7->8
    struct Node* head = NULL;
    for (int i = 8; i >= 1; i--)
        push(&head, i);
    cout << "Original Linked List: ";
    printList(head);
    for (int k = 1; k < 9; k++) {

        // Function call
        swapKth(&head, k);
        cout << "\nModified List for k = " << k << endl;
        printList(head);
    }
    return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        stable_sort(begin(arr), end(arr), [x](const auto a, const auto b){
            return abs(a - x) < abs(b - x);   // sort by distance from x
        });
        arr.resize(k);                        // choose first k elements
        sort(begin(arr), end(arr));           // sort the output in ascending order before returning
        return arr; 
    }
};



class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int L = 0, R = size(arr)-1;
        while (R - L >= k) 
            if (x - arr[L] <= arr[R] - x) R--;
            else L++;
        return vector<int>(begin(arr) + L, begin(arr) + R + 1);
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {        
        int n = size(arr), R = lower_bound(begin(arr), end(arr), x) - begin(arr), L = R - 1;
        // expand the [L, R] window till its size becomes equal to k
        while(k--) 
            if(R >= n || L >= 0 && x - arr[L] <= arr[R] - x) L--;  // expand from left
            else R++;                                              // expand from right
        return vector<int>(begin(arr) + L + 1, begin(arr) + R);
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {        
        int n = size(arr), R = lower_bound(begin(arr), end(arr) - k, x) - begin(arr), L = R - 1;
        while(k--) 
            if(R >= n || L >= 0 && x - arr[L] <= arr[R] - x) L--;
            else R++;
        return vector<int>(begin(arr) + L + 1, begin(arr) + R);
    }
};



class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {        
        int n = size(arr), L = 0, R = n - k;
        while (L < R) {
            int mid = (L + R) / 2;            
            if(arr[mid] == arr[mid + k])          // case - 3
                if (arr[mid] < x) L = mid + 1;
                else R = mid;
                
            else if (abs(x - arr[mid]) <= abs(x - arr[mid + k])) R = mid;   // case - 1
            else L = mid + 1;                                               // case - 2
        }
        return vector<int>(begin(arr) + L, begin(arr) + L + k);
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {        
        int n = size(arr), R = lower_bound(begin(arr), end(arr) - k, x) - begin(arr), L = R - 1;
        while(k--) 
            if(R >= n || L >= 0 && x - arr[L] <= arr[R] - x) L--;
            else R++;
        return vector<int>(begin(arr) + L + 1, begin(arr) + R);
    }
};



class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Compare distance from x to ends of the window
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // Return k elements starting from index `left`
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};





#include <stdio.h>
#include <stdlib.h>

// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};

// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL");
}

// Helper function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Helper function to return a new node of the linked list
struct Node* newNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a given node at its correct sorted position into a given
// list sorted in increasing order
void sortedInsert(struct Node** head, struct Node* newNode)
{
    struct Node** currentRef = head;
    while (*currentRef != NULL && (*currentRef)->data < newNode->data) {
        currentRef = &((*currentRef)->next);
    }

    newNode->next = *currentRef;
    *currentRef = newNode;
}

int main(void)
{
    // input keys
    int keys[] = {2, 4, 6, 8};
    int n = sizeof(keys)/sizeof(keys[0]);

    // points to the head node of the linked list
    struct Node* head = NULL;

    // construct a linked list
    for (int i = n-1; i >= 0; i--) {
        push(&head, keys[i]);
    }

    sortedInsert(&head, newNode(5));
    sortedInsert(&head, newNode(9));
    sortedInsert(&head, newNode(1));

    // print linked list
    printList(head);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>

// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};

// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL");
}

// Helper function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Helper function to return a new node of the linked list
struct Node* newNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a given node at its correct sorted position into a given
// list sorted in increasing order
void sortedInsert(struct Node** head, struct Node* newNode)
{
    struct Node dummy;
    struct Node* current = &dummy;
    dummy.next = *head;

    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    *head = dummy.next;
}

int main(void)
{
    // input keys
    int keys[] = {2, 4, 6, 8};
    int n = sizeof(keys)/sizeof(keys[0]);

    // points to the head node of the linked list
    struct Node* head = NULL;

    // construct a linked list
    for (int i = n-1; i >= 0; i--) {
        push(&head, keys[i]);
    }

    sortedInsert(&head, newNode(5));
    sortedInsert(&head, newNode(9));
    sortedInsert(&head, newNode(1));

    // print linked list
    printList(head);

    return 0;
}































































