class Solution {
public:
    int countPalindromes(string s) {
        int n = s.size(); int MOD = 1'000'000'007; // Logic: maintain counts in suf_single, maintain two digit counts in suf
        vector<int> suf_single(10); vector<vector<int>> suf(10, vector<int>(10));
        vector<int> pref_single(10); vector<vector<int>> pref(10, vector<int>(10));

        for (int i = n - 1; i > -1; i--) { 
            int b = s[i] - '0'; // build suffix counts first
            for (int a = 0; a < 10; a++) {
                suf[b][a] += suf_single[a]; // Number of two digit combinations possible
            }
            suf_single[b] += 1; // Update the suf_single. You update after because it would otherwise affect suffix double digit calculation.
        }

        long long result = 0;
        for (int i = 0; i < n; i++) {
            int b = s[i] - '0';
            suf_single[b] -= 1; // Tear down should have opposite order. 

            for (int a = 0; a < 10; a++) { // single first, then double digit.
                suf[b][a] -= suf_single[a];
            }

            for (int a = 0; a < 10; a++) { // calulate results
                for (int new_b = 0; new_b < 10; new_b++) { // has to be new_b because you have to calculate for all 10 b digits having torn down the count for b
                    result = (result + ((long long)pref[a][new_b] * suf[new_b][a])) % MOD;
                }
            }

            for (int a = 0; a < 10; a++) { // b build up prefix
                pref[a][b] += pref_single[a];
            }
            pref_single[b] += 1;
        }
        return result;
    }
};

