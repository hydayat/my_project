#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = result * i;
    }

    printf("%lld\n", result);
    return 0;
}
