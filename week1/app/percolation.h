#include "quick_union.h"

class Percolation {
public:
    Percolation(int N);            // create N-by-N grid, with all sites blocked
    void open(int i, int j);       // open site (row i, column j) if it is not open already
    bool isOpen(int i, int j);     // is site (row i, column j) open?
    bool isFull(int i, int j);     // is site (row i, column j) full?
    bool percolates();             // does the system percolate?
private:
    QuickUnion m_union;
    unsigned translate(int row, int col);
    int m_N;
};

class PercolationStats {
public:
    PercolationStats(int N, int T);     // perform T independent experiments on an N-by-N grid
    double mean();                      // sample mean of percolation threshold
    double stddev();                    // sample standard deviation of percolation threshold
    double confidenceLo();              // low  endpoint of 95% confidence interval
    double confidenceHi();              // high endpoint of 95% confidence interval
};
