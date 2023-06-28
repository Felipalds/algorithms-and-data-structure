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
    prev *Node
}

func (node *Node) setData (data int){
    node.data = data
}

func (node *Node) setPrev (prev *Node){
    node.prev = prev
}

func (node *Node) setNext (next *Node){
    node.next = next
}

func (list *List)Init(){
    list.first = nil
    list.last = nil
    list.length = 0
}

func (list *List) insertFirst (data int) {
    var newNode Node
    newNode.setData(data)
    newNode.setNext(nil) 
    newNode.setPrev(nil)
    list.first = &newNode
    list.last = &newNode
    list.length++
}

func (list *List)InsertRight(data int) {
    if list.length == 0 {
        list.insertFirst(data)
        return
    }
    var newNode Node
    newNode.setData(data)
    list.last.setNext(&newNode)
    newNode.setPrev(list.last)
    list.last = &newNode
    list.length++
}

func (list *List)InsertLeft(data int) {
    if list.length == 0 {
        list.insertFirst(data)
        return
    }
    var newNode Node
    newNode.setData(data)
    newNode.setNext(list.first)
    newNode.setPrev(nil)
    list.first.setPrev(&newNode)
    list.first = &newNode
    list.length++
}
func (list *List) deleteList() int {
    returnedData := list.first.data
    list.first = nil
    list.last = nil
    list.length = 0
    return returnedData
}
func (list *List) DeleteLast () int {
    if list.length == 0 {
        return -1
    }
    if list.length == 1 {
        return list.deleteList()
    }
    returnedData := list.last.data
    auxNode := list.last.prev
    list.last.prev.setNext(nil)
    list.last = auxNode
    list.length--
    return returnedData
}

func (list *List) DeleteFirst () int {
    if list.length == 0 {
        return -1
    }
    if list.length == 0 {
        return list.deleteList()
    }


}

func (list *List) Insert (data int, pos int) {
}

func (list *List) Delete (pos int) {
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
    // myList.DeleteFirst()
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
