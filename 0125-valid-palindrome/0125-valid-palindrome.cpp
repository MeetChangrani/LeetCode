class Solution {
public:
    bool isPalindrome(string s) {
        string filtered = "";
        stack<char> s1;
        for (char c : s) {
            if (isalnum(c)) {
                c = tolower(c);
                filtered += c;
                s1.push(c);
            }
        }
        string rev = "";
        while (!s1.empty()) {
            rev += s1.top();
            s1.pop();
        }
        return filtered == rev;
    }
};
