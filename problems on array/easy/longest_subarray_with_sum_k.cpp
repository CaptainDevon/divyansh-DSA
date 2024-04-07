#include<bits/stdc++.h>
using namespace std;
class solution 
{
    public:
    int longestSubarrayWithSumK(vector<int> a, long long k) {

    int left=0 , right=0;

    long long sum=a[0];

    int maxlen=0;

    int n=a.size();

    while(right<n){

        while(left<right && sum>k){

            sum -= a[left];

            left++;

        }

        if(sum==k){

            maxlen=max(maxlen , right-left+1);

        }

        right++;

        if (right < n) {

            sum += a[right];

        }

    }

    return maxlen;

}
};
int main()
{
    vector<int>a={1,2,3,1,1,1,1,2,1,0,0,2};
    int k=4;
    solution s;
    cout<<s.longestSubarrayWithSumK(a,k);
    return 0;
}