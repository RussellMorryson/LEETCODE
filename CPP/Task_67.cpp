/*Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
 
Constraints:
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/
class Solution {
public:
    string addBinary(string a, string b) { 
        int len1 = a.length();
        int len2 = b.length();
        string ls1 = len1 < len2 ? a : b;
        string ls2 = len1 < len2 ? b : a;
        for (int i = ls1.length(); i < ls2.length(); ++i) ls1 = '0'+ls1;
        string result;
        int carry = 0;
        for (int i = ls2.length() - 1; i >= 0; --i) {
            int bit1 = ls1.at(i) - '0';
            int bit2 = ls2.at(i) - '0';
            char sum = (bit1 ^ bit2 ^ carry) + '0';
            result = sum + result;
            carry = (bit1&carry)|(bit2&carry)|(bit1&bit2);
        }
        if (carry) result = '1' + result;
        return result;
    }
};