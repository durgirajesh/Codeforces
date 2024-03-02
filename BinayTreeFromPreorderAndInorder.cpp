class Solution {
public:
    TreeNode* build(vector<int> pre, vector<int> in, int e){
        TreeNode* root = new TreeNode(e);

        vector<int> :: iterator it;
        it = find(in.begin(), in.end(), e);
        auto x = (it - in.begin());

        vector<int> leftin, rightin;
        if(x < in.size()){
            leftin = vector<int> (in.begin(), in.begin() + x);
        }
        if(x + 1 < in.size()){
            rightin = vector<int> (in.begin() + x + 1, in.end()); 
        }

        auto it1 = find(pre.begin(), pre.end(), e);
        auto index1 = (it1 - pre.begin());

        vector<int> prel, prer;
        if(!leftin.empty() && !rightin.empty()){
            int k = leftin[leftin.size()-1];
            
            auto it2 = find(pre.begin(), pre.end(), k);
            auto index2 = (it2 - pre.begin());

            
            if(index1 +1 < pre.size() && index2 + 1 < pre.size()){
                prel = vector<int> (pre.begin() + index1 + 1, pre.begin() + leftin.size() + 1);
                prer = vector<int> (pre.begin() + leftin.size() + 1, pre.end());
            }

            if(prel.size() > 0 && prer.size() > 0){
                root->left = build(prel, leftin, prel[0]);
                root->right = build(prer, rightin, prer[0]);
            }
        }else if(leftin.empty() && !rightin.empty()){
            if(index1 + 1 < pre.size()){
                prer = vector<int> (pre.begin() + index1 + 1, pre.end());
            }

            if(prer.size()){
                root->right = build(prer, rightin, prer[0]);
            }
        }else if(!leftin.empty() && rightin.empty()){
            if(index1 + 1 < pre.size()){
                prel = vector<int> (pre.begin() + index1 + 1, pre.end());
            }

            if(prel.size() > 0){
                root->left = build(prel, leftin, prel[0]);
            }
        }

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, preorder[0]);
    }
};
