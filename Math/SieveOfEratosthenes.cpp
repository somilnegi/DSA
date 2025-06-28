class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        vector<bool> prime(n+1, true);
        prime[0]=prime[1]=false;
        for(int i=2;i<n;i++){
            if(prime[i]){
                count++;
            }
            for(int j=2*i;j<n;j+=i){
                prime[j]=false;
            }
        }
        return count;
    }
};

// More Efficient Approach
for (int p = 2; p * p < limit; p++) {
        // If p is not changed, then it is a prime
        if (mark[p] == true) {
            // Update all multiples of p
            for (int i = p * p; i < limit; i += p)
                mark[i] = false;
        }
    }