class Solution {
public:
 bool isValid(string s) {
    stack<char> stk;

    for (char ch : s) {
       
        if (ch == '(' || ch == '{' || ch == '[') {
            stk.push(ch);
        } else {
            
            if (stk.empty()) return false;

            char top = stk.top();
            stk.pop();

        
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

  
    return stk.empty();
}
};