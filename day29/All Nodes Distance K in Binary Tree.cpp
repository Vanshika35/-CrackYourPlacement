/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

vector<int > ans;

vector<TreeNode*> mypath;
bool findpath(TreeNode* root,TreeNode* target)
{
    //1
    if(root==NULL)
    {
        return false;
    }
    //2
    if(root==target)
    {
        mypath.push_back(root);
        return true;
    }
    //3
    bool fl=findpath(root->left,target);
    if(fl==true)
    {
        mypath.push_back(root);
        return true;
    }

    //4
bool fr=findpath(root->right,target);
    if(fr==true)
    {
        mypath.push_back(root);
        return true;
    }
//5
return false;

}


void kleveldown(TreeNode* root,int k,TreeNode* blocker)
{
    if(root==NULL or k<0 or root==blocker)
    {
        return ;
    }
    if(k==0)
    {
        //we find k distance root and node
ans.push_back(root->val);
    }
    kleveldown(root->left,k-1,blocker);  
    kleveldown(root->right,k-1,blocker);

}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//finction 1
        findpath(root,target); // this push  target to root path in mypath data_strucure

//just print to check mypath 
        // for(auto it:mypath)
        // {cout<<it->val<<" ";}



//function 2
int sz=mypath.size();
     
        for(int i=0;i<sz;i++)
        {
            kleveldown( mypath[i],k-i, i==0?NULL:mypath[i-1]);  
            //2 nd parament is : for every i node distance is reduce by i therfore k-i is pass for every ith node
            //3rd parametr is just to avoid i==0 case : when i==0  then its not have path[i-1] so as a blocker we pass NULL othewise pass path[i-1] as a blocker

        }
        return ans;
    }
};