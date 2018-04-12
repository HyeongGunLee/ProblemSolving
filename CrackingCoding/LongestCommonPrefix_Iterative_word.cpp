class Solution {
public:

    string LCP(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        string result = "";
        for (int i = 0, j = 0; i < len1 && j < len2; i++, j++) {
            if (s1[i] != s2[j]) {
                break;
            }
            result.push_back(s1[i]);
        }
        return result;

    }

    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if (len == 0) return "";
        string result = strs[0];


        for (int i = 1; i < len; i++) {
            result = LCP(result, strs[i]);
        }
        return result;
    }
};

