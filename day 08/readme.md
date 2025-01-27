## What I Learned Today

Learned pseudocode of merged sort and tried translating it to code in python. 

Also currently using python to spend less time configuring the compiler and development environment. 

1. recursively sort 1st half of input array 
2. merge 2 sorted sublists into one

```
C = output array , length = n
A = 1st sorted array (n/2)
B = 2nd sorted array (n/2)
i , j = counter to traverse A and B

i = 1,
j = 1

for k = 1 to n
	if A(i) < B(j)
		C(k) = A(i)
		i++
	else ( B (j) < A(i) )
		(C(k) = B(j))
		j++

end
```

## Key Concepts

- Merged Sort
- Principles in Analysis

---

## Code Snippets

```python
def merge_sort(arr) -> list:
    n = len(arr)

    if n <= 1:
        return arr

    half_length = math.ceil(n / 2)
    left = merge_sort(arr[0:half_length])
    right = merge_sort(arr[half_length:])

    return merge(left, right)

def merge(left: list, right: list) -> list:
    result = []

    i = 0
    j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        elif right[j] <= left[i]:
            result.append(right[j])
            j += 1

    while i < len(left):
        result.append(left[i])
        i += 1
    while j < len(right):
        result.append(right[j])
        j += 1

    return result
```

## Challenges Experienced

While the pseudocode explained the base concept, I encountered a problem on the part where I needed to add the remaining integers. I had to look it up and found that I just had to add the following. 

```python
    while i < len(left):
        result.append(left[i])
        i += 1
    while j < len(right):
        result.append(right[j])
        j += 1
```

## Resources Used

https://www.coursera.org/learn/algorithmic-toolbox

https://medium.com/@mca.saboor/merge-sort-data-structure-and-algorithms-with-dart-58b3780710e6