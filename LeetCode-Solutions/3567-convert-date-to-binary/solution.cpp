class Solution {
public:
    string convertDateToBinary(string date) {
        string ans = "";
        string tmp = "";
        for(int i = 0; i<date.size(); ++i){
            char c = date[i];
            if(c == '-'){
                cout << tmp << '\n';
                int t = stoi(tmp);
                string t2 = "";
                while(t > 0){
                    t2 += to_string(t%2);
                    t/=2;
                }
                reverse(t2.begin(), t2.end());
                ans+= t2; ans+= "-";
                tmp = "";
            }
            else if(i == date.size()-1){
                tmp += c;
                cout << tmp << '\n';
                int t = stoi(tmp);
                string t2 = "";
                while(t > 0){
                    t2 += to_string(t%2);
                    t/=2;
                }
                reverse(t2.begin(), t2.end());
                ans+= t2;
                tmp = "";
            }
            else{
                tmp += c;
            }
        }
        return ans;
    }
};
