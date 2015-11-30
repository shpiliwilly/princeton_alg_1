#include <iostream>

#include <list>

#include "collinear.h"


using PointsList = std::list<my::Point>;

  template <typename ForwardIterator>
  void printRange(const char* prefix, ForwardIterator first, ForwardIterator last) {
      std::cout << prefix;
      while(first != last)
          std::cout << *(first++) << ", ";
      std::cout << std::endl;
  }


void testAlgorithm(const PointsList& points) {

    PointsList res;
    my::findCollinearBruteForce(points.begin(), points.end(), res.end());
    printRange("result: ", res.begin(), res.end());

}

int main() {

    std::list<my::Point> points;
#if 0
    points.push_back(my::Point(1, 1));
    points.push_back(my::Point(2, 2));
    points.push_back(my::Point(3, 3));
    points.push_back(my::Point(123, 324));
    points.push_back(my::Point(4, 4));
#endif

    points.push_back(my::Point(1, 1));
    points.push_back(my::Point(1, 2));
    points.push_back(my::Point(1, 3));
    points.push_back(my::Point(123, 324));
    points.push_back(my::Point(1, 4));

    testAlgorithm(points);


    return 0;
}
