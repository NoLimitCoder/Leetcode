#define rep(i,n) for(int i = 0; i<n; ++i)
auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 'c'; }();
class Solution {
public:

    void merge(int l, int m, int r, vector<int>& A) {
        int n1 = m-l+1, n2 = r-m-1+1, L[n1], R[n2], i = 0, j = 0, k = l;
        rep(v,n1)   L[v] =   A[l+v];       rep(v,n2) R[v] = A[m+1+v];
        while(i<n1 && j<n2)  A[k++] = (L[i] < R[j])? L[i++] : R[j++];
        while(i<n1) A[k++] = L[i++];     while(j<n2) A[k++] = R[j++];
    }

    void mergeSort(int l, int r, vector<int>& A) {
        if(l >= r) return; 
        int m = (l+r)/2; 
        mergeSort(l,m,A); mergeSort(m+1,r,A); 
                 merge(l,m,r,A);
    }


    vector<int> sortArray(vector<int>& A) {
        mergeSort(0,A.size()-1,A); return A;
    }
};
