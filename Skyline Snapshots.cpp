/****************************************************************************************************************************************************************
Having completed his ultimate goal of uncovering Spiderman's identity, JJJ has gone to Dubai for a vacation. There, he wants to take pictures of the city's beautiful skyline.

The skyline consists of N buildings, the i-th building has a height of A[i]. Since he might not necessarily be able to capture all of the buildings in a single picture he has decided to take snaps of segments of the skyline such that each building gets included in exactly one of the snaps.

Also, he will only take snaps of 'picturesque' segments of the skyline. A segment is called 'picturesque' only if the heights of leftmost and rightmost buildings in the segment are non-coprime (i.e. gcd(A[l], A[r]) > 1, where l and r denote the leftmost and rightmost buildings respectively).

JJJ still has a lot of the city left to explore and thus wants to take as few photos as possible to save memory in his camera. Help him figure out the minimum number of photographs that must be taken to cover the whole skyline such that the segment in each photo is picturesque.

Input Format

The first line will consist of an integer N denoting the number of buildings in the skyline.

The next line will contain N integers, the heights of the buildings.

Constraints

2 <= N <= 200000

1 <= A[i] <= 1000000

Output Format

The output must consist of a single integer denoting the minimum number of photographs required.

Sample Input 0

5
2 4 6 3 9
Sample Output 0

2
Explanation 0

We can make segments of - (2,4) and (6, 3, 9), or (2, 4, 6) and (3, 9).
************************************************************************************************************************************************************************/

//My solution is not working for all testcases

#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int skylineSnapshots(int N, vector<int>A){
    int i = 0, j = N-1;
    int ans = 0;
    while(i < N){
        if(gcd(A[i], A[j]) > 1){
            ans++;
            i = j+1;
            j = N-1;
        }
        else{
            j--;
        }
    }
    return ans;
}

int main(){
    int N;
    cin>>N;
    vector<int>A(N);
    for(auto &x:A)cin>>x;
    cout<<skylineSnapshots(N, A)<<"\n";
}
