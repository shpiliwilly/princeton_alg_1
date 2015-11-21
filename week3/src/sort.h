#include <iterator>


namespace my {

    template <typename RandomAccessIterator>
    void insertion_sort(RandomAccessIterator first, RandomAccessIterator last) {
       if(first >= last)
           return;
       // maintain loop invariant - at each iteration all elements before 'current' iterator are sorted
       for(RandomAccessIterator current = first + 1; current != last; ++current) {
           RandomAccessIterator lastSorted = current - 1;
           // determine position where 'current' element must be inserted
           RandomAccessIterator insertPos = current;
           while(*(insertPos - 1) > *current)
               --insertPos;
           // make room for element to be inserted
           typename RandomAccessIterator::value_type tmpVal = *current;
           for(RandomAccessIterator mv = current; mv >= insertPos; --mv) {
               *mv = *(mv - 1);
           }
           // insert element
           *insertPos = tmpVal;
       }
    }

#if 0
    template <typename RandomAccessIterator>
    void merge_sort(RandomAccessIterator first, RandomAccessIterator last);

    template <typename RandomAccessIterator>
    void quick_sort(RandomAccessIterator first, RandomAccessIterator last);

    template <typename RandomAccessIterator>
    void quick_sort_3w(RandomAccessIterator first, RandomAccessIterator last);
#endif

}
