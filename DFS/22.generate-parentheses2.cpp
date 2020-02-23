/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
/* solution one (5.31%) : permutation */
private:
    vector<string> result;
public:
    bool isRight(char *str, int n)
    {   
        if (!str) return false;
	    stack<char> s;
	    for (int i = 0; i < n; i++) {
    		char ch = str[i];
	    	if (ch == '(') s.push(ch);
		    else if (ch == ')') {
			    if (s.empty()) return false;
			    if (s.top() == '(') {
				    s.pop();
				    continue;
			    } else return false;
		    }
	    }
	    if (s.empty()) return true;
	    else return false;
    }

    void gePar(int n, char *p, char *res, int cur)
    {
    	if (cur == n ) {
	    	if (isRight(res, n)) {
                string t;
				/* followings are wrong */
				// string t(res);
				// result.push_back(t);
		    	for (int i = 0; i < n; i++) t.push_back(res[i]);
                result.push_back(t);
		    }
	    }
	    else for (int i = 0; i < n; i++) {
    		if (!i || p[i] != p[i-1]) {
                int c1 = 0, c2 = 0;
                for (int j = 0; j < cur; j++) if (res[j] == p[i]) c1++;
                for (int j = 0; j < n; j++) if (p[i] == p[j]) c2++;
                if (c1 < c2) {
				    res[cur] = p[i];
                    gePar(n, p, res, cur+1);
                }
            }
	    }
    }

    vector<string> generateParenthesis(int n) {
        if (n == 0) { result.push_back("") ;return result; }

        char *str = new char[n*2+1];
        char *res = new char[n*2+1];

        for (int i = 0; i < n; i++)
            str[i] = '(';
        for (int i = n; i < n*2; i++)
            str[i] = ')';
        str[n*2] = '\0';

        gePar(n*2, str, res, 0);
        
        return result;
    }
};
// @lc code=end

