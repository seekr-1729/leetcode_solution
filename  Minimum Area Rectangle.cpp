/* problem:
Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.

 

Example 1:

Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4
*/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map <int , set<int>> mp;
        int area = INT_MAX;
        
        for (auto p : points)
        {
            mp[p[0]].insert(p[1]);
        }
        
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            if(i->second.size() < 2) continue;
            for (auto j = next(i); j != mp.end(); j++)
            {
                if(j->second.size() < 2) continue;
                vector<int> y;
                set_intersection(i->second.begin(),i->second.end(),j->second.begin(),j->second.end(),inserter(y,y.begin()));
                for (int k = 1; k < y.size(); ++k)
                    area = min(area, abs(j->first - i->first) * (y[k] - y[k - 1]));
                                    
            }       
        }
        
        return area == INT_MAX ? 0 : area;
    }
};