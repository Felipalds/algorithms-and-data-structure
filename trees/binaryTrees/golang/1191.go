package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type Node struct {
    left *Node
    right *Node
    data byte
}

func printPostfix(root *Node) {
    	if root == nil {
		      return 
	    }

	    printPostfix(root.left)
	    printPostfix(root.right)
      fmt.Printf("%c", root.data)
}

func findIndex(slice string, value byte) int {
    for i, v := range slice {
        if v == rune(value) {
            return i
        }
    }
    return -1
}

func convert(prefix string, infix string) *Node{
    if len(prefix) == 0 || len(infix) == 0 {
        return nil
    }

    rootValue := prefix[0]
    root := &Node{ data: rootValue }

    rootIndex := findIndex(infix, rootValue)
    root.left = convert(prefix[1:rootIndex+1], infix[:rootIndex])
    root.right = convert(prefix[rootIndex+1:], infix[rootIndex+1:])
    return root
}

func main(){
    scanner := bufio.NewScanner(os.Stdin)

    for scanner.Scan(){
      line := scanner.Text()
      trees := strings.Fields(line)
      prefix := trees[0]
      infix := trees[1]

      root := convert(prefix, infix)
      printPostfix(root)
    }


}
