package main

import (
	"fmt"
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
    var testAmount int
    fmt.Scanf("%d", &testAmount)
    for i:=0 ; i < testAmount; i++ {
      var stringSize int
      var prefix string
      var infix string
      fmt.Scanf("%d %s %s", &stringSize, &prefix, &infix)
      root := convert(prefix, infix)
      printPostfix(root)
      fmt.Print("\n")
    }


}
