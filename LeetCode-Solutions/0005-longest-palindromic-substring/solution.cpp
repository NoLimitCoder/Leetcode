class Solution {
public:

/*Brute Force Methods:

    bool isPalindrome(string str){
        int n = str.size();
        for(int i = 0; i<n/2; ++i){
            if(str[i]!= str[n-i-1])
                return false;
        }
        return true;
    }*/

    string substring(string &s, int x, int y){
        string ans = "";
        for(int i = x; i<=y; ++i){
            ans += s[i];
        }
        return ans;
    }

    //Greedy methods:
    int checkPalindrome(int i, int j, string &s){
        int count = 0;
        while(i >= 0 && j < s.size()){
            if(s[i] == s[j]){
                count++; i--; j++;
            }
            else{
                break;
            }
        }
        return count;
    }
       
    string longestPalindrome(string s) {


    //Greedy:
    int Maxlen = 0;
    string best = "";
    for(int i = 0; i<s.size(); ++i){
        int len = checkPalindrome(i,i,s);
        if(len > Maxlen){
            Maxlen = len;
                best = substring(s,i-len+1,i+len-1);
        }
        len = checkPalindrome(i,i+1,s);
        //cout << len << '\n';
        if(len >= Maxlen){
            Maxlen = len;
            cout << len <<", i: " << i <<'\n'; 
            best = substring(s,i-len+1,i+len);
        }
    }
    return best;

        //brute force:
        /*
        if(s.size() == 1) return s;
        string best = "";
        for(int i = 0; i <= s.size(); ++i){
            for(int j = 0; j<= i; ++j){
                string str = substringg(s,j,i);
                //cout << "i: "<<i << " j: "<< j << '\n';
                //cout << str << '\n'; ty
                if(isPalindrome(str) && str.size() > best.size()){
                    best = str;
                }
            }
        }
        return best;*/
    //O(N^3)

    }
    //abcdbbfcba
};
