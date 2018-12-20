/* problem:
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

    Your returned answers (both index1 and index2) are not zero-based.
    You may assume that each input would have exactly one solution and you may not use the same element twice.

Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

*/



class Solution {
public:
    int binarySearch(int start, int end, const vector<int>& numbers, int n){
        while(start<=end){
            int mid = start + (end-start)/2;
            if(numbers[mid] < n)
                start = mid + 1;
            else if(numbers[mid] > n)
                end = mid - 1;
            else
                return mid;
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        for(int i = 0; i < numbers.size()-1; ++i){
            int compliment = target - numbers[i];
            int r = binarySearch(i+1, numbers.size()-1, numbers, compliment);
            if(r>=0){
                return {i+1,r+1};
            }
        }
        return ans;
    }
};