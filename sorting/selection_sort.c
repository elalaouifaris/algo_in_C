#include <stdio.h>
#include <criterion/criterion.h>

#include "sorting_utils.h"

void selection_sort(int *input, size_t size);

void selection_sort(int *input, size_t size) {
	size_t current;
	size_t scan;
	size_t min_index;
	int min_value;

	for (current = 0; current < size; ++current) {
		min_index = current;
		min_value = input[min_index];
		for (scan = current; scan < size; ++scan) {
			if (input[scan] < min_value) {
				min_index = scan;
				min_value = input[min_index];
			}
		}
		input[min_index] = input[current];
		input[current] = min_value;
	}
}

Test(selection_sort, simple_case) {
	int input[5] = {2, 4, 5, 4, 1};
	int expected[5] = {1, 2, 4, 4, 5};

	selection_sort(input, 5);

	check_sorted(input, 5);
	cr_expect_arr_eq(input, expected, 5 * sizeof(int));
}
