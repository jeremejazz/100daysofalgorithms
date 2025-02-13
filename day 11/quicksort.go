package main

import "fmt"

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

func main() {

	numbers := [6]int{5, 6, 2, 1, 3, 9}
	fmt.Println(QuicksortInt(numbers[:]))

	numbers2 := [6]int{33, 55, 22, 900, 2000, 1}
	fmt.Println(QuicksortInt(numbers2[:]))

}
