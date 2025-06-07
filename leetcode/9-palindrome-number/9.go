package main

import (
	"fmt"
	"strconv"
)

func isPalindrome(x int) bool {
	fmt.Println("Starting process for ", x)
	s := strconv.Itoa(x)
	l := len(s)

	if l == 0 || l == 1 || (l == 2 && (s[0] == s[1])) {
		return true
	}

	if l == 2 && (s[0] != s[1]) {
		return false
	}

	fmt.Println(s)
	middle := l / 2

	fmt.Println("Middle is: ", middle)

	que := []byte{}

	k := 0
	fmt.Println("Starting printing the que")
	for k < middle {
		que = append(que, s[k])
		k++
		fmt.Println(que)
	}

	k = middle
	if l%2 != 0 {
		k++
	}
	fmt.Println("Starting reading the queue")
	for k <= len(s)-1 {
		fmt.Printf("Comparing %c with %c\n", s[k], que[len(que)-1])
		if s[k] != que[len(que)-1] {
			return false
		}
		k++
		fmt.Println(que)
		que = que[:len(que)-1]
	}

	return true
}

func main() {
	fmt.Println("Here")
	fmt.Println(isPalindrome(101))
	fmt.Println(isPalindrome(1001))
	fmt.Println(isPalindrome(-101))
	fmt.Println(isPalindrome(-10))
}
