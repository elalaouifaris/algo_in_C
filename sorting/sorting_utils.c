#include <stdio.h>
#include <criterion/criterion.h>

#include "sorting_utils.h"

void check_sorted(int *input, size_t size) {
	for (size_t idx = 0; idx < size - 1; ++idx) {
		cr_expect(input[idx] <= input[idx + 1], "Sorting broken between %zu and %zu", idx, idx + 1);
	}
}

void swap(int *input, size_t left, size_t right) {
	int temp = input[right];
	input[right] = input[left];
	input[left] = temp;
}