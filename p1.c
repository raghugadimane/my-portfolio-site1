#include <limits.h>

// GreekForGreeks example problem: maximum contiguous subarray sum.
// Input:
//   First line: integer n
//   Second line: n integers
// Output:
//   Maximum sum of any contiguous subarray.
int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    long long maxSum = LLONG_MIN;
    long long currentSum = 0;

    for (int i = 0; i < n; ++i) {
        long long x;
        if (scanf("%lld", &x) != 1) {
            return 0;
        }
        if (i == 0) {
            currentSum = x;
            maxSum = x;
        } else {
            if (currentSum + x < x) {
                currentSum = x;
            } else {
                currentSum += x;
            }
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }

    printf("%lld\n", maxSum);
    return 0;
}
'