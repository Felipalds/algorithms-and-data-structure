/**
 * @file q04.go
 * @author LUIZ FELIPE E PEDRO ZOZ
 * @brief QUESTÃO 4
 * @version 0.1
 * @date 2023-04-28
 */

package main

import "fmt"

var jogadas int
var jogador_um, jogador_dois string
var jogada_um, jogada_dois int

func main() {
	fmt.Scanln(&jogadas)
	fmt.Scanln(&jogador_um)
	fmt.Scanln(&jogador_dois)
	for counter := 1; jogadas != 0; counter++ {
		fmt.Println("Teste", counter)
		for i := 0; i < jogadas; i++ {
			fmt.Scanln(&jogada_um, &jogada_dois)
			if (jogada_um+jogada_dois)%2 == 0 {
				fmt.Println(jogador_um)
			} else {
				fmt.Println(jogador_dois)
			}
		}
		fmt.Print("\n")
		fmt.Scanln(&jogadas)
		if jogadas == 0 {
			break
		}
		fmt.Scanln(&jogador_um)
		fmt.Scanln(&jogador_dois)
	}
}
