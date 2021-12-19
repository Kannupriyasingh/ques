//PhonePe Externship Assessment Questions
/**********************************************************************************************************************************************
Mr. Da Vinci is an artist who wants to make money. He has n paintings which he wishes to sell.
The main issue is that he can only sell one painting every day. Due to a low demand of paintings, the price of every painting depreciates by 5 dollars each day. Obviously, the price cannot depreciate to a value below 0, in which case the price becomes stagnant at zero.
Find the maximum profit which Mr. Da Vinci can get if he sells the paintings optimally.
Since the maximum profit could be a large number, print it modulo 10^9 + 7.

Input Format

The first line will have an integer n: denoting the number of paintings to be sold.
The second line contains n space separated integers denoting the initial prices of the paintings.

Constraints

n<=10^6
0

Output Format

Return the maximum profit which Mr. Da Vinci can get modulo 10^9 + 7.

Sample Input 0

3
6 6 7
Sample Output 0

8
Explanation 0

On the first day, Mr. Da Vinci sells the painting at index 2 to earn a profit of 7 dollars (0 based indexing).
On the next day, Mr. Da Vinci sells the painting at index 1 to earn a profit of (6-1) 1 dollar.
On the third day, Mr. Da Vinci earns no profit on selling the painting at index 0.
***************************************************************************************************************************************************************/

//This solution is working for all Testcases

#include <bits/stdc++.h>
using namespace std;
int sellingPaintings(int n, vector<int>&vec){
    int ans = 0, idx = 0, dec = 0;
    sort(vec.begin(), vec.end(), greater<int>());
    while((vec[idx] - dec) > 0){
        ans = (ans%1000000007 + (vec[idx] - dec)%1000000007)%1000000007;  
        dec += 5;
        idx++;
    }
return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    
    cout<<sellingPaintings(n, vec);
}
