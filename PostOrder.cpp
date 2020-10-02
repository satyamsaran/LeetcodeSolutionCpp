class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        TreeNode* p=root;
        st.push(p);
        while(!st.empty()){
            if(p!=NULL)cout<<p->val<<":"<<st.top()->val<<endl;
            if(p==NULL)cout<<"NULL :"<<st.top()->val<<endl;
            if(p==NULL){
                if(st.top()->right==NULL){
                    ans.push_back(st.top()->val);
                    p=st.top();
                    st.pop();
                }else{
                    p=st.top()->right;
                    st.push(p);
                }
                continue;
            }
            if(p==st.top()){
                p=p->left;
                if(p!=NULL){
                    //p=p->left;
                    st.push(p);
                }
                continue;
            }else{
                if(st.top()->right==p || st.top()->right==NULL){
                    ans.push_back(st.top()->val);
                    p=st.top();
                    st.pop();
                }else{
                    p=st.top()->right;
                    st.push(p);
                }
            }
            
            
        }
        return ans;
    
    }
};
