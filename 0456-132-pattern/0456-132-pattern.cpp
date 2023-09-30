/* TLE \U0001f60b
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                for(int k=j+1; k<n; ++k){
                    if(nums[i]<nums[k] && nums[k]<nums[j]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int three = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < three) return true;
            while (!st.empty() && nums[i] > st.top()) {
                three = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};