class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string tmp;
        generateParenthesis(ret,tmp,n,n);
        return ret;
    }

    void generateParenthesis(vector<string>& ret, string& tmp, 
        int left, int right){
        if(left == 0 && right == 0){
            ret.push_back(tmp);
            return;
        }

        if(left!=0){
            tmp.push_back('(');
            generateParenthesis(ret,tmp,left-1,right);
            tmp.pop_back();
        }

        if(right!=0 && right > left){
            tmp.push_back(')');
            generateParenthesis(ret,tmp,left,right-1);
            tmp.pop_back();
        }
    }
};