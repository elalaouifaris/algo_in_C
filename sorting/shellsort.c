#include <stdio.h>
#include <criterion/criterion.h>

#include "sorting_utils.h"

void shellsort(int input[], size_t size);

void shellsort(int input[], size_t size) {
	size_t gap;
	size_t scan;
	int position;

	for (gap = size / 2; gap >= 1; gap /= 2) {
		for (scan = gap; scan < size; ++scan) {
			for (position = scan; position >= 0 && position + gap < size; position -= gap) {
				if (input[position + gap] < input[position]) swap(input, position + gap, position);
			}
		}
	}
}

Test(shellsort, simple_case) {
	int input[] = {2, 3, 4, 5, 6, 7, 8, 9, 1};
	int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	shellsort(input, 9);

	check_sorted(input, 9);
	cr_expect_arr_eq(input, expected, 9 * sizeof(int));
}

Test(shellsort, sample_case) {
	int input[10] = {2, 4, 5, 4, 1, 9, 3, 5, 3, 7};
	int expected[10] = {1, 2, 3, 3, 4, 4, 5, 5, 7, 9};

	shellsort(input, 10);

	check_sorted(input, 10);
	cr_expect_arr_eq(input, expected, 10 * sizeof(int));
}