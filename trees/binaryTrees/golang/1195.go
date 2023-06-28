package main

import (
	"fmt"
)

type Node struct {
    left *Node
    right *Node
    data int
}

type Tree struct {
    root *Node
    elements int
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

func (node *Node) Insert (data int) *Node {
    var newNode Node
    newNode.data = data
    newNode.left = nil
    newNode.right = nil
    if node == nil {
        return &newNode
    }
    if data < node.data {
        node.left = node.left.Insert(data)
    }
    if data > node.data {
        node.right = node.right.Insert(data)
    }
    return node
}

func main(){
    
    var cases int
    fmt.Scanf("%d", &cases)
    for i := 0; i < cases; i++ {
        var elements int
        var tree Tree
        tree.root = nil
        fmt.Scanf("%d", &elements)
        for j := 0; j < elements; j++ {
            var value int
            fmt.Scanf("%d", &value)
            tree.root.Insert(value)
            fmt.Println(tree.root.data)
        }
        fmt.Println("AAAA")
        printPostfix(tree.root)
    }

}
