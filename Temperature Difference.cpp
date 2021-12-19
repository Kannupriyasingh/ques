/***************************************************************************************************************************************************************
Henry is planning to go on a trip with Oswald, to multiple cities (possibly in different countries) in the month of June. Since Henry is a penguin, he is very sensitive to temperature fluctuations. You have an array of average temperatures of n cities which they are planning to visit. You are their trip planner. For every new city that Henry visits, his frustration level increases by maximum temperature encountered so far – minimum temperature encountered so far in the trip (max temp-min temp).

Find the minimum total frustration for Henry which can be achieved by rearranging the order of cities for his visit.

Input Format

The first line of input contains a single integer n denoting the number of cities Oswald and Henry are planning to visit. The next line contains n space separated integers denoting the average temperature of the cities in the month of June.

Constraints

N<=2000 1<= temp[i] <= 1000000000

Output Format

Return the minimum total frustration of Henry which can be achieved by rearranging the order of cities for his visit.

Sample Input 0

5
25 15 5 30 16
Sample Output 0

51
Explanation 0

The cities can be rearranged in this order: 15 16 25 30 5 This will lead to a total frustration of: 0+1+10+15+25=51 which is the minimum possible.
***************************************************************************************************************************************************************************/

//My solution is not Working with all testcases

#include <bits/stdc++.h>
using namespace std;

void change(int n, vector<int>&a){
    int val = a[0];
    for(int i = 0; i < (n-1); i++){
        a[i] = a[i+1];
    }
    a[n-1] = val;
}
long long int temperatureDifference(int n,vector<int> a){
    //int ans = 0, mini = a[0], maxi = a[0];
   /* for(int i = 0; i < n; i++){
        ans += (maxi - mini);
        maxi = max(maxi, a[i]);
        mini = min(mini, a[i]);
    }*/
    
    sort(a.begin(), a.end()); 
    int times = 0, res1 = INT_MAX, ans = 0, mini, maxi;

    while(times < n){
        ans = 0;
        mini = a[0], maxi = a[0];
        for(int i = 0; i < n; i++){
        ans += (maxi - mini);
        maxi = max(maxi, a[i+1]);
        mini = min(mini, a[i+1]);
        }
        times++;
        res1 = min(res1, ans);
        
        int val = a[0];
        for(int i = 0; i < (n-1); i++){
            a[i] = a[i+1];
        }
        a[n-1] = val;
    }
    
    sort(a.begin(), a.end(), greater<int>()); 
    times = 0;
    int res2 = INT_MAX;

    while(times < n){
        ans = 0;
        mini = a[0], maxi = a[0];
        for(int i = 0; i < n; i++){
        ans += (maxi - mini);
        maxi = max(maxi, a[i+1]);
        mini = min(mini, a[i+1]);
        }
        times++;
        res2 = min(res2, ans);
        
        int val = a[0];
        for(int i = 0; i < (n-1); i++){
            a[i] = a[i+1];
        }
        a[n-1] = val;
    }
    return min(res1, res2);
}


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<temperatureDifference(n,a);
    return 0;
}
