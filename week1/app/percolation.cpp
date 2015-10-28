#include "percolation.h"

Percolation::Percolation(int N)
    : m_union(N * N)
    , m_N(N) {
}

unsigned Percolation::translate(int row, int col) {
    return (row - 1) * m_N + col - 1;
}

void Percolation::open(int i, int j) {

}

bool Percolation::isOpen(int i, int j) {

}

bool Percolation::isFull(int i, int j) {

}

bool Percolation::percolates() {

}

PercolationStats::PercolationStats(int N, int T) {

}

double PercolationStats::mean() {

}

double PercolationStats::stddev() {

}

double PercolationStats::confidenceLo() {

}

double PercolationStats::confidenceHi() {

}
