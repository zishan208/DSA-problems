

class Solution {
  private:
  void s(TreeNode* root,int& sum,int psum){
    if (root==nullptr) {
      
        return;
    }
     psum=psum*10+root->val;
    if(!root->left && !root->right){
        sum+=psum;

    }
   
    s(root->left,sum,psum);
    s(root->right,sum,psum);
  }
public:
    int sumNumbers(TreeNode* root) {
      int sum=0;
      s(root,sum,0);
      return sum;
        
    }
};

