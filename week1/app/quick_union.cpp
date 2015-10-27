#include "quick_union.h"

QuickUnion::QuickUnion(unsigned size) {
    m_roots.reserve(size);
    for (unsigned i = 0; i < size; i++)
        m_roots.push_back(i);
    m_roots.resize(size, 0);
}

void QuickUnion::link(unsigned q, unsigned p) {
    unsigned root_p = getRoot(p);
    unsigned root_q = getRoot(q);
    if(m_sizes[root_q] > m_sizes[root_p]) {
        m_roots[root_p] = root_q;
        m_sizes[root_q] += m_sizes[root_p];
    } else {
        m_roots[root_q] = root_p;
        m_sizes[root_p] += m_sizes[root_q];
    }
}

bool QuickUnion::connected(unsigned q, unsigned p) {
    return getRoot(q) == getRoot(p);
}

unsigned QuickUnion::getRoot(unsigned p) const {
    while(m_roots[p] != p) {
        p = m_roots[p];
    }
    return p;
}
