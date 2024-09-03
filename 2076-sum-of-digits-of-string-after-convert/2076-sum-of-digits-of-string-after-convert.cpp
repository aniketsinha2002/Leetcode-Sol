class Solution {
public:
    int getLucky(string s, int k) {
        string temp = "";
        for(int i = 0; i<s.length(); i++){
            temp += to_string(s[i] - 'a' + 1) ;
        }
        int res = 0;
        while(k-- > 0){
            res = 0;
            for(int j = 0; j < temp.size(); j++){
                res += (temp[j] - '0');
            }
            temp = to_string(res);
        }
        return res;
    }
};