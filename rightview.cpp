/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

vector<int> trav(TreeNode* root);


vector<int> trav(TreeNode* root){
    if(!root){
        return {};
    }
    
    queue<TreeNode*> level;
    level.push(root);
    vector<int> result;
    
    while(!level.empty()){
        int n = level.size();
        vector<int> arr;
        while(n > 0){
            TreeNode* node = level.front();
            arr.push_back(node->val);
            level.pop();
            
            if(node->left){
                level.push(node->left);
            }
            
            if(node->right){
                level.push(node->right);
            }
            n--;
        }
        if(arr.size() > 0){
            result.push_back(arr[arr.size() - 1]);
        }
    }
    
    return result;
    
}

int main()
{
    TreeNode* root = new TreeNode();
    root->val = 12;
    
    TreeNode* node1 = new TreeNode();
    node1->val = 7;
    root->left = node1;
    
    TreeNode* node2 = new TreeNode();
    node2->val = 1;
    root->right = node2;
    
    TreeNode* node3 = new TreeNode();
    node3->val = 9;
    node1->left = node3;
    
    
    
    TreeNode* node4 = new TreeNode();
    node4->val = 10;
    node2->left = node4;
    
    TreeNode* node5 = new TreeNode();
    node5->val = 5;
    node2->right = node5;
    
    TreeNode* node6 = new TreeNode();
    node6->val = 3;
    node3->left = node6;
    
    vector<int> answer = trav(root);
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << " ";
    }

    return 0;
}

