
class Solution {
  private:

  bool isvalid(TreeNode* root,long long min,long long max){
    if(root==nullptr) return true;
    if(root->val>=max || root->val<=min){
      return false;
    }

    return isvalid(root->left,min,root->val) && isvalid(root->right,root->val,max);
  }

  public:
  bool isValidBST(TreeNode* root) {

    return isvalid(root,LONG_MIN,LONG_MAX);


  }

};

