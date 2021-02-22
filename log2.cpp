/*  
    This program implements the BBP/Spigot algorithm to generate a few binary
    digits of Log(2) beginning immediately after a given position id, or in other words
    beginning at position id + 1.
    This is a simplified version of the same alogrithm for pi.
    For more details, please see the Wikipedia page below and the references within.
    https://en.wikipedia.org/wiki/Bailey%E2%80%93Borwein%E2%80%93Plouffe_formula
*/

/*  Songhao Li    2021-02-12 */

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>

using namespace std;

int expo(int b, int p, int k) {
    // compute b^p mod k
    long r = 1, t = 1;
    while (t <= p/2) t = t*2;
    while (t > 0) {
        r = (r*r)%k;
        if (p >= t) {
            r = (b*r) % k;
            p = p-t;
        }
        t = t/2;
    }
    return r;
}

double intprt(int b, int d) {
    // compute the fractional part of the sum of (b^(d-k) mod k)/k, k = 1, ..., d.
    double ans = 0;
    for (int k = 1; k <= d; k++) {
        ans += ((double) expo(b, d-k, k)) / k;
        ans = ans - (int) ans;
    }
    return ans;
}

double fracprt(int b, int d) {
    // compute the sum of b^(d-k)/k, k = d+1, ...
    double ans = 0;
    long long x = d;
    for (int i = 1; x < 1e15; i++) {
        x = 2*x;
        x = x/(d+i-1)*(d+i);
        ans += ((double) 1) / x;
        ans = ans - (int) ans;
    }
    return ans;
}

string dbltobin(double d) {
    // for double 0 < x < 1, convert it to its 10-digit binary representation
    string ans;
    for (int i = 0; i < 10; i++) {
        if (d >= 0.5) {
            ans.push_back('1');
            d = (d-0.5)*2;
        }
        else {
            ans.push_back('0');
            d = d*2;
        }
    }
    return ans;
}

int main()
{
    int x = 2;
    /*  The program computes the digites of log(x)-log(x-1) in general.
        In the case x = 2, we have log(2)-log(1)=log(2)
     */

    int id = 1e7;
    /*  id is the digit position.  Digits generated follow immediately after id. */
    cout << " position = " << id << endl;
    
    double ans = intprt(x, id) + fracprt(x, id);
    ans =  ans - (int) ans;
    /* ans is the fractional part immediately after id. */
    cout << " fraction = " << setprecision(15) << ans << endl;
    

    string ansbin = dbltobin(ans);
    /* ansbin is the binary digits immediately after id. */
    cout << " binary digits = " + ansbin << endl;

    return 0;
}