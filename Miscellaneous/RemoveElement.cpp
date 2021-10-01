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
//OR
class Solution {
public int removeElement(vector<int>& nums, int val) {
    if(nums.size()==0) return 0;
    int valid_size=0;
    for(int i =0;i<nums.size();i++)
  {
    if(nums[i] != val){
        nums[valid_size]=nums[i];
        valid_size++;
    }
}
    return valid_size;
}
}
