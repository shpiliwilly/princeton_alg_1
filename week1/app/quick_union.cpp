#include "quick_union.h"

QuickUnion::QuickUnion(unsigned size) {
    initArray(m_roots, size);
    initArray(m_sizes, size);
}

void QuickUnion::initArray(QuickUnion::IntArray& array, unsigned size) {
    array.reserve(size);
    for (unsigned i = 0; i < size; i++)
        array.push_back(i);
}

void QuickUnion::link(unsigned q, unsigned p) {

}

bool QuickUnion::connected(unsigned q, unsigned p) {
    return false;
}

unsigned QuickUnion::getRoot(unsigned p) const {
    return 0;

}

