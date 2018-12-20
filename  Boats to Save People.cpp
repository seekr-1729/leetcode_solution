/* problem:
The i-th person has weight people[i], and each boat can carry a maximum weight of limit.

Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
         int boat=0,flag=0;
        
        sort(people.begin(),people.end());
       int i = 0, j = people.size() - 1;

        while (i <= j) {
            boat++;
            if (people[i] + people[j] <= limit)
                i++;
            j--;
        }

        return boat;
    }
};