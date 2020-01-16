#include <stdio.h>
#include <criterion/criterion.h>

#include "sorting_utils.h"

void bubble_sort(int *input, size_t size);

void bubble_sort(int *input, size_t size) {
	bool still_swapping = true;

	while (still_swapping) {
		still_swapping = false;

		for (size_t idx = 0; idx < size - 1; ++idx) {
			if (input[idx] > input[idx + 1]) {
				still_swapping = true;
				swap(input, idx, idx + 1);
			}
		}
	}
}

Test(bubble_sort, already_soted) {
	int dummy[5] = {1, 2, 3, 4, 5};

	bubble_sort(dummy, 5);

	check_sorted(dummy, 5);
}

Test(bubble_sort, simple_case) {
	int input[5] = {2, 4, 5, 3, 6};

	bubble_sort(input, 5);

	check_sorted(input, 5);
}
