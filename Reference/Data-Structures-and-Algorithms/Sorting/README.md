# Sorting
![Sorting](https://github.com/nandanabhishek/Data-Structure/blob/main/Sorting/sorting.jpg)

*Sorting refers to the operation of arranging data in some given order, such as increasing or decreasing with numerical data, or alphabetically with character data.*


# Types of sorting 
- **Internal sorting** - Sorts the data resides in the computer’s memory. 
    **Example - Selection sort, Bubble sort, Insertion sort, Merge sort, Quick sort, Heap sort, Bucker Sort, etc**
    
- **External Sorting** - Deals with sorting the data stored in files. External sorting is applied when there is large amount of data that cannot be stored in memory. 
    **Example- Multiway merging**


## Internal Sorting Methods –
- [Selection Sort](https://github.com/nandanabhishek/Data-Structure/tree/main/Sorting/Selection%20Sort/main.c)
- [Bubble Sort](https://github.com/nandanabhishek/Data-Structure/tree/main/Sorting/Bubble%20Sort/main.c)
- [Insertion Sort](https://github.com/nandanabhishek/Data-Structure/tree/main/Sorting/Insertion%20Sort/main.c)
- [Merge Sort](https://github.com/nandanabhishek/Data-Structure/blob/main/Sorting/Merge%20Sort/main.c)
- [Quick Sort](https://github.com/nandanabhishek/Data-Structures-and-Algorithms/blob/main/Sorting/Quick%20Sort/main.c)
- [Heap Sort]
- [Bucket Sort]


## SORTING-Terminology

- **In-place Sorting** - *Any sorting algorithm is called In-place sorting algorithm if it uses constant space for sorting the elements. It sorts the elements by changing the order of the elements within the given list.*

- **Stable Sorting** -*Any sorting algorithm is called stable sorting algorithm if two elements with equal keys appear in the same order in sorted output as they appear in the input array to be sorted.* 


# Complexity Analysis
| S No. | Algorithm | Worst Time | Average Time | Best Time | Space Complexity(Worst) | In-place | Stable |
| :--| :-- | :--: | :--: | :--: | :--: | :--: | :--: |
| 1. | Bubble Sort | O(n^2) | O(n^2) | O(n) | O(1) | Yes | Yes |
| 2. | Selection Sort | O(n^2) | O(n^2) | O(n^2) | O(1) | Yes | Yes |
| 3. | Insertion Sort | O(n^2) | O(n^2) | O(n) | O(1) | Yes | Yes |
| 4. | Merge Sort | O(n * log n ) | O(n * log n ) | O(n * log n ) | O(n) | | Yes |
| 5. | Quick Sort | O(n^2) | O(n * log n ) |  O(n * log n )   | O(n) || No |
| 6. | Bucket Sort  | O(n^2 * k) ) | O(n * k) |  | O(n * k) | | |
| 7. | Heap Sort  | O(n * log n) | O(n * log n) | O(n * log n) | O(1) || |
| 8. | Shell Sort  | O(n * (log n)^2 ) | |  | | ||



