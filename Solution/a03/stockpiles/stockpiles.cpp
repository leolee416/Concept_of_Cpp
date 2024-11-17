#include "stockpiles.hpp"

namespace stockpiles {

// Helper function: Swap two Stockpile objects
void swap(Stockpile &a, Stockpile &b) noexcept {
    Stockpile temp = a;
    a = b;
    b = temp;
}

// Helper function: Adjust the element at index i to maintain the max-heap property
void heapify_down(Stockpile *stock_start, unsigned stock_len, unsigned i) {
    unsigned largest = i;
    unsigned left = 2 * i + 1;
    unsigned right = 2 * i + 2;

    // Left child
    if (left < stock_len) {
        if (*stock_start[left].bottles > *stock_start[largest].bottles ||
            (*stock_start[left].bottles == *stock_start[largest].bottles &&
             stock_start[left].id < stock_start[largest].id)) {
            largest = left;
        }
    }

    // Right child
    if (right < stock_len) {
        if (*stock_start[right].bottles > *stock_start[largest].bottles ||
            (*stock_start[right].bottles == *stock_start[largest].bottles &&
             stock_start[right].id < stock_start[largest].id)) {
            largest = right;
        }
    }

    // If largest is not i, swap and recursively adjust
    if (largest != i) {
        swap(stock_start[i], stock_start[largest]);
        heapify_down(stock_start, stock_len, largest);
    }
}

// Initialization function: Build the max-heap
void init(Stockpile *stock_start, unsigned stock_len) {
    // Build the heap starting from the last non-leaf node
    for (int i = stock_len / 2 - 1; i >= 0; --i) { heapify_down(stock_start, stock_len, i); }
}

// Serve request function
bool serve(Stockpile *stock_start, unsigned stock_len, unsigned amount, Stockpile &which) {
    if (stock_len == 0 || *stock_start[0].bottles < amount) {
        // No stockpiles or the root stockpile cannot satisfy the request
        return false;
    }

    // Extract the root as the stockpile to satisfy the request
    which = stock_start[0];
    *which.bottles -= amount; // Update the bottle count in the root stockpile

    // If the bottle count is reduced to 0, remove the stockpile
    if (*which.bottles == 0) {
        stock_start[0] = stock_start[stock_len - 1]; // Replace root with last element
        stock_len--; // Decrease heap size
    }

    // Adjust the heap
    heapify_down(stock_start, stock_len, 0);

    return true;
}

} // namespace stockpiles
