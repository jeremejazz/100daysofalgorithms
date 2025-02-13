
# Day 11


# The Quicksort Algorithm

- the “greatest hit” algorithm
- $O(n log n)$ on averate

## Key Concepts

- Basic steps
    - choose a pivot element
    - move all values lower than pivot to the left partition
    - move higher values to the right partition
    - apply recursion to repeat steps

### Quick Links

---

https://www.coursera.org/learn/algorithms-divide-conquer/lecture/xUd8B/partitioning-around-a-pivot

## Code Snippets

```go
func QuicksortInt(numbers []int) []int {
	if len(numbers) <= 1 {
		return numbers
	}

	pivot := numbers[0]

	left := []int{}
	right := []int{}

	for _, value := range numbers[1:] {
		if value <= pivot {
			left = append(left, value)
		} else {
			right = append(right, value)
		}
	}

	left = QuicksortInt(left)
	right = QuicksortInt(right)

	return append(append(left, pivot), right...)

}
```

## Challenges Experienced

setting up the go debugger

## Resources Used

https://www.coursera.org/learn/algorithms-divide-conquer/lecture/xUd8B/partitioning-around-a-pivot