class Solution {
protected:
    string addOne(string binary) {
          int carry = 1;
          int len = binary.length();
          for (int i = len - 1; i >= 0; i--) {
            int digit = binary[i] - '0';
            digit += carry;
            carry = digit / 2;
            binary[i] = (digit % 2) + '0';
            if (carry == 0) {
              break;
            }
          }
          if (carry == 1) {
            binary = '1' + binary;
          }

          return binary;
    }
    string divideBy2(const std::string& binary) {
        if(binary == "0" || binary.empty())return "0";
        string result = binary.substr(0, binary.size() - 1);
        if (result.empty())return "0";
       return result;
   }
 
public:
    int numSteps(string s) {
        if(s=="1")return 0;
        int n = s.size();
        return s[n-1]=='0'?1+numSteps(divideBy2(s)):1+numSteps(addOne(s));
    }
};