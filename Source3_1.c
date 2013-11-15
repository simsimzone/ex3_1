#include <stdio.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v [], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid + 1;
		else if (x > v[mid])
			low = mid + 1;
		else /* found match */
			return mid;
	}
	return -1; /* no match */
}

int binsearch2(int x, int v [], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (high > (low + 1))//while continues till low and high are next to each other.
	{
		mid = (low + high) / 2;
		if (v[mid] < x)
			low = mid;
		else
			high = mid;
	}
	if (v[low] == x)
		return low;
	else if (v[high] == x)
		return high;
	else
		return -1;

}

//Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice 
//(at the price of more tests outside.) Write a version with only one test inside the loop
//and measure the difference in run-time.
void ex3_1()
{
	int v [] = { 1, 2, 3, 4, 5, 5, 7, 8 };
	int x, n = 8, index;
	x = 5;
	index = binsearch2(x, v, n);
	if (index > 0)
		printf("key found at #%d", index);
	else
		printf("key not found");
}

main()
{
	ex3_1();
	printf("\nPress ENTER to continue. . .\n");
	getchar();
}