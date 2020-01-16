#include <stdio.h>
#include <criterion/criterion.h>

#include "sorting_utils.h"

void insertion_sort(int *input, size_t size);

void insertion_sort(int *input, size_t size) {
	int temp;
	size_t unsorted_start;
	size_t scan_sorted;

	for (unsorted_start = 1; unsorted_start < size; ++unsorted_start) {
		temp = input[unsorted_start];
		scan_sorted = unsorted_start;
		while (scan_sorted > 0 && temp < input[scan_sorted - 1]) {
			input[scan_sorted] = input[scan_sorted - 1];
			scan_sorted--;
		}
		input[scan_sorted] = temp;
	}
}

Test(insertion_sort, simple_case) {
	int input[5] = {2, 4, 5, 4, 1};
	int expected[5] = {1, 2, 4, 4, 5};

	insertion_sort(input, 5);

	check_sorted(input, 5);
	cr_expect_arr_eq(input, expected, 5 * sizeof(int));
}
