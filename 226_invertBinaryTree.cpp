#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
    {
        val = 0;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int v)
    {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

#if 0
TreeNode* invertTree_Itr(TreeNode* root)
{
    if(root == nullptr)
        return nullptr;
    
    //1. create a stack
    stack<TreeNode*> s;
    TreeNode* temp = nullptr;

    //2. push root to stack
    s.push(root);

    //3. iterate through the stack until empty, keep pushing children
    while(s.size() > 0)
    {
        TreeNode* node = s.top();
        s.pop();
        if(node->left)
            s.push(node->left);
        if(node->right)
            s.push(node->right);

        //4. swap algo
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
    return root;
}

TreeNode* invertTree_Rec(TreeNode* root)
{
    if(root == nullptr)
        return root;
    if(root->left)
        invertTree_Rec(root->left);
    if(root->right)
        invertTree_Rec(root->right);

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    return root;
}

int maxDepth_Rec(TreeNode* root)
{
    if(root == nullptr)
        return 0;
    return (1+max(maxDepth_Rec(root->left),maxDepth_Rec(root->right)));
}

int maxDepth_Itr(TreeNode* root)
{
    if(root == nullptr)
        return 0;
    
    int curr_height = 1;
    int max_height = 1;
    queue<pair<TreeNode*,int> > q;
    q.push({root,1});

    while(q.size() > 0)
    {
        TreeNode* node = q.front().first;
        curr_height = q.front().second;
        q.pop();
        max_height = max(max_height,curr_height);
        if(node->left)
        {
            q.push({node->left, 1+curr_height});
        }
        if(node->right)
        {
            q.push({node->right, 1+curr_height});
        }
    }
    return max_height;
}


int max_diam = 0;

int diameterOfBinaryTree_helper(TreeNode* root)
{
    //base case
    if(root == nullptr)
        return -1;
    
    int left_height = diameterOfBinaryTree_helper(root->left);
    int right_height = diameterOfBinaryTree_helper(root->right);
    max_diam = max(max_diam, (2 + left_height + right_height));
    return 1+max(left_height,right_height);
}

int diameterOfBinaryTree(TreeNode* root)
{
    if(root == nullptr)
        return 0;
    
    int height = diameterOfBinaryTree_helper(root);
    return max_diam;
}

pair<bool, int> isBalanced_helper(TreeNode* root)
{
    if(root == nullptr)
    {
        return(make_pair(true,0));
    }
    pair<bool,int> left_child = isBalanced_helper(root->left);
    pair<bool,int> right_child = isBalanced_helper(root->right);

    bool isNodeBalanced = true;
    if( left_child.first == false || right_child.first == false )
        isNodeBalanced = false;
    else if(abs(left_child.second - right_child.second) > 1)
        isNodeBalanced = false;

    int nodeHeight = 1+max(left_child.second,right_child.second);

    return make_pair(isNodeBalanced,nodeHeight);  
}

bool isBalanced(TreeNode* root)
{
    if(root == NULL)
        return true;
    pair<bool,int> res;
    res = isBalanced_helper(root);
    return res.first;
}

/*return a pair of bool and height. bottom top approach results in TC O(n) SC O(1)*/

/*--------------------------------------------------------------------------------------------
572. Sub Tree of Another Tree
*/

bool isSameTree(TreeNode* root, TreeNode* subRoot)
{
    if(root == nullptr && subRoot == nullptr)
        return true;
    else if(root == nullptr || subRoot == nullptr)
        return false;
    return (isSameTree(root->left,subRoot->left) && isSameTree(root->right, subRoot->right));
}

bool isSubtree(TreeNode* root, TreeNode* subRoot)
{
    /* edge cases:
    1. both are null - true
    2. subroot is only null - true 
    3. root is only null - false
    */
   //1 and 2
    if(root == nullptr && subRoot == nullptr)
        return true;
    //3
    if(root != nullptr || subRoot == nullptr)
        return false;
    
    //if val - false -> isSubtree
    //if val - true -> isSametree
    if(root->val == subRoot->val)
        if(isSameTree(root,subRoot))
            return true;
        else
            return(isSubtree(root->left,subRoot) || isSubtree(root->right, subRoot));
    else
        return (isSubtree(root->left,subRoot) || isSubtree(root->right, subRoot));
}


/*--------------------------------------------------------------------------------------------
235. Lowest Common Ancestor
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    //Note this is a BST
    TreeNode* curr = root;

    while(curr)
    {
        if(p->val < curr->val && q->val < curr->val)
            curr = curr->left;
        else if(p->val > curr->val && q->val > curr->val)
            curr = curr->right;
        else
            break;
    }
    return curr;
}

/*--------------------------------------------------------------------------------------------
102. Binary Tree Level Order Traversal
*/
vector<vector<int> > levelOrder_1(TreeNode* root)
{
    vector<vector<int> > res;

    //use a queue for BFS/Level order Traversal
    if(root == nullptr)
        return {};
    queue<pair<TreeNode*, int> > q;
    vector<int> subset;
    TreeNode* node = root;
    q.push(make_pair(root,1));
    // subset.push_back(root->val);
    res.push_back({root->val});
    int level = 0;
    int node_level = 0;
    while(q.size() > 0)
    {
        node = q.front().first;
        node_level = q.front().second;
        q.pop();
        if(node_level > level && subset.size() > 0)
        {
            res.push_back(subset);
            subset.clear();
            level++;
        }
        if(node->left)
        {
            subset.push_back(node->left->val);
            q.push(make_pair(node->left,1+node_level));
        }
        if(node->right)
        {
            subset.push_back(node->right->val);
            q.push(make_pair(node->right,1+node_level));
        }       
    }
    return res;
}

/*
use queue for BFS. push nodes if not null into subset and then into result. O(n)SC:  O(n). Note: imp concept of level and node level
*/

vector<vector<int> > levelOrder(TreeNode* root)
{
    vector<vector<int> > res;

    //use a queue for BFS/Level order Traversal
    if(root == nullptr)
        return {};
    queue<TreeNode*> q;
    vector<int> subset;
    q.push(root);

    while(q.size() > 0)
    {
        int elements = q.size();
        for(int i=0; i<elements; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            if(node != nullptr)
            {
                subset.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
        }
        res.push_back(subset);
        subset.clear();   
    }
    return res;
}

/*--------------------------------------------------------------------------------------------
199. Binary Tree Right Side View
*/
vector<int> rightSideView(TreeNode* root)
{
    if(root == nullptr)
        return {};
    
    //BFS push to queue and pick the rightmost/last element
    //in queue at each level
    vector<int> res;
    queue<TreeNode*> q;
    TreeNode* node; //declare outside of the for loop
    
    q.push(root);

    while(q.size() > 0)
    {
        int size = q.size();
        for(int i=0; i<size; i++)
        {
            node = q.front();
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        res.push_back(node->val);
    }
    return res;
}
/*
BFS push to queue and pick the rightmost/last element in queue at each level.
TC: O(n) SC: O(n)
*/


/*--------------------------------------------------------------------------------------------
1448. Count Good Nodes In A Binary Tree
*/

int goodNodes(TreeNode* root)
{
    //BFS to push into queue only valid nodes
    if(root == nullptr)
        return 0;
    
    queue<pair<TreeNode*, int> > q;
    TreeNode* node;
    int count = 0;
    int greatest = root->val;
    
    q.push(make_pair(root, root->val));

    while(q.size() > 0)
    {
        //push to result only if val > greatest. then update greatest by val
        node = q.front().first;
        greatest = q.front().second;
        q.pop();

        if(node->val >= greatest)
            count++;
        
        if(node->left)
            q.push(make_pair(node->left, max(greatest, node->val)));

        if(node->right)
            q.push(make_pair(node->right, max(greatest, node->val)));
    }
    return count;
}

/*
queue of pair of node and max in path. push to result only if val > greatest. then update greatest by val
TC: O(n) SC: O(n)
*/

/*--------------------------------------------------------------------------------------------
98. Validate Binary Search Tree
*/

bool isValidBST_helper(TreeNode* node, long left_limit, long right_limit)
{
    //base case
    if(node == nullptr)
        return true;
    
    //condition to not traverse further if false is found
    //note left and right are parent's limits
    if(!(node->val > left_limit && node->val < right_limit))
        return false;
    
    //else recursively search left and right subtree
    //with correct bounds

    return( 
        //left
        ( isValidBST_helper(node->left, left_limit, node->val))
        &&
        //right
        (isValidBST_helper(node->right, node->val, right_limit))
    );
}

bool isValidBST(TreeNode* root)
{
    return isValidBST_helper(root, LONG_MIN, LONG_MAX);
}

/*
recursive helper function to call with limits set by parents or parent's values
Note: use LONG as inputs using INT_MIN/MAX values. TC: O(n) SC: O(1)*/


/*--------------------------------------------------------------------------------------------
230. Kth Smallest Node*/

int kthSmallest(TreeNode* root, int k)
{
    stack<TreeNode*> s;
    s.push(root);

    while(s.size() > 0 || root)
    {
        while(root)
        {
            s.push(root->left);
            root = root->left;
        }
        root = s.top(); //imp as root will be null here
        k--;
        if(k==0)
            return root->val;
        s.pop();
        s.push(root->right);
    }
    return -1;
}
#endif

/*--------------------------------------------------------------------------------------------
105. Construct Binary Tree from Preorder and Inorder Traversal
*/

TreeNode* buildTree_helper(vector<int>& preorder, vector<int>& inorder, int& index, int left, int right)
{
    //base case - left and right indices should be good
    if(left > right)
        return nullptr;

    TreeNode* node = new TreeNode(preorder[index]);

    //find the preorder index in Inorder array.
    //partition InOrder array with this index.
    //Left to this is the left subtree and right to this will be the right subtree
    //both should be recursive calls

    int inorderSplitIndex = 0;
    for(int i=0; i<inorder.size(); i++)
    {
        if(inorder[i] == preorder[index])
        {
            inorderSplitIndex = i; //update new index value
            break;
        }
    }
    index++;

    //recursively call left and right subtrees
    node->left = buildTree_helper(preorder, inorder, index, left, inorderSplitIndex-1);
    node->right = buildTree_helper(preorder, inorder, index, inorderSplitIndex+1, right);

    return node;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    if(preorder.empty() || inorder.empty())
        return nullptr;

    int index = 0;
    //recursive algorithm
    return buildTree_helper(preorder, inorder, index, 0, preorder.size()-1);
}

/*
//find the preorder index in Inorder array.
//partition InOrder array with this index.
//Left to this is the left subtree and right to this will be the right subtree
//both should be recursive calls
note: index for preorder should be a global and passed by ref. split inorder 
*/



/*--------------------------------------------------------------------------------------------*/

int main()
{
    TreeNode* root = new TreeNode(3);
    /*
    Only a placeholder file. Non-executable
    */
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    // root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    // root->right->left = new TreeNode(13);
    // root->left->right = new TreeNode(17);
    // cout << "max diameter: " << diameterOfBinaryTree(root);

    // vector<vector<int> > res = levelOrder(root);

    // cout << "Result: " << isValidBST(root);

    // cout << "Result: " << kthSmallest(root, 1);

    cout << "\nLa fin! \n";
    return 0;
}