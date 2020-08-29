#include<iostream>
using namespace std;


vector<vector<int>> findBeforeMatrix(vector<vector<int>> after)
{
    int m = after.size() //No of Rows
    int n = after[0].size() // No of Columns

    vector<vector<int>> before(m,vector<int>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            before[i][j] =after[i][j];
            if(i-1>=0 && j-1>=0) before[i][j]+=after[i-1][j-1];
            if(i-1>=0) before[i][j]-=after[i-1][j];
            if(j-1>=0) before[i][j]-=after[i][j-1];
        }
    }

    return before;
}



int main()
{
    int noOfRows;
    int noOfColumns;

    cin>>noOfRows;
    cin>>noOfColumns;

    vector<vector<int>> input(noOfRows,vector<int>(noOfColumns));

    for(int i=0;i<noOfRows;i++)
        for(int j=0;j<noOfColumns;j++)
            cin>>input[i][j];

    return findBeforeMatrix(input);
}
