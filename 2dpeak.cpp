// Finding peak element in a 2D Array.
#include <bits/stdc++.h>
using namespace std;

vector<int> findPeakGrid(vector<vector<int> >& mat)
{

    // Starting point & end point of Search Space
    int stcol = 0,  endcol = mat[0].size() - 1; 
      
    while (stcol <= endcol) { // Bin Search Condition

        int midcol = stcol + (endcol - stcol) / 2,
            ansrow = 0;
      
        // "ansrow" To keep the row number of global Peak
        // element of a column

        // Finding the row number of Global Peak element in
        // Mid Column.
        for (int r = 0; r < mat.size(); r++) {
            ansrow = mat[r][midcol] >= mat[ansrow][midcol]
                         ? r
                         : ansrow;
        }

        // Finding next Search space will be left or right
        bool valid_left = midcol - 1 >= stcol
                          && mat[ansrow][midcol - 1]
                                 > mat[ansrow][midcol];
        bool valid_right = midcol + 1 <= endcol
                           && mat[ansrow][midcol + 1]
                                  > mat[ansrow][midcol];

        // if we're at Peak Element
        if (!valid_left && !valid_right) {
            return { ansrow, midcol };
        }

        else if (valid_right)
            stcol = midcol
                    + 1; // move the search space in right
        else
            endcol = midcol
                     - 1; // move the search space in left
    }

    return { -1, -1 };
}

// Driver Code
int main()
{
    vector<vector<int> > arr = { { 9, 8 }, { 2, 6 } };

    vector<int> result = findPeakGrid(arr);

    cout << "Peak element found at index: " << result[0]
         << "," << result[1] << endl;
    return 0;
}
