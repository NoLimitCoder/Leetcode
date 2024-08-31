class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string s1 = to_string(num1), s2 = to_string(num2), s3 = to_string(num3);
        while(s1.size() != 4) s1 = "0" + s1;
        while(s2.size() != 4) s2 = "0" + s2;
        while(s3.size() != 4) s3 = "0" + s3;
        string key = "";
        for(int i = 0; i<4; ++i){
            key = key + to_string(min({s1[i]-'0',s2[i]-'0',s3[i]-'0'}));
        }
        return stoi(key);
    }
};
