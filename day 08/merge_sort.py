import math


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


if __name__ == "__main__":
    
    output = merge_sort([6, 5, 12, 10, 9, 1])
    print(output)
