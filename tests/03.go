package main

import (
	"fmt"
)

type List struct {
    first *Node
    last *Node
    length int
}

type Node struct {
    id int
    // state int
    next *Node
}

// func (node *Node) setState (state int){
//     node.state = state
// }

func (node *Node) setId (id int) {
    node.id = id
}

func (node *Node) setNext (next *Node){
    node.next = next
}

func (list *List)Init(){
    list.first = nil
    list.last = nil
    list.length = 0
}

func (list *List)Push(id int) {
    var newNode Node
    newNode.setId(id)
    newNode.setNext(list.first)
    if list.first == nil {
        list.first = &newNode
        list.last = &newNode
        list.length ++
    } else {
        list.last.setNext(&newNode)
        list.last = &newNode
        list.length++
    }
}

func (list *List) Pop () int {
    var nodeAux Node
    
    if list.length == 0 {
      return -1
    }
      
    nodeAux = *list.first

    if list.length == 1 {
        list.first = nil
        list.last = nil
        list.length--
        return nodeAux.id
    } else {
      returnedValue := list.first.id
      list.first = nodeAux.next
      list.last.next = list.first
      list.length --
      return returnedValue
    }
}

func (list *List)Print(){
    node := list.first
    if list.length == 0{
        fmt.Printf("[ ]\n")
    } else {
        fmt.Printf("[ ")
        for node.next != nil {
            fmt.Printf("%d -- ", node.id)
            node = node.next
        }
        fmt.Printf("%d ]\n", list.last.id)
    }
}


func main () {

    var myList List

    var participantsAmount int
    var roundsAmount int
    test := 0

    for {
        myList.Init()
        fmt.Scanf("%d %d", &participantsAmount, &roundsAmount)
        if participantsAmount == 0 && roundsAmount == 0 {
           break
        }
        for i := 0; i < participantsAmount; i++ {
            var currentId int
            fmt.Scanf("%d", &currentId)
            myList.Push(currentId)
        }
        for j := 0; j < roundsAmount; j++ {
            var participantsPlaying int
            var currentState int
            fmt.Scanf("%d %d", &participantsPlaying, &currentState)
            for k := 0; k < participantsPlaying; k++ {
                var playerState int
                fmt.Scanf("%d", &playerState)
                if playerState != currentState {
                    myList.Pop()
                } else {
                    myList.first = myList.first.next
                    myList.last = myList.last.next
                }
            }
        }
        test ++
        fmt.Println("Teste ",test)
        fmt.Println(myList.first.id)
        fmt.Println()

    } 
}
