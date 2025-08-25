class Solution {
public:
    long long ncr(int n,int r){
        long long res=1;
        for(int i=1;i<=r;i++){
            res=res*(n-r+i)/i;

        }
        return res;
    }

    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int M=min(m-1,n-1);
        return (int)ncr(N,M);
    }
};