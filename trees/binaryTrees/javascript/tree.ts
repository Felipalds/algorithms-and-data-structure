
class TNode {

  left: TNode | null
  right: TNode | null
  data: number | null


  constructor(data: number){
    this.data = data
    this.left = null
    this.right = null
  }


  getData(){
    return this.data
  }

  getLeft(): TNode | null{
    return this.left
  }

  getRight(): TNode | null{
    return this.right
  }

  setLeft(node: TNode | null){
    this.left = node
  }
 
  setRight(node: TNode | null){
    this.right = node
  }
}

class Tree {

  root: TNode | null
  elementsAmount: number

  constructor(){
    this.root = null
    this.elementsAmount = 0
  }



  insert(data: number, root: TNode | null){
    if(root === null){
      root = new TNode(data)
      return root
    } else {
        const rootData = root.getData()
        if(rootData){
          if(data < rootData){
            root.setLeft(this.insert(data, root.getLeft()))
          }
        }

        return root
      }
    } 


  remove(){

  }
}
