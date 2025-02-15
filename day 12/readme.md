## What I Learned Today

Q: Running time of a Quicksort

A: Depends on the quality of the Pivot

Q: if you quicksort on a sorted array using the first element as the pivot, what is the time complexity?

A: $\Theta(n^2)$  

Reason: Partitioning process would keep on iterating (right partition)

Q: Suppose we run QuickSort on some input, and, magically, every recursive call chooses the median element of its subarray as its pivot.  What's the running time in this case?

A:  $\Theta (n log n)$

### **Random Pivots**

**Quicksort Theory:** for every input array of length n, the average running time the quicksort with random pivots is O(n log n)

The average is over random choices made by the algorithm.

## Key Concepts

- Analysis of Quick sort algorithm, partitions
- importance of pivot

### Quick Links

---

## Code Snippets

```dart
// reimplementation of quicksort in Dart
List<int> quicksort(List<int> numbers) {
  if (numbers.length <= 1) return numbers;

  var pivot = numbers[0];

  List<int> left = [];
  List<int> right = [];

  for (var value in numbers.sublist(1)) {
    if (value <= pivot) {
      left.add(value);
    } else {
      right.add(value);
    }
  }

  left = quicksort(left);
  right = quicksort(right);

  List<int> result = [];
  result.addAll(left);
  result.add(pivot);
  result.addAll(right);

  return result;
}
```

```dart

```

## Challenges Experienced

## Resources Used

https://www.coursera.org/learn/algorithms-divide-conquer/lecture/QCLVL/choosing-a-good-pivot