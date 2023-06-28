package main

import "fmt"


type Heap struct {
    vector []int
    length int
}

func (heap *Heap) getFather (i int) int {
    k := i%2
    if k == 0 {
        return int(i / 2) - 1
    } else {
        return int(i / 2)
    }
}

func (heap *Heap) Insert (number int) {

    if(heap.length == 0){
        heap.vector = append(heap.vector, number)
        heap.length++
        return
    }
    heap.vector = append(heap.vector, number)
    heap.length ++

    index := heap.length - 1

    fatherIndex := heap.getFather(index)
    fatherValue := heap.vector[fatherIndex]

    for number  > fatherValue {
        fmt.Println(fatherIndex)
        fatherValue = heap.vector[fatherIndex]
        heap.vector[index] = fatherValue
        heap.vector[fatherIndex] = number
        index = fatherIndex
        fatherIndex = heap.getFather(index)

        if index == 0 {
            break
        }
    }
}


func main () {
    var heap Heap
    heap.Insert(10)
    heap.Insert(7)
    heap.Insert(5)
    heap.Insert(4)
    heap.Insert(6)
    heap.Insert(8)
    heap.Insert(9)
    heap.Insert(15)
    fmt.Println(heap.vector)
}
