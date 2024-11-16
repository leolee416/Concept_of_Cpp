#include "disjoint_sets.hpp"
#include <stdexcept>

namespace disjoint_sets {

DisjointSets::DisjointSets(unsigned size) : parent(size), rank(size, 0) {
    for (unsigned i = 0; i < size; i++) {
        parent[i] = i; // initialize, every node's parents are themselves
    }
}

unsigned DisjointSets::add() {
    unsigned position = parent.size();
    parent.push_back(position);
    rank.push_back(0);
    return position;
}

unsigned DisjointSets::find(unsigned entry) {
    if (entry >= parent.size()) { throw std::out_of_range("Entry index is out of bounds"); }
    if (parent[entry] != entry) { parent[entry] = find(parent[entry]); }
    return parent[entry];
}

unsigned DisjointSets::unionSets(unsigned entry1, unsigned entry2) {
    if (entry1 >= parent.size() || entry2 >= parent.size()) { throw std::out_of_range("Entry index is out of bounds"); }
    unsigned root1 = find(entry1);
    unsigned root2 = find(entry2);

    if (root1 != root2) {
        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
            return root1;
        } else if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
            return root2;
        } else {
            parent[root2] = root1;
            ++rank[root1];
            return root1;
        }
    }
    return root1;
}

bool DisjointSets::disjoint(unsigned entry1, unsigned entry2) {
    if (entry1 >= parent.size() || entry2 >= parent.size()) { throw std::out_of_range("Entry index is out of bounds"); }
    return find(entry1) != find(entry2);
}

} // namespace disjoint_sets
