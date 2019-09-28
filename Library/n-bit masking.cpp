#include <bits/stdc++.h>

using namespace std;

struct NBitMasking {
    int limit;
    int base;
    vector<int> power;

    /**
        initializes the masking system
        with provided base and limit
        limit is the highest power of the base that will be used
    **/
    NBitMasking(int base, int limit): base(base), limit(limit), power(limit + 1, 1) {
        for (int i = 1; i <= limit; i++) {
            power[i] = base * power[i - 1];
        }
    }

    /**
        0 - based
        finds the pos-th bit of the number mask
    **/
    int getBit(int mask, int pos) {
        return (mask / power[pos]) % base;
    }

    /**
        0 - based
        sets the pos-th bit of mask as bit and returns the new mask
    **/
    int setBit(int mask, int pos, int bit) {
        int tmp = (mask / power[pos]) % base;
        mask -= tmp * power[pos];
        mask += bit * power[pos];
        return mask;
    }
};

int main() {


    return 0;
}

// Test With:
// - [C. Anadi and Domino](https://codeforces.com/contest/1230/problem/C)
