/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, int> mp;
        map<char, int> st;

        for (int i = 0; i < s.size(); i++) mp[s[i]]++; 
        for (int i = 0; i < t.size(); i++) st[t[i]]++; 

        if (st == mp) return true;
        else return false;       
    }
};
// @lc code=end

