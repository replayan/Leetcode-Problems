/* o(nLogN) solution using sorting
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-1; ++i){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};
*/

// Hashtable solution o(N)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> alreadyAvail;
        for (int i:nums) {
            if (alreadyAvail.count(i)) {
                return true;
            }
            alreadyAvail.insert(i);
        }
        return false;
    }
};
