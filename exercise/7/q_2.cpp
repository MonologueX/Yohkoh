class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        std::stack<char> s;
        for (auto i = 0; i < n; i++)
        {
            if (A[i] == '(')
                s.push(A[i]);
            if (A[i] == ')')
            {
                if (s.size() != 0 && s.top() == '(')
                    s.pop();
                else 
                    return false;
            }
        }
        if (s.size() == 0)
            return true;
        return false;
    }
};
