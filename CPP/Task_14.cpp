/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "". 

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string word = strs[0];
        string wordSum = "";
        int count = 0;        
        for(string temp : strs) {
            if (word.length() > temp.length()) {
                count = word.length() - temp.length();
                word = word.substr(0, word.size() - count);
                count = 0;
            }
            for(int i = 0; i < temp.length(); i+=1) { 
                if (word[i] == temp[i]) {
                    wordSum += word[i];
                } else {
                    break;
                }
            }
            word = wordSum;
            wordSum = "";
        }        
        return word;
    }
};