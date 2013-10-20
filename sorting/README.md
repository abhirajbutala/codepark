Selection Sort
==============
In a loop, select the next minimum element and put it in sorted order.

SelectionSort(A)
    For i = 1 to n do
    Sort[i] = Find-Minimum from A
    Delete-Minimum from A
    Return(Sort)


Selection sort performs n iterations, where the average iteration takes n/2
steps, for a total of O(n^2) time.


Heap Sort
=========
Heap Sort is actually selection sort with better priority queue implementation
like heap or a balanced binary tree. With this, the inner loop takes O(logn)
time and thus the total time becomes O(nlogn).


Insertion Sort
==============
The idea is to select an arbitary element from the unsorted set and insert it
into proper position in sorted set.

Insertion sort takes O(n^2) in the worst case, but performs considerably better
when the data is almost sorted because inner loop takes fewer iterations.

InsertionSort(A)
    A[0] = −∞
    for i = 2 to n do
        j = i
        while (A[j] < A[j − 1]) do
            swap(A[j],A[j − 1])
            j = j − 1


Note that faster sorting algorithms based on incremental insertion follow from
more efficient data structures. Insertion into a balanced search tree takes
O(log n) per operation, or a total of O(nlogn) to construct the tree. An in-order
traversal reads through the elements in sorted order to complete the job in
linear time.


Merge Sort
==========
Recursevely partition the data into two groups and sort the groups individually
and merge them back in sorted order. Merge Sort is divide and conquer approach.

Mergesort(A[1, n])
    Merge( MergeSort(A[1,n/2]), MergeSort(A[n/2 + 1, n]) )


In merge sort, the number of elements in a subproblem gets halved at each level.
Thus the number of times we can halve n until we get to 1 is lg2 n. Because the
recursion goes lg n levels deep, and a linear amount of work is done per level,
mergesort takes O(n log n) time in the worst case.

Mergesort is a great algorithm for sorting linked lists, because it does not
rely on random access to elements as does heapsort or quicksort. Its primary
disadvantage is the need for an auxilliary buffer when sorting arrays. It is
easy to merge two sorted linked lists without using any extra space, by just
rearranging the pointers. However, to merge two sorted arrays (or portions
of an array), we need use a third array to store the result of the merge to
avoid stepping on the component arrays.

There are clever alogorithms to do in-place merging. Kronrod's algorithm is
one such example.


Quick Sort
==========
Quick Sort does it by randomly selecting a pivot element and partitioning the
data into two groups, one of which contains all elements small than pivot
element, and the other one contains all elements greater than pivot element.
Thus two sub groups are formed, which can be recursively sorted indendently.

Benefits: In place, O(nlogn) average case.


The difficulty is that the height of the tree depends upon where the pivot
element ends up in each partition. If we get very lucky and happen to repeatedly
pick the median element as our pivot, the subproblems are always half the size
of the previous level. The height represents the number of times we can halve n
until we get down to 1, or at most lg2 n. This corresponds to the best case of
quicksort.

Now suppose we consistently get unlucky, and our pivot element always splits
the array as unequally as possible. This implies that the pivot element is always
the biggest or smallest element in the sub-array. After this pivot settles into its
position, we are left with one subproblem of size n − 1. We spent linear work and
reduced the size of our problem by one measly element, as shown in Figure 4.6(r).
It takes a tree of height n−1 to chop our array down to one element per level, for
a worst case time of Θ(n2).

The worst case for quicksort is worse than heapsort or mergesort.


Randomized Quick Sort
=====================
We can also do randomized quick sort, where there is an initial step of
randomizing the data in O(n) time. This will ensure that the pivot element
picked up in every iteration is random enough and the O(nlogn) performance is
achieved every time. Randomization is thus a powerful tool to improve algorithms
with bad worst case but good average-case complexity.

Examples where randomization is used:
    * Random sampling
    * Randomized hashing
    * Randomized search


Bucket Sort or Distribution Sort
================================
Distribute the data in different buckets and then sort the buckets individually
and finally append the sorted buckets to each other. For example, distribute words
according to their first letter in 26 different buckets.

Such kind of sorting works well only if the distribution of data is roughly uniform
accross buckets. If distribution is uneven, the performance is terrible.


Shell Sort
==========


Radix Sort
==========


Stable Sorting Algorithms
=========================
Stable sorting algorithms leave equal-key items in the same relative order as in
the original permutation.



Problems
========


1. Use the partitioning idea of quicksort to give an algorithm that finds the median
element of an array of n integers in expected O(n) time. (Hint: must you look at
both sides of the partition?)

2. Give an efficient algorithm to rearrange an array of n keys so that all the
negative keys precede all the nonnegative keys. Your algorithm must be in-place,
meaning you cannot allocate another array to temporarily hold the items. How fast
is your algorithm? Hint: Use Quick Sort partitioning technique

3. Implement an algorithm that takes an input array and returns only the unique
elements in it.

4. Design a stack that supports push, pop, and retrieving the minimum element
in constant time. Can you do this?


