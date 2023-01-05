class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> non_zero_values;
        int zero = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 0) zero++;
            else non_zero_values.push_back(nums[i]);
        }
        if(zero) non_zero_values.push_back(0);

        sort(non_zero_values.begin(),non_zero_values.end());
        map<vector<int>,int> mp;
        vector<vector<int> > ans;
        if(non_zero_values.size() > 2)
        for(int i = 0;i <= non_zero_values.size()-(int)3;i++){
            for(int j = i+1;j <= non_zero_values.size()-2;j++){
                int need = 0 - (non_zero_values[i] + non_zero_values[j]);
                int pos = lower_bound(non_zero_values.begin()+j+1,non_zero_values.end(),need) - non_zero_values.begin();
                if(pos > j && pos < non_zero_values.size() && non_zero_values[pos] == need){
                    vector<int> temp;
                    temp.push_back(non_zero_values[i]);
                    temp.push_back(non_zero_values[j]);
                    temp.push_back(non_zero_values[pos]);
                    if(mp[temp] == 0){
                        mp[temp]++;
                        ans.push_back(temp);
                    }
                }
            }
        }
        if(zero > 2){
            vector<int> temp(3,0);
            ans.push_back(temp);
        }
        return ans;
    }
};
