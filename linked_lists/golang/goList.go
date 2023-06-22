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
    data int
    next *Node
}

func (node *Node) setData (data int){
    node.data = data
}

func (node *Node) setNext (next *Node){
    node.next = next
}

func (list *List)Init(){
    list.first = nil
    list.last = nil
    list.length = 0
}

func (list *List)InsertRight(data int) {
    var newNode Node
    newNode.setData(data)
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

func (list *List)InsertLeft(data int) {
    var newNode Node
    newNode.setData(data)
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
    var returnedData int
    if list.first != nil {
      nodeAux := list.first
      if list.length == 1 {
        returnedData = nodeAux.data
        list.first = nil
        list.last = nil
        list.length--
      } else {
        for nodeAux.next.next != nil {
          nodeAux = nodeAux.next
        }
        returnedData = nodeAux.next.data
        list.last = nodeAux
        list.last.next = nil
        list.length--
      }
    } else {
      returnedData = -1
    }
    return returnedData
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
        return nodeAux.data
    } else {
      returnedValue := list.first.data
      list.first = nodeAux.next
      list.length --
      return returnedValue
    }
}

func (list *List) Insert (data int, pos int) {
    
    var newNode Node
    newNode.data = data

    if list.length == 0 {
        list.InsertRight(data)
    } else if pos >= list.length {
        list.InsertRight(data)
    } else if pos == 0 {
        list.InsertLeft(data)
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

func (list *List) Delete (pos int) {

  if pos >= list.length - 1 {
      list.DeleteLast()
    }
    
    if pos == 0 {
      list.DeleteFirst()
      return
    }

    if list.length == 1 {
        list.first = nil
        list.last = nil
        list.length --
    }

    if pos > 0 && pos < list.length {
        iterator := 0
        auxNode := list.first
        for iterator < pos - 1{
          auxNode = auxNode.next
          iterator++
        }
        auxNode.next = auxNode.next.next
        list.length --
    }

}

func (list *List)Print(){
    node := list.first
    if list.length == 0{
        fmt.Printf("[ ]\n")
    } else {
        fmt.Printf("[ ")
        for node.next != nil {
            fmt.Printf("%d -- ", node.data)
            node = node.next
        }
        fmt.Printf("%d ]\n", list.last.data)
    }
}


func main () {

    var myList List
    myList.Init()
    var data int

    var option int
    option = 1

    for option != 0{

        fmt.Println("(1) Visualizar lista")
        fmt.Println("(2) Inserir item à direita")
        fmt.Println("(3) Inserir item à esquerda")
        fmt.Println("(4) Deletar último valor (pop)")
        fmt.Println("(5) Deletar primeiro valor (shift)")
        fmt.Println("(6) Inserir item em uma posição")
        fmt.Println("(7) Deletar item em uma posição")
        fmt.Println("(0) Sair")

        fmt.Scanf("%d", &option)

        if option == 1 {
            myList.Print()
        }
        if option == 2 {
            fmt.Scanf("%d", &data)
            myList.InsertRight(data)
        }
        if option == 3{
            fmt.Scanf("%d", &data)
            myList.InsertLeft(data)
        }
        if option == 4 {
            myList.DeleteLast()
        }
        if option == 5 {
            myList.DeleteFirst()
        }
        if option == 6 {
            var pos int
            fmt.Printf("NÚMERO A SER INSERIDO: ")
            fmt.Scanf("%d", &data)
            fmt.Print("POSIÇÃO: ")
            fmt.Scanf("%d", &pos)
            myList.Insert(data, pos)
        }
        if option == 7 {
          var pos int

            fmt.Print("POSIÇÃO: ")
            fmt.Scanf("%d", &pos)
            myList.Delete(pos)
        }
        if option == 0 {
            break
        }

    }
}
