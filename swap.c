#include <stdlib.h>

// swap functions that swaps two values without a temporary variable
void swap(void** a, void** b) {
  *a = (void*) ((size_t)*a ^ (size_t)*b);
  *b = (void*) ((size_t)*a ^ (size_t)*b);
  *a = (void*) ((size_t)*a ^ (size_t)*b);
}