#include <list>
#include <iostream>

namespace my {


    // point on the plane
    struct Point {
        Point(int x, int y)
            : m_x(x)
            , m_y(y)
        { }
        int m_x;
        int m_y;
    };


    // segment - pair of points
    struct Segment {
        Point m_p1;
        Point m_p2;
    };

    std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << p.m_x << ", " << p.m_y;
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Segment& seg) {
        os << "(" << seg.m_p1 << "), (" << seg.m_p2 << ")";
        return os;
    }

    ////////////////////////////////////////////////////////////////////////

    // returns slope of the line defined by two given points
    double getSlope(const Point& p1, const Point& p2) {
        return (double)(p1.m_x - p2.m_x) / (p1.m_y - p2.m_y);
    }

    // finds all collinear points
    template<typename ForwardIterator, typename OutputIterator>
    void findCollinearBruteForce(ForwardIterator first, ForwardIterator last, OutputIterator result) {
        for(ForwardIterator it0 = first; it0 != last; ++it0) {

            ForwardIterator it1 = it0;
            while(++it1 != last) {

                ForwardIterator it2 = it1;
                while(++it2 != last) {

                    ForwardIterator it3 = it2;
                    while(++it3 != last) {

                        std::cout << "p0 = " << *it0 << std::endl;
                        std::cout << "p1 = " << *it1 << std::endl;
                        std::cout << "p2 = " << *it2 << std::endl;
                        std::cout << "p3 = " << *it3 << std::endl;

                        double slp1 = getSlope(*it0, *it1);
                        double slp2 = getSlope(*it0, *it2);
                        double slp3 = getSlope(*it0, *it3);
                        std::cout << "slp1 = " << slp1 << std::endl;
                        std::cout << "slp2 = " << slp2 << std::endl;
                        std::cout << "slp3 = " << slp3 << std::endl;
                        if(slp1 == slp2 && slp2 == slp3) {
                            // found 4 points with same slope => they are on the same line
                            std::cout << "found 4 points with same slope = " << slp1 << " : "
                                << *it0 << ", "
                                << *it1 << ", "
                                << *it2 << ", "
                                << *it3
                                << std::endl;
                            //*result =
                        }
                        std::cout << "==========================" << std::endl;
                    }
                }
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////

    // finds all collinear points
    template<typename ForwardIterator, typename OutputIterator>
    void findCollinearFast(ForwardIterator first, ForwardIterator last, OutputIterator result) {


    }

}
