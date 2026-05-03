class Solution {
public:
    bool isPrime(int n) {
        if (n<=1)return false;
        for(int i=2;i*i<=n;i++) {
            if (n%i==0) return false;
        }
        return true;
    }

    int rev(int n){
        int num=0;
        while(n!=0){
            int digit=n%10;    
            num=num*10+digit; 
            n=n/10;
        }
        return num;
    } 
    int rangeSum(int start,int end){
        int sum=0;
        for(int i=start;i<=end;i++){
            if(isPrime(i)){
                sum+=i;
            }
        }

        return sum;

    }
    int sumOfPrimesInRange(int n) {
        int revv = rev(n);
        if(revv>n){
            return rangeSum(n,revv);
        }

        return rangeSum(revv,n);
    }
};