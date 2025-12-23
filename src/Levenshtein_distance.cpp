#include <iostream>     // cin, cout
#include <vector>       // vector
#include <string>       // string
#include <algorithm>    // min, sort, transform

using namespace std;

int levenshtein_distance(const string &input,const string &target){
    const int m=target.size(); // length of target string
    const int n=input.size(); // length of input string
    vector<vector<int>> ld(m+1,vector<int>(n+1,0)); // 2D vector for distance matrix
    for(int i=0;i<n+1;i++) ld[0][i]=i;
    for(int i=0;i<m+1;i++) ld[i][0]=i;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(input[i-1]==target[j-1]){
                ld[i][j]=ld[i-1][j-1]; // No operation needed
            }else{
                int insert=ld[i][j-1]+1;
                int del=ld[i-1][j]+1;
                int replace=ld[i-1][j-1]+1;
                ld[i][j]=min({insert,del,replace}); // Minimum of the three operations
            }
        }
    }
    return ld[n][m]; // Return the Levenshtein distance
}