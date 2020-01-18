#include <stdio.h>
#include <criterion/criterion.h>

#include "sorting_utils.h"

void quicksort(int *input, size_t size);
void quicksort_helper(int *input, size_t lower_bound, size_t upper_bound);
size_t partition(int *input, size_t lower_bound, size_t upper_bound);

void quicksort(int *input, size_t size) {
	if (size == 0) return;
	quicksort_helper(input, 0, size - 1);
}

void quicksort_helper(int *input, size_t lower_bound, size_t upper_bound) {
	if (upper_bound <= lower_bound) {
		return;
	}

	size_t pivot_location = partition(input, lower_bound, upper_bound);
	quicksort_helper(input, lower_bound, pivot_location - 1);
	quicksort_helper(input, pivot_location + 1, upper_bound);
}

size_t partition(int *input, size_t lower_bound, size_t upper_bound) {
	int pivot = input[lower_bound];
	size_t start = lower_bound + 1;
	size_t end = upper_bound;

	while (start <= end) {

		while (input[start] <= pivot) {
			start++;
		}
		while (input[end] > pivot) {
			end--;
		}

		if (start < end) {
			swap(input, start, end);
		}
	}

	swap(input, lower_bound, end);
	return end;
}

Test(quicksort, simple_case) {
	int input[5] = {2, 4, 5, 4, 1};
	int expected[5] = {1, 2, 4, 4, 5};

	quicksort(input, 5);

	check_sorted(input, 5);
	cr_expect_arr_eq(input, expected, 5 * sizeof(int));
}

Test(quicksort, edge_case_zero_length) {
	int input[] = {};
	int expected[] = {};

	quicksort(input, 0);
}
