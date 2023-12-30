//Approach
/*Create an unordered map (mp) to store the frequency of each character.
Iterate through each string in the input vector (words).
For each character in the current string, increment its frequency in the map.
After counting the frequencies, iterate through the map and check if the frequency of each character is divisible by the total number of strings (n).
If any character's frequency is not divisible by n, return false. Otherwise, return true.
*/
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> map;
        for(auto it:words){
            for(auto i:it){
                map[i]++;
            }
        }
        int n = words.size();
        for(auto it:map){
            if(it.second % n== 0)continue;
            else return false;
        }
        return true;  
    }
};
