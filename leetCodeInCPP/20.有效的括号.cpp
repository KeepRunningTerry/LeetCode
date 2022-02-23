class Solution {
public:
    bool isValid(string s) {
       int n = s.size();
       if(n%2==1){
           return false;
       }

       unordered_map<char,char> pairs = {
           {')','('},
           {']','['},
           {'}','{'}
       };

       stack<char> stack;
       for(char ch : s){
           if(pairs.count(ch)){
               if(stack.empty() || stack.top() != pairs[ch]){
                   return false;
               }
               stack.pop();
           }else{
               stack.push(ch);
           }
       }
       return stack.empty();
    }
};
