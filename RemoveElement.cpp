class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index =0;
for(int i =0;i<nums.size();i++)
{
if(nums[i] == val)
continue;
nums[index] = nums[i];
index+=1;
}
return index;
    }
};
