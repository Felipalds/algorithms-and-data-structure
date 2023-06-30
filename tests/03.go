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

func (list *List)InsertRight(id int) {
    var newNode Node
    newNode.setId(id)
    newNode.setNext(nil)
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

func (list *List)InsertLeft(id int) {
    var newNode Node
    newNode.setId(id)
    if list.first == nil {
        newNode.setNext(nil)
        list.first = &newNode
        list.last = &newNode
        list.length++
    } else {
        newNode.next = list.first
        list.first = &newNode
        list.length ++

    }
}

func (list *List) DeleteLast () int {
    fmt.Println("HEREEEE")
    var returnedid int
    if list.first != nil {
      nodeAux := list.first
      if list.length == 1 {
        returnedid = nodeAux.id
        list.first = nil
        list.last = nil
        list.length--
      } else {
        for nodeAux.next.next != nil {
          nodeAux = nodeAux.next
        }
        returnedid = nodeAux.next.id
        list.last = nodeAux
        list.last.next = nil
        list.length--
      }
    } else {
      returnedid = -1
    }
    fmt.Println("AAA", returnedid)
    return returnedid
}

func (list *List) DeleteFirst () int {
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
      list.length --
      return returnedValue
    }
}

func (list *List) Insert (id int, pos int) {
    
    var newNode Node
    newNode.id = id

    if list.length == 0 {
        list.InsertRight(id)
    } else if pos >= list.length {
        list.InsertRight(id)
    } else if pos == 0 {
        list.InsertLeft(id)
    } else {
        auxNode := list.first
        iterator := 0
        for iterator < pos {
            auxNode = auxNode.next
            iterator++
        }
        newNode.next = auxNode.next
        auxNode.next = &newNode
        list.length ++
    }
}

func (list *List) Delete (pos int) int {

  if pos >= list.length - 1 {
      returnedId := list.DeleteLast()
      return returnedId
    }
    
    if pos == 0 {
      returnedId := list.DeleteFirst()
      return returnedId
    }

    if list.length == 1 {
        list.first = nil
        list.last = nil
        list.length --
        return -1
    }

    if pos > 0 && pos < list.length {
        iterator := 0
        auxNode := list.first
        for iterator < pos - 1{
          auxNode = auxNode.next
          iterator++
        }
        returnedId := auxNode.next.id
        auxNode.next = auxNode.next.next
        list.length --
        return returnedId
    }
    return -1
}

func (list *List) GetId(pos int) int{

    if pos >= list.length - 1 {
      return list.last.id
    }
    
    if pos == 0 {
      return list.first.id
    }

    if list.length == 1 { 
      return list.first.id
    }

    if pos > 0 && pos < list.length {
        iterator := 0
        auxNode := list.first
        for iterator < pos - 1{
          auxNode = auxNode.next
          iterator++
        }
        return auxNode.next.id
    }
    return -1
}

func (list *List) RemoveId (id int) {
    fmt.Println(id)
    pos := 0
    auxNode := list.first
    for auxNode.id != id {
        auxNode = auxNode.next
        pos++
    }
    fmt.Println(pos)
    list.Delete(pos)

}

func (list *List) DeleteDeaths(arrId []int){
    for k:= 0; k < len(arrId); k++ {
        list.RemoveId(arrId[k])
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
    participantsAmount = 1
    roundsAmount = 1
    test := 0

    for participantsAmount != 0 && roundsAmount != 0{
        myList.Init()
        fmt.Scanf("%d %d", &participantsAmount, &roundsAmount)
        for i := 0; i < participantsAmount; i++ {
            var currentId int
            fmt.Scanf("%d", &currentId)
            myList.InsertRight(currentId)
        }
        myList.Print()
        for j := 0; j < roundsAmount; j++ {
            var  deletedIds []int
            var participantsPlaying int
            var currentState int
            fmt.Scanf("%d %d", &participantsPlaying, &currentState)
            for k := 0; k < participantsPlaying; k++ {
                var playerState int
                fmt.Scanf("%d", &playerState)
                if playerState != currentState {
                    deletedIds = append(deletedIds, myList.GetId(k)) 
                }
            }
            myList.DeleteDeaths(deletedIds)
        }
        test ++
        fmt.Println("Teste ",test)
        fmt.Println(myList.first.id)

    } 
}
