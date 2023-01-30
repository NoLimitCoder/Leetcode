class Solution {
public:
    int tribonacci(int n) {
          vector<int> V(38);
          V[0] = 0; V[1] = 1; V[2] = 1;
          for(int i = 3; i<=37; ++i){
              V[i] = V[i-1]+V[i-2]+V[i-3];
          }
          return V[n];
    }

};
