#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

int dist_zero(int n)
{
    if (n > 0)
        return n;
    return -n;
}

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int compute_closest_to_zero(int n, int ts[n])
{
	int i = 0;
	int dist_neg = 2147483647;
	int dist_pos = 2147483647;
	if (n == 1)
		return ts[0];
    if (n == 0)
		return 0;
    // for (int idx = 0; idx <= n; idx++) {
    //     fprintf(stderr,"%d  ", ts[idx]);
    // }
    // fprintf(stderr,"\nSort\n");
	qsort(ts, n, sizeof(int), compare);
    // for (int idx = 0; idx <= n; idx++) {
    //     fprintf(stderr,"%d  ", ts[idx]);
    // }
    for (i = 0; i <= n; i++) {
		if (ts[i] > 0)
			break;
        if (dist_zero(ts[i]) < dist_neg) {
            dist_neg = dist_zero(ts[i]);
        }
    }
	for (int j = i; j <= n; j++) {
        if (ts[j] != 0 && dist_zero(ts[j]) < dist_pos) {
            dist_pos = dist_zero(ts[j]);
        }
    }
	if (dist_neg < dist_pos)
		return -dist_neg;
	return dist_pos;
}

int main()
{
    int n = 5;
    int ts[] = {-15, -7, -9, -14, -12};
    int solution = compute_closest_to_zero(n, ts);
    printf("%d\n", solution);
    return 0;
}