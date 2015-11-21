#include <vector>
#include <iterator>
#include <algorithm>

namespace my {

    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    // insertion sort algorithm:
    // O(N^2) running time
    // not stable 
    // O(1) extra memory
    template <typename RandomAccessIterator>
    void insertion_sort(RandomAccessIterator first, RandomAccessIterator last) {
       if(first >= last)
           return;
       // maintain loop invariant - at each iteration all elements before 'current' iterator are sorted
       for(RandomAccessIterator current = first + 1; current != last; ++current) {
           RandomAccessIterator lastSorted = current - 1;
           // determine position where 'current' element must be inserted
           RandomAccessIterator insertPos = current;
           while(*(insertPos - 1) > *current && insertPos > first)
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

    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    // merge sort algorithm (recursive):
    // O(N * lgN) running time
    // stable 
    // O(N) extra memory

    template <typename T>
    using BufferType = std::vector<T>;

    template <typename RandomAccessIterator, typename ValueType>
    void merge(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last, BufferType<ValueType>& mergeBuff) {
        auto itLeft = first;
        auto itRight = middle;
        auto itMerged = mergeBuff.begin();
        for(auto i = 0; i < last - first; ++i) {
            if(itRight == last)
                *itMerged = *(itLeft++);
            else if(itLeft == middle)
                *itMerged = *(itRight++);
            else if(*itLeft <= *itRight)
                *itMerged = *(itLeft++);
            else 
                *itMerged = *(itRight++);
            ++itMerged;
        }
        std::copy(mergeBuff.begin(), itMerged, first);
    }

    template <typename RandomAccessIterator, typename ValueType>
    void sort_helper(RandomAccessIterator first, RandomAccessIterator last, BufferType<ValueType>& mergeBuff) {
        auto problemSize = std::distance(first, last);
        if(problemSize < 7) {
            insertion_sort(first, last);
            return;
        }
        RandomAccessIterator middle = first + problemSize / 2;
        sort_helper(first, middle, mergeBuff);
        sort_helper(middle, last, mergeBuff);
        merge(first, middle, last, mergeBuff);
    }

    template <typename RandomAccessIterator>
    void merge_sort_recursive(RandomAccessIterator first, RandomAccessIterator last) {
        if(first >= last)
            return;
        auto buffSize = last - first;
        // buffer we use to merge to sorted arrays
        BufferType<typename RandomAccessIterator::value_type> mergeBuff(buffSize);
        sort_helper(first, last, mergeBuff);
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    // quick sort algorithm
    // O(N * lgN) average running time, O(N^2) worst case
    // not stable 
    // O(1) extra memory
    
    template <typename RandomAccessIterator>
    void quick_sort(RandomAccessIterator first, RandomAccessIterator last) {



    }


#if 0

    template <typename RandomAccessIterator>
    void merge_sort_bottom_up(RandomAccessIterator first, RandomAccessIterator last) {

    }


    template <typename RandomAccessIterator>
    void quick_sort_3w(RandomAccessIterator first, RandomAccessIterator last);
#endif

}
