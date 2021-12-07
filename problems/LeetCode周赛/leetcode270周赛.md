#### leetcode270周赛  

[leetcode题目链接](https://leetcode-cn.com/contest/weekly-contest-270/)  

### 1.３位偶数

本来应该是考虑到只需要暴力遍历就可以的，但是一开始还是想着用回溯来做

```C++
//思路：
//1.用一个ans记录纳入的数字。这里千万不要想着从digits里面拿３个数出来，拿的这三个数再去做backtrack。直接从digits里面拿３个数出来
//2.用set<int>来记录，避免重复
//3.用一个vector<int>来记录重复使用
//4.递归退出条件：当ans的长度为３,计算这时三个数字组成的和，大于100且是偶数的话，就加入到set(去重)
class Solution {
    vector<int> ans;
    set<int> st;

    void backTrack(vector<int>& digits, vector<int>& used) {
        if(ans.size() == 3) {
            int num = 100*ans[0] + 10*ans[1] + ans[2];
            if(num >= 100 && num%2 == 0) {
                st.insert(num);
            }
            return;
        }

        for(int i = 0; i < digits.size(); i++) {
            if(used[i] == 1) {
                continue;
            }
            used[i] = 1;
            ans.push_back(digits[i]);
            backTrack(digits, used);
            ans.pop_back();
            used[i] = 0;
        }
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> used(digits.size(), 0);
        backTrack(digits, used);
        vector<int> ans;
        for(auto& s : st) {
            ans.push_back(s);
        }
        return ans;
    }
};
```

### 删除链表的中间节点  
[leetcode题目链接](https://leetcode-cn.com/problems/delete-the-middle-node-of-a-linked-list/)  


### 从二叉树一个节点到另一个节点每一步的方向
[leetcode题目链接](https://leetcode-cn.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/)
```C++
//思路：题目让我们求任意两点的路径，需要转换以下思路，A->B其实就是求A->LCA(最近公共祖先)->B
//而A->LCA这段路径是一直往上走的，所以我们填充'U'即可，另外一段就是DFS遍历保存路径
//1.求最近公共祖先LCA
//2.通过两次DFS分别求出LCA到s和d的路径
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
        if(root == nullptr || p == root->val || q == root->val) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        return root;
    }

    string res;
    void dfs(TreeNode* cur, int t, string& path) {
        if(!cur) return;
        if(cur->val == t) {
            res = path;
            return;
        }

        if(cur->left) {
            path += "L";
            dfs(cur->left, t, path);
            path.pop_back();
        }
        if(cur->right) {
            path += "R";
            dfs(cur->right, t, path);
            path.pop_back();
        }

        return;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* a = lowestCommonAncestor(root, startValue, destValue);
        string path = "";
        res = "";
        dfs(a, startValue, path);
        string ans(res.size(), 'U');
        res = "";
        dfs(a, destValue, path);
        ans += res;
        return ans;
    }
};
```