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

main() {
  print(quicksort([5, 6, 2, 1, 3, 9]));
  // print(quicksort([33, 55, 22, 900, 2000, 1]));
}
