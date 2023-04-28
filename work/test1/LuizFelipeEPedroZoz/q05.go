/**
 * @file q05.go
 * @author LUIZ FELIPE E PEDRO ZOZ
 * @brief QUESTÃO 5
 * @version 0.1
 * @date 2023-04-28
 */

package main

import (
	"fmt"
)

type Image struct {
	image [][]int
}

func (image *Image) moveVertically(y int) {
	if y > 0 {
		for i := 0; i < y; i++ {
			aux := image.image[0]
			for row := 0; row < len(image.image)-1; row++ {
				image.image[row] = image.image[row+1]
			}
			image.image[len(image.image)-1] = aux
		}
	} else if y < 0 {
		for i := 0; i > y; i-- {
			aux := image.image[len(image.image)-1]
			for row := len(image.image) - 1; row != 0; row-- {
				image.image[row] = image.image[row-1]
			}
			image.image[0] = aux
		}
	}
}

func (image *Image) moveHorizontally(x int) {
	if x < 0 {
		for i := 0; i > x; i-- {
			for row := 0; row < len(image.image); row++ {
				aux := image.image[row][0]
				for column := 0; column < len(image.image[0])-1; column++ {
					image.image[row][column] = image.image[row][column+1]
				}
				image.image[row][len(image.image[0])-1] = aux
			}
		}
	} else if x > 0 {
		for i := 0; i < x; i++ {
			for row := 0; row < len(image.image); row++ {
				aux := image.image[row][len(image.image[0])-1]
				for column := len(image.image[0]) - 1; column != 0; column-- {
					image.image[row][column] = image.image[row][column-1]
				}
				image.image[row][0] = aux
			}
		}
	}
}

var X, Y, N int
var times_vertical, times_horizontal int
var string_buffer string

func main() {
	fmt.Scanln(&X, &Y)
	for counter := 1; X != 0 && Y != 0; counter++ {
		image := [][]int{}
		for i := 0; i < X; i++ {
			image = append(image, []int{})
			for j := 0; j < Y; j++ {
				if j == Y-1 {
					fmt.Scanln(&N)
				} else {
					fmt.Scan(&N)
				}
				image[i] = append(image[i], N)
			}
		}
		myImage := Image{image: image}
		fmt.Scanln(&times_horizontal, &times_vertical)
		for !(times_horizontal == 0 && times_vertical == 0) {
			myImage.moveHorizontally(times_horizontal)
			myImage.moveVertically(times_vertical)
			fmt.Scanln(&times_horizontal, &times_vertical)
		}
		fmt.Println("Teste", counter)
		for i := 0; i < len(myImage.image); i++ {
			for j := 0; j < len(myImage.image[0]); j++ {
				fmt.Print(myImage.image[i][j])
				if j != len(myImage.image[0])-1 {
					fmt.Print(" ")
				} else {
					fmt.Print("\n")
				}
			}
		}
		fmt.Print("\n")
		fmt.Scanln(&X, &Y)
	}

}
