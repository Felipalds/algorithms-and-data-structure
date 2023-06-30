package main

import (
	"fmt"
)

type Stack struct {
    first *Node
    last *Node
    length int
}

type Node struct {
    id int
    next *Node
    prev *Node
}


func (node *Node) setId (id int) {
    node.id = id
}

func (node *Node) setPrev (prev *Node){
    node.prev = prev
}

func (node *Node) setNext (next *Node){
    node.next = next
}

func (stack *Stack)Init(){
    stack.first = nil
    stack.last = nil
    stack.length = 0
}

func (stack *Stack) insertFirst (data int) {
    var newNode Node
    newNode.setId(data)
    newNode.setNext(nil) 
    newNode.setPrev(nil)
    stack.first = &newNode
    stack.last = &newNode
    stack.length++
}

func (stack *Stack) deleteStack() int {
    returnedData := stack.first.id
    stack.first = nil
    stack.last = nil
    stack.length = 0
    return returnedData
}

func (stack *Stack)Push(data int) {
    if stack.length == 0 {
        stack.insertFirst(data)
        return
    }
    var newNode Node
    newNode.setId(data)
    stack.last.setNext(&newNode)
    newNode.setPrev(stack.last)
    stack.last = &newNode
    stack.length++
}

func (stack *Stack) Pop () int {
    if stack.length == 0 {
        return -1
    }
    if stack.length == 1 {
        return stack.deleteStack()
    }
    returnedData := stack.last.id
    auxNode := stack.last.prev
    stack.last.prev.setNext(nil)
    stack.last = auxNode
    stack.length--
    return returnedData
}

func (stack *Stack)Print(){
    node := stack.first
    if stack.length == 0{
        fmt.Printf("[ ]\n")
    } else {
        fmt.Printf("[ ")
        for node.next != nil {
            fmt.Printf("%d -- ", node.id)
            node = node.next
        }
        fmt.Printf("%d ]\n", stack.last.id)
    }
}


func main () {
  
    var buyStack Stack
    var deathStack Stack
    var discardStack Stack

    var cardsAmount int
    var iterations int
    fmt.Scanf("%d", &cardsAmount)
    for i:= 0; i < cardsAmount; i++ {
        var newCard int
        fmt.Scanf("%d", &newCard)
        buyStack.Push(newCard)
    }
    currentCard := 1
    for deathStack.length < cardsAmount {
        for buyStack.length > 0 {
          auxNode := buyStack.last
          for auxNode != nil && auxNode.id != currentCard {
              auxNode = auxNode.prev
              removedCard := buyStack.Pop()
              discardStack.Push(removedCard)
          }
          findedCard := buyStack.Pop()
          deathStack.Push(findedCard)
        }
        for discardStack.length > 0 {
            replacedCard := discardStack.Pop()
            buyStack.Push(replacedCard)
        }
        currentCard++
        iterations++
    }
    fmt.Println(iterations)
}
