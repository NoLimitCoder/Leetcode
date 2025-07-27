class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n2 = row.size();
        // pos[p] = current index of person p in row[]
        vector<int> pos(n2);
        for (int i = 0; i < n2; ++i) 
            pos[row[i]] = i;

        int swaps = 0;
        // process seats in pairs (0–1), (2–3), …
        for (int i = 0; i < n2; i += 2) {
            int x = row[i];
            int want = x ^ 1;          // your partner: 0^1=1,1^1=0, 2^1=3,3^1=2, etc.
            if (row[i+1] == want) 
                continue;              // already sitting together

            // otherwise, swap row[i+1] with wherever 'want' currently sits
            int idx = pos[want];
            swap(row[i+1], row[idx]);

            // update positions in our pos[] array
            pos[row[idx]] = idx;
            pos[row[i+1]] = i+1;

            ++swaps;
        }
        return swaps;
    }
};

