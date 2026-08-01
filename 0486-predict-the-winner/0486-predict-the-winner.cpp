class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        function<int(int ,int )>calc=[&](int i , int j)->int{
            if(i==j)
                return nums[i];
            int l = nums[i] - calc(i+1,j);
            int r = nums[j]-calc(i,j-1);
            return max(l,r);
        };     
        return calc(0,nums.size()-1)>=0;
    }
};