class Solution {
public:
    int removeElement(vector<int>& vec, int val) {
        vec.erase(std::remove(vec.begin(), vec.end(), val), vec.end());
        return (int) vec.size();
    }
};
