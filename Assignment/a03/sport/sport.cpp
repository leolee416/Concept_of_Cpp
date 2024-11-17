#include "sport.hpp"

namespace sport {

// Helper function to compare two competitors based on points and times
bool is_better(const unsigned *points_a, const unsigned *times_a, const unsigned *points_b, const unsigned *times_b) {
    if (*points_a != *points_b) {
        return *points_a > *points_b; // Higher points are better
    }
    return *times_a < *times_b; // For equal points, shorter times are better
}

// Swap function marked as noexcept
void swap(const unsigned *&a, const unsigned *&b) noexcept {
    const unsigned *temp = a;
    a = b;
    b = temp;
}

void sort(const unsigned **points, const unsigned **times, unsigned len) {
    for (unsigned i = 0; i < len - 1; ++i) {
        unsigned best_index = i;
        for (unsigned j = i + 1; j < len; ++j) {
            if (is_better(points[j], times[j], points[best_index], times[best_index])) { best_index = j; }
        }
        // Swap pointers instead of data
        if (best_index != i) {
            swap(points[i], points[best_index]);
            swap(times[i], times[best_index]);
        }
    }
}

} // namespace sport