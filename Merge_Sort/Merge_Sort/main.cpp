//
//  main.cpp
//  Merge_Sort
//
//  Created by Himanshu Ahuja on 11/07/16.
//  Copyright © 2016 Himanshu Ahuja. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace::std;

/////// Merging two sorted vectors into one sorted vector////////
vector<int> merge (vector<int> L, vector<int> R, vector<int> A)
{
    int i =0, j = 0, k = 0;
    unsigned long nL = L.size();
    unsigned long nR = R.size();
    while ( i < nL && j < nR ){
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<nL)
    {
        A[k] = L[i];
        i++; k++;
    }
    while (j<nR)
    {
        A[k] = R[j];
        j++; k++;
    }
    return A;
}

//////    Dividing and Sorting  ///////////////

vector<int> mergeSort(vector<int> A){
    unsigned long n = A.size();
    if(n < 2)
        return A;
    unsigned long mid = n/2;
    vector<int> left(mid, 0);
    vector<int> right(n - mid, 0);
    unsigned long i;
    for (i = 0; i < mid; i++)
        left [i] = A[i];
    for (i = mid; i<n; i++)
        right [i - mid] = A[i];
    left = mergeSort(left);
    right = mergeSort(right);
    return merge (left, right, A);
}
int main() {
    vector<int> A = {2, 7, 3 , 4 , 1 , 5, 90, 89, 5, 100, 9, 56};
    
    vector<int> result = mergeSort(A);
    for  ( int i = 0; i < result.size(); i++)
        cout<<result[i]<<" ";
    return 0;
}
