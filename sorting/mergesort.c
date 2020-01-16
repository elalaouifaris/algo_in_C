#include <stdio.h>
#include <criterion/criterion.h>

#include "sorting_utils.h"

void mergesort(int *input, size_t size);
void _mergesort(int *input, size_t lower_bound, size_t upper_bound);
void __merge(int *input, size_t lower_bound, size_t middle, size_t upper_bound);

void mergesort(int *input, size_t size) {
	_mergesort(input, 0, size - 1);
}

void _mergesort(int *input, size_t lower_bound, size_t upper_bound) {
	if (lower_bound >= upper_bound) return;

	// lower + (upper - lower) / 2 equivalent to (upper + lower)/2
	// but it's more robust to overflow
	size_t middle = lower_bound + (upper_bound - lower_bound) / 2;

	_mergesort(input, lower_bound, middle);
	_mergesort(input, middle + 1, upper_bound);

	__merge(input, lower_bound, middle, upper_bound);
}

void __merge(int *input, size_t lower_bound, size_t middle, size_t upper_bound) {
	size_t lower_scan = lower_bound;
	size_t upper_scan = middle + 1;

	size_t temp_size = upper_bound - lower_bound + 1;
	size_t temp_scan = 0;
	int temp[temp_size];

	while (lower_scan <= middle && upper_scan <= upper_bound) {
		if (input[lower_scan] <= input[upper_scan]) {
			temp[temp_scan++] = input[lower_scan++];
		} else {
			temp[temp_scan++] = input[upper_scan++];
		}
	}

	while (lower_scan <= middle) {
		temp[temp_scan++] = input[lower_scan++];
	}

	while (upper_scan <= upper_bound) {
		temp[temp_scan++] = input[upper_scan++];
	}

	for (size_t i = 0; i < temp_size ; ++i) {
		input[lower_bound + i] = temp[i];
	}
}

Test(mergesort, simple_case) {
	int input[5] = {2, 4, 5, 4, 1};
	int expected[5] = {1, 2, 4, 4, 5};

	mergesort(input, 5);

	check_sorted(input, 5);
	cr_expect_arr_eq(input, expected, 5 * sizeof(int));
}

Test(mergesort, reversed_case) {
	int input[5] = {5, 4, 3, 2, 1};
	int expected[5] = {1, 2, 3, 4, 5};

	mergesort(input, 5);

	check_sorted(input, 5);
	cr_expect_arr_eq(input, expected, 5 * sizeof(int));
}
