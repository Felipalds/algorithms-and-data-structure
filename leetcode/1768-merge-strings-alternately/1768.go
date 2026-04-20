package main

import "fmt"

func main() {

	fmt.Println(mergeAlternately("abc", "defghi"))

}

func mergeAlternately(word1, word2 string) string {

	w1, w2 := len(word1), len(word2)
	n := w1 + w2
	newWord := make([]byte, 0, n)

	for i := 0; i < w1 || i < w2; i++ {
		if i < w1 {
			newWord = append(newWord, word1[i])
		}
		if i < w2 {
			newWord = append(newWord, word2[i])
		}
	}

	return string(newWord)

}
