#include <bits/stdc++.h>
using namespace std;

/*
f(n,k-1)=(n-1)^k-1-f(n,k-1);
f(n,k)=(n-1)^k-1+(n-1)^k-2+(n-1)^k-3...(n-1);
f(n,k)=(n-1)^k-1-(n-1)^k-2+(n-1)^k-3...(n-1);

f(n,k)/(n-1)=(n-1)^k-2+(n-1)^k-3+(n-1)^k-4....1
f(n,k)+f(n,k)/(n-1)=(n-1)^k-1+(-1)^k
f(n,k)*((n-1)+1)/(n-1)=(n-1)^k-1+(-1)^k
f(n,k)*((n-1)+1)/(n-1)=(n-1)^k-1+(-1)^k
f(n,k)=((n-1)^k+(-1)^k(n-1))/n
*/
int numofways(int n, int k)
{
    int p = 1;
    if (k % 2 != 0)
    {
        p = -1;
    }
    return (pow(n - 1, k) + p * (n - 1)) / n;
}

int main()
{
    int n = 4;
    int k = 2;
    cout << numofways(n, k);
    return 0;
}