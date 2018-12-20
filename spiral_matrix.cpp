/* problem:
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
*/

#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    
    int a[5][2] = {
 {1, 2},{3,4},
 {5, 6},{7,8},
 {9, 10}}; 
    
        int m = 5,i;
        int n = 2;
        int l = 0, k = 0,z = 0;
        vector<int> v(m*n);
        cout<<"here";    
        
        while (k < m && l < n) 
    { 
        /* Print the first row from the remaining rows */
        for (i = l; i < n; ++i) 
        { 
            //printf("%d ", a[k][i]);
            v[z] = a[k][i];
            z++; 
        } 
        k++; 

        /* Print the last column from the remaining columns */
        for (i = k; i < m; ++i) 
        { 
            //printf("%d ", a[i][n-1]); 
            v[z] = a[i][n-1];
            z++; 
        } 
        n--; 

        /* Print the last row from the remaining rows */
        if ( k < m) 
        { 
            for (i = n-1; i >= l; --i) 
            { 
                //printf("%d ", a[m-1][i]);
                v[z] = a[m-1][i];
                z++;  
            } 
            m--; 
        } 

        /* Print the first column from the remaining columns */
        if (l < n) 
        { 
            for (i = m-1; i >= k; --i) 
            { 
                //printf("%d ", a[i][l]);
                v[z] = a[i][l];
                z++;  
            } 
            l++;     
        }        
    }

    for (int i  = 0; i < v.size(); i++)
    {
        cout<<" "<<v[i];
    }
    return 0;
}