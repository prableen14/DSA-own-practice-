class Solution {
public:
    int romanToInt(string s) {
      vector<int>v(256);
    v['I']=1,v['V']=5,v['X']=10,v['L']=50,v['C']=100,v['D']=500,v['M']=1000;
        int sum=0;
        for(int i=0;i<s.length();i++){
            if(v[s[i]]<v[s[i+1]]){
                sum=sum-v[s[i]];
            }
            else{
                sum=sum+v[s[i]];
            }
        }
        return sum;    
    }
};
