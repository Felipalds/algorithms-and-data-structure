
/***********************************************************************
 * AvlTree.go: Implementação de uma árvore binária de busca balanceada * 
 * 				AVL em go                                               *
 ***********************************************************************/
package main

import(
   "fmt"
)

/***********************************************
 * Declaração do tipo de dado armazenado no nó *
 ***********************************************/
type DataType uint8

/**************************************
 * Declaração do nó de árvore binária *
 **************************************/
type BinTreeNode struct {
   data DataType 						// dado armazenado no nó
   left, right *BinTreeNode	// ponteiros para os filhos esquerdo e direito
}

/****************************************************
 * Declaração de nó de Lista simplesmente encadeada *
 ****************************************************/
type Node struct {
   data *BinTreeNode
   next *Node
}

/********************************************
 * Declaração dos métodos da classe ListaSE *
 ********************************************/
type ListaSE struct {
   len int8	// Número de elementos na lista
   left *Node	// ponteiro para o inicio da lista
   right *Node	// ponteiro para o final da lista
}

/******************************
 * Verificação de lista vazia *
 ******************************/
func (l *ListaSE) IsEmpty() bool {
   return l.len == 0
}

/*****************************************
 * Verifica se um dado é membro da lista *
 *****************************************/
func (l *ListaSE) Find(x *BinTreeNode) *Node {
   aux := l.left
   for (aux != nil) && aux.data == x {
      aux = aux.next
   }
   return aux
}

/******************************
 * Retorna o tamanho da lista *
 ******************************/
func (l *ListaSE) Length() int8 {
   return l.len
}

/*******************
 * Imprime a lista *
 *******************/
func (l *ListaSE) Print() {
   p := l.left
   fmt.Print("{")
   for p != nil {
      fmt.Printf("%v", p.data)
      if p.next != nil {
	 fmt.Print(", ")
      }
      p = p.next
   }
   fmt.Println("}")
}

/***********************
 * Inserção à esquerda *
 ***********************/
func (list *ListaSE) InsertLeft(x *BinTreeNode) {
   newNode := new(Node)
   if newNode == nil {
      panic("Não há memória suficiente para alocar um novo nó!")
   }
   newNode.data = x

   // Se a lista estiver vazia, o novo nó será o primeiro e o último nó.
   if list.left == nil {
      newNode.next = nil
      list.left = newNode
      list.right = newNode
   } else {
      // Se a lista não estiver vazia, adicione o novo nó ao início da lista.
      newNode.next = list.left
      list.left = newNode
   }
   // incrementar o contador de elementos na lista
   list.len++
}

/***********************
 * Inserção à direita  *
 ***********************/
func (list *ListaSE) InsertRight(x *BinTreeNode) {
   newNode := new(Node) // alocar memória para um novo nó
   if newNode == nil { // verifica se ocorreu erro de memória insuficiente
      panic("Não há memória suficiente para alocar um novo nó!")
   }
   // inicializar o valor e o próximo ponteiro do novo nó
   newNode.data = x
   newNode.next = nil

   // se a lista está vazia, o novo nó será a cabeça e a cauda da lista
   if list.left == nil {
      list.left = newNode
      list.right = newNode
   } else {
      // se a lista não está vazia, adicionar o novo nó no final da lista
      list.right.next = newNode
      list.right = newNode
   }
   // incrementar o contador de elementos na lista
   list.len++
}

/***********************
 * Remoção à esquerda  *
 ***********************/
func (l *ListaSE) RemoveLeft() *BinTreeNode {
   if l.left == nil {
      return nil
   }
   r := l.left.data
   l.left = l.left.next
   if l.left == nil {
      l.right = nil
   }
   l.len--
   return r
}

/***********************
 * Remoção à direita   *
 ***********************/
func (l *ListaSE) RemoveRight() *BinTreeNode {
   if l.right == nil {
      return nil
   }
   r := l.right.data
   if l.left == l.right {
      l.left = nil
      l.right = nil
   } else {
      aux := l.left
      for aux.next != l.right {
         aux = aux.next
      }
      aux.next = nil
      l.right = aux
   }
   l.len--
   return r
}

/*********************************************************
 * init(): Função de inicialização da classe BinTreeNode *
 *********************************************************/
func (btn *BinTreeNode)Init(l *BinTreeNode, d DataType, r *BinTreeNode) {
   btn.data = d
   btn.left = l
   btn.right = r
}

/**********************************************
 * GetData(): retorna o dado armazenado no nó *
 **********************************************/
func (btn *BinTreeNode)GetData()(data DataType) {
   return btn.data
}

/****************************************************
 * SetData(): seta o valor do dado armazenado no nó *
 ****************************************************/
func (btn *BinTreeNode)SetData(d DataType) {
   btn.data = d
}

/*************************************************************
 * GetLeft(): retorna o ponteiro para o filho esquerdo do nó *
 *************************************************************/
func (btn *BinTreeNode)GetLeft()(l *BinTreeNode) {
   return btn.left
}

/*************************************************************
 * GetRight(): retorna o ponteiro para o filho direito do nó *
 *************************************************************/
func (btn *BinTreeNode)GetRight()(r *BinTreeNode) {
   return btn.right
}

/******************************************************
 * SetLeft(): Seta o ponteiro do filho esquerdo do nó *
 ******************************************************/
func (btn *BinTreeNode)SetLeft(l *BinTreeNode) {
   btn.left = l
}

/******************************************************
 * SetRight(): Seta o ponteiro do filho direito do nó *
 ******************************************************/
func (btn *BinTreeNode)SetRight(r *BinTreeNode) {
   btn.right = r
}

/*************************************
 * Print(): Imprime o conteúdo do nó *
 *************************************/
func (btn *BinTreeNode)Print() {
   fmt.Print(btn.data)
}

/****************************************************************
 * Implementação da classe AVLTree: árvore binária de busca AVL *
 ****************************************************************/
type AVLTree struct {
   root *BinTreeNode
   numElements int8
}

/*******************************************
 * Init(): Inicialização da classe AVLTree *
 *******************************************/
func (avl *AVLTree) Init()  {
   avl.root = nil
   avl.numElements = 0
}

/******************************************************
 * GetRoot(): Retorna o endereço do nó raiz da árvore *
 ******************************************************/
func (avl *AVLTree) GetRoot() *BinTreeNode {
   return avl.root
}

/*************************************************************************
 * GetNumElements(): retorna o número de elementos armazenados na árvore *
 *************************************************************************/
func (avl *AVLTree) GetNumElements() int8 {
   return avl.numElements
}

/*************************************************
 * Height(x): Calcula a altura do nó de árvore x *
 *************************************************/
func (avl *AVLTree)Height(x *BinTreeNode) int8 {
   var h int8
   if (x == nil) {
      h = 0
   } else {
      a := avl.Height(x.GetLeft())
      b := avl.Height(x.GetRight())
      if a > b {
	 h = (1 + a)
      } else {
         h = (1 + b)
      }
   }
   return h
}

/*****************************************************************
 * GetBalanceFactor(x): Retorna o fator de balanceamento do nó x *
 *****************************************************************/
func (avl *AVLTree)GetBalanceFactor(r *BinTreeNode) int8 {
   if (r == nil) {
      return 0
   } else {
      hr := avl.Height(r.GetRight())
      hl := avl.Height(r.GetLeft())
      fb := hr - hl
      return fb
   }
}

/***************************************
 * Print(): Imprime a árvore formatada *
 ***************************************/
func (avl *AVLTree)Print(r *BinTreeNode, level int8) {
   if r == nil {
      return
   } else {
      avl.Print(r.GetRight(), level + 1) // varre primeiro o ramo direito
      for i := int8(0); i < level; i++ { // imprime as barrinhas pra formar a árvore 
	 if i < level -1 {
	    fmt.Print("-------|")
	 } else {
	    fmt.Print("-------|")
	 }
      }
      r.Print() 			// imprime o nó
      fmt.Printf("(%d)\n",avl.GetBalanceFactor(r))// imprime o fator de balanceamento do nó
      avl.Print(r.GetLeft(), level + 1) // varre o ramo esquerdo
   }
}

/***********************************************************************
 * RotateLeft(x): Implementa a rotação simples à esquerda sobre o nó x *
 ***********************************************************************/
func (avl *AVLTree) RotateLeft(r *BinTreeNode) *BinTreeNode {
   var temp, aux *BinTreeNode
   
   temp = r
   if temp == nil {
      return temp   
   } else {
      if temp.GetRight() == nil {
	 return temp
      } else {
	 aux = temp.GetRight()
         temp.SetRight(aux.GetLeft())
         aux.SetLeft(temp)
      }
      return aux
   }
} 
/***********************************************************************
 * RotateRight(x): Implementa a rotação simples à direita sobre o nó x *
 ***********************************************************************/
func (avl *AVLTree) RotateRight(r *BinTreeNode) (*BinTreeNode){
   var temp, aux *BinTreeNode
	
   temp = r
   if temp == nil {
      return temp
   } else {
      if temp.GetLeft() == nil {
         return temp
      } else {
         aux = temp.GetLeft()
         temp.SetLeft(aux.GetRight())
         aux.SetRight(temp)
      }
      return aux
   }
}

/******************************************************************************
 * RotateRightLeft(x): implementa a rotação dupla direita-esquerda sobre o nó *
 * 						  x                                                      *
 ******************************************************************************/
func (avl *AVLTree) RotateRightLeft(r *BinTreeNode) *BinTreeNode {
   var temp, auxL, auxR *BinTreeNode
        
   temp = r
   if temp == nil {
      return temp
   } else { 
      if temp.GetRight() == nil {
	 return temp
      } else {
	 auxR = temp.GetRight()
	 if auxR.GetLeft() == nil {
	    return temp
	 } else {
	    auxL = auxR.GetLeft()
	    auxR.SetLeft(auxL.GetRight())
	    temp.SetRight(auxL.GetLeft())
	    auxL.SetLeft(temp)
	    auxL.SetRight(auxR)
	 }
      }
   }
   return auxL
}

/******************************************************************************
 * RotateLeftRight(x): implementa a rotação dupla esquerda-direita sobre o nó *
 * 						  x                                                      *
 ******************************************************************************/
func (avl *AVLTree) RotateLeftRight(r *BinTreeNode) *BinTreeNode {
   var temp, auxL, auxR *BinTreeNode
	
   temp = r
   if temp == nil {
      return temp
   } else {
      if temp.GetLeft() == nil {
	 return temp
      } else {
	 auxL = temp.GetLeft()
	 if auxL.GetRight() == nil {
	    return temp
	 } else {
	    auxR = auxL.GetRight()
	    auxL.SetRight(auxR.GetLeft())
	    temp.SetLeft(auxR.GetRight())
	    auxR.SetRight(temp)
	    auxR.SetLeft(auxL)
	 }
      }
   }
   return auxR;
}

/*************************************************************************
 * InsertOrd(x, r): função recursiva auxiliar que insere o elemento x na *
 * 					  árvore enraizada em r                                *
 *************************************************************************/
func (avl *AVLTree) insertOrd(x DataType, r *BinTreeNode) *BinTreeNode {
   var temp, t1 *BinTreeNode
	
   temp = r
   if temp == nil {
      temp = new(BinTreeNode)
      if temp == nil {
	 panic("Erro: Memória insuficiente!\n")
      } else {
	 temp.Init(nil, x, nil)
	 avl.numElements++
      } 
   } else if (temp.GetData() < x) {
      temp.SetRight(avl.insertOrd(x, temp.GetRight()))
      t1 = temp.GetRight()
      if (avl.GetBalanceFactor(temp) > 1) {
	 if (t1.GetData() < x) {
	    temp = avl.RotateLeft(temp)
	 } else {
	    temp = avl.RotateRightLeft(temp)
	 } 
      } else {
	 return temp
      }
   } else if (temp.GetData() > x) {
      temp.SetLeft(avl.insertOrd(x, temp.GetLeft()))
      t1 = temp.GetLeft()
      if (avl.GetBalanceFactor(temp) < -1) {
	 if(t1.GetData() < x) {
	    temp = avl.RotateLeftRight(temp)
	 } else {
	    temp = avl.RotateRight(temp)
	 }
      } else {
	 return temp
      }
   } else {
      return temp
   }
   return temp
}

/******************************************************
 * Insert(x): Função que insere um elemento na árvore *
 ******************************************************/
func (avl *AVLTree) Insert(x DataType) {
   avl.root = avl.insertOrd(x, avl.root)
}

/*****************************************************************
 * organize(): Função que organiza a árvore após a remoção de um *
 * elemento. A função reorganiza o ramo da árvore que foi        *
 * afetado pela remoção. Esta função é chamada pela função       *
 * recursiva dtree que implementa o algoritmo de remoção por     *
 * cópia.                                                        *
 *****************************************************************/
func (avl *AVLTree) organize(r *BinTreeNode, x DataType) *BinTreeNode {
   temp := r	
   if temp != nil {
      temp.SetRight(avl.remNode(temp.GetRight(), x))
   }
   if temp.GetLeft() == nil {
      aux := temp.GetRight()
      temp = nil
      return aux
   } else {
      temp.SetLeft(avl.organize(temp.GetLeft(), x))
      if avl.GetBalanceFactor(temp) > 1 {
	 if avl.GetBalanceFactor(temp.GetRight()) == -1 {
	    temp = avl.RotateRightLeft(temp)
         } else {
	    temp = avl.RotateLeft(temp)
         }
      } else if avl.GetBalanceFactor(temp) < -1 {
         if avl.GetBalanceFactor(temp.GetRight()) == 1 {
	    temp = avl.RotateLeftRight(temp)
         }else{
	    temp = avl.RotateRight(temp)
         }
      }
      return temp
   }
}

/*********************************************************
 * Min() Método para obter o menor elemento de uma ávore *
 * (elemento mais a esquerda diferente de null)          *
 *********************************************************/
func (avl *AVLTree) min(r *BinTreeNode) *BinTreeNode {
   temp := r
   if temp == nil {
      return nil
   } else {
      for (temp.GetLeft() != nil) {
         temp = temp.GetLeft()
      }
      return temp
   }
}

/*************************************************************
 * dTree() Procedimento privado e recursivo para remover um  *
 * elemento da árvore. r é a raiz da árvore da qual o        *
 * elemento deve ser removido, x é o elemento a ser removido *
 * retorna a raiz da árvore sem o elemento removido          *
 *************************************************************/
func (avl *AVLTree) remNode(r *BinTreeNode, x DataType)*BinTreeNode {
   var t1 *BinTreeNode
        
   temp := r
   if temp == nil {
      return temp // árvore vazia ou elemento não foi encontrado
   } else { 
      if temp.GetData() == x { // achou o elemento. Remove-o
	 if temp.GetRight() == nil {
	    t1 = temp.GetLeft()
	    temp = nil
	    avl.numElements--
	    return t1
	 } else {
	    temp.SetData(avl.min(temp.GetRight()).GetData())
	    temp.SetRight(avl.organize(temp.GetRight(),  x))
	    avl.numElements--
	    if avl.GetBalanceFactor(temp) < -1 {
	       if avl.GetBalanceFactor(temp.GetLeft()) == 1 {
		  temp = avl.RotateLeftRight(temp)
	       } else {
		  temp = avl.RotateRight(temp)
	       }
	    }
	 }
      } else {
	 if temp.GetData() < x {
	    temp.SetRight(avl.remNode(temp.GetRight(), x))
	    // testa os fatores de balanceamento
	    if avl.GetBalanceFactor(temp) < -1 {
	       if avl.GetBalanceFactor(temp.GetLeft()) == 1 {
		  temp = avl.RotateLeftRight(temp)
	       } else {
		  temp = avl.RotateRight(temp);
	       }
	    } else {
	       return temp
	    }
	 } else {
	    temp.SetLeft(avl.remNode(temp.GetLeft(), x))
	    // testa os fatores de balanceamento
	    if avl.GetBalanceFactor(temp) > 1 {
	       if avl.GetBalanceFactor(temp.GetRight()) == -1 {
		  temp = avl.RotateRightLeft(temp)
	       } else {
		  temp = avl.RotateLeft(temp)
	       }
	    } else {
	       return temp
	    }
	 }
      }
   }
   return temp
}

/*************************************************************
 * Remove(): Procedimento para remover um elemento da árvore *
 *************************************************************/
func (avl *AVLTree) Delete(x DataType) {
   avl.root = avl.remNode(avl.root, x)
}

/****************************************************************************
 * Find(): retorna o endereço do elemento na árvore, se o mesmo estiver * 
 * na árvore, ou nil caso o elemento não esteja na árvore                   *
 ****************************************************************************/
 func (avl *AVLTree) Find(x DataType) *BinTreeNode {
   r := avl.root
   achou := false
   for (!achou) && (r != nil) {
      if r == nil {
	 return nil
      } else {
	 if r.GetData() == x { //achou
	    achou = true;
	 } else {
	    if r.GetData() > x { // busca na esquerda
	       r = r.GetLeft()
	    } else {
	       r = r.GetRight() // busca na direita
	    }
	 }
      }
   }
   return r
}

/**************************
 * Algoritmos de percurso *
 **************************/
 
/***********************************************************************
 * Algoritmo de visitação de nós utilizado pelos algoritmos iterativos *
 * R é o nó que está sendo visitado.                                   *
 * Este método é usado em todos os algoritmos de percurso              *
 ***********************************************************************/
func (avl *AVLTree) Visit(r *BinTreeNode) {
   // Implemente aqui o processo de visita ao nó.
   // Neste exemplo, a visita apenas imprime o conteúdo armazenado no nó.
   fmt.Print(r.GetData(), " ")
}

/*****************************************************************************
 * BreadthFirst(): Realiza um percurso em largura iterativo na árvore.       *
 * Utiliza uma fila para realizar este procedimento. Imprime os nós na ordem *
 * em que o percurso é realizado                                             *
 *****************************************************************************/
func (avl *AVLTree) BreadthFirst() {
   var (
      r *BinTreeNode = avl.root
      fila  ListaSE
   )
   
   if r != nil {
      fila.InsertRight(r)
      fmt.Print("{ ")
      for !fila.IsEmpty() {
	 r = fila.RemoveLeft()
         avl.Visit(r)
         if r.GetLeft() != nil {
	    fila.InsertRight(r.GetLeft())
         }
         if (r.GetRight() != nil) {
	    fila.InsertRight(r.GetRight())
         }
      }
      fmt.Print("}")
   }
   return
}

/****************************************
 * Percursos em profundidade iterativos *
 ****************************************/
 
/********************************
 * Percurso Pré-ordem iterativo *
 ********************************/
func (avl *AVLTree)ItPreOrder() {
   var pilha ListaSE
   
   r := avl.root
   if r != nil {
      pilha.InsertLeft(r)
      fmt.Print("{ ")
      for !pilha.IsEmpty() {
	 r = pilha.RemoveLeft()
	 avl.Visit(r)
         if (r.GetRight() != nil) {
	    pilha.InsertLeft(r.GetRight())
         }
         if (r.GetLeft() != nil) {
            pilha.InsertLeft(r.GetLeft())
         }
      }
      fmt.Print("}")
   }
   return
}

/*******************************
 * Percurso em-Ordem iterativo *
 *******************************/
func (avl *AVLTree) ItInOrder() {
   var pilha ListaSE
   
   r := avl.root
   fmt.Print("{ ")  
   for r != nil {
      for r != nil {
	 if (r.GetRight() != nil) {
	    pilha.InsertLeft(r.GetRight())
         }
         pilha.InsertLeft(r)
         r = r.GetLeft()
      }
      r = pilha.RemoveLeft()
      for !pilha.IsEmpty() && (r.GetRight() == nil) {
	 avl.Visit(r)
	 r = pilha.RemoveLeft()
      }
      avl.Visit(r)
      if !pilha.IsEmpty() {
	 r = pilha.RemoveLeft()
      } else {
	 r = nil
      }
   }
   fmt.Print("}")
   return
}

/********************************
 * Percurso Pós-Ordem Iterativo *
 ********************************/
func (avl *AVLTree) ItPostOrder() {
   var pilha ListaSE
		
   r := avl.root
   rAux := avl.root
   fmt.Print("{ ")
   for r != nil {
      for r.GetLeft() != nil {
	 pilha.InsertLeft(r)
         r = r.GetLeft()
      }
      for (r != nil) && ((r.GetRight() == nil) || (r.GetRight() == rAux)) {
	 avl.Visit(r)
         rAux = r
         if pilha.IsEmpty() {
	    fmt.Print("}")
	    return
         }
         r = pilha.RemoveLeft()
      }
      pilha.InsertLeft(r)
      r = r.GetRight()
   }
}

/*****************************************************
 * Algoritmos de percurso em profundidade recursivos *
 *****************************************************/
 
/*************
 * Pré-Ordem *
 *************/
 
// Função recursiva interna
func (bt *AVLTree) rPreOrd(r *BinTreeNode) {
   if (r == nil) {
      return
   } else {
      bt.Visit(r)
      bt.rPreOrd(r.GetLeft())
      bt.rPreOrd(r.GetRight())
   }
}

// Função que deve ser chamada
func (bt *AVLTree)RecPreOrder() {
   r := bt.root
   fmt.Print("{ ")
   bt.rPreOrd(r)
   fmt.Print("}")
}

/************
 * Em-ordem *
 ************/
 
// Função recursiva interna
func (avl *AVLTree) rInOrd(r *BinTreeNode) {
   if (r == nil) {
      return
   } else {
      avl.rInOrd(r.GetLeft())
      avl.Visit(r)
      avl.rInOrd(r.GetRight())
   }
}

// Função que deve ser chamada
func (avl *AVLTree)RecInOrder() {
   r := avl.root
   fmt.Print("{ ")
   avl.rInOrd(r)
   fmt.Print("}")
}

/*************
 * Pós-ordem *
 *************/

// Função recursiva interna
func (bt *AVLTree) rPosOrd(r *BinTreeNode) {
   if (r == nil) {
      return
   } else {
      bt.rPosOrd(r.GetLeft())
      bt.rPosOrd(r.GetRight())
      bt.Visit(r)
   }
}

// Função que deve ser chamada
func (bt *AVLTree)RecPostOrder() {
   r := bt.root
   fmt.Print("{ ")
   bt.rPosOrd(r)
   fmt.Print("}")
}


/**************************************
 * Clear(): Função para limpar a tela *
 **************************************/
func Clear(){
   fmt.Print("\033[H\033[2J") // escape codes para limpar a tela (Unix)
}

/****************************
 * main(): Função principal *
 ****************************/
func main() {
   // Declaração de variáveis
   var (
      op, x DataType
      avlTree AVLTree
   )

   for {
      // limpa a tela
      Clear()
      fmt.Println("ÁRVORES BINÁRIAS DE BUSCA AVL\n")
      fmt.Println("\t Menu Principal\n")
      fmt.Println("[ 0] Sair")
      fmt.Println("[ 1] Criar árvore")
      fmt.Println("[ 2] Imprimir árvore")
      fmt.Println("[ 3] Inserir elemento")
      fmt.Println("[ 4] Remover elemento")
      fmt.Println("[ 5] Procurar elemento")
      fmt.Println("[ 6] Percurso em largura iterativo")
      fmt.Println("[ 7] Percurso em profundide pré-ordem iterativo")
      fmt.Println("[ 8] Percurso em profundide em-ordem iterativo")
      fmt.Println("[ 9] Percurso em profundide Pós-ordem iterativo")
      fmt.Println("[10] Percurso em profundide Pré-ordem recursivo")
      fmt.Println("[11] Percurso em profundide em-ordem recursivo")
      fmt.Println("[12] Percurso em profundide Pós-ordem recursivo")
   
      fmt.Print("\nQual a sua opção? >> ")
      fmt.Scan(&op)
      switch op {
	 case 0: {
	    Clear()
	    fmt.Println("Programa Encerrado!\nTecle [ENTER]")
	    fmt.Scanln(&op)
	    return
	 }
	 case 1: {
	    Clear()
	    fmt.Println("Criando árvore...")
	    avlTree.Init()
	    fmt.Println("Árvore criada!\n Tecle [ENTER]")
	    fmt.Scanln()
	 }
	 case 2: {
	    Clear()
	    fmt.Println("Árvore armazenada:\n")
	    avlTree.Print(avlTree.root, 0)
	    fmt.Println("\nNúmero de elementos na árvore: ", avlTree.GetNumElements(), "\n")
	    fmt.Println("\nTecle [ENTER]")
	    fmt.Scanln()
	 }
	 case 3: {
	    Clear()
	    fmt.Println("Inserindo elemento\n")
	    fmt.Print("Número a inserir >> ")
	    fmt.Scanln(&x)
	    avlTree.Insert(x)
	    fmt.Println("Elemento inserido. Tecle [ENTER]")
	    fmt.Scanln()
	 }
	 case 4: {
	    Clear()
	    fmt.Println("Removendo elemento\n")
	    fmt.Print("Número a remover >> ")
	    fmt.Scanln(&x)
	    avlTree.Delete(x)
	    fmt.Println("Elemento removido. Tecle [ENTER]")
	    fmt.Scanln()
	 }
	 case 5: {
	    Clear()
	    fmt.Println("Procurar elemento\n")
	    fmt.Print("Número a procurar >> ")
	    fmt.Scanln(&x)
	    a := avlTree.Find(x)
	    if a == nil {
	       fmt.Println("Elemento não encontrado. Tecle [ENTER]")
	       fmt.Scanln()
	    } else {
		  fmt.Println(x, "está na árvore:", a)
		  fmt.Scanln()
	    }
	 }
	 case 6: {
	    Clear()
	    fmt.Println("Percurso em largura iterativo\n")
	    avlTree.BreadthFirst()
	    fmt.Println("\nTecle [ENTER]")
	    fmt.Scanln()
	 }
	 case 7: {
	    Clear()
	    fmt.Println("Percurso em profundidade Pré-Ordem iterativo\n")
	    avlTree.ItPreOrder()
	    fmt.Println("\nTecle [ENTER]")
	    fmt.Scanln()
	 }
	 case 8: {
	    Clear()
	    fmt.Println("Percurso em profundidade Em-Ordem iterativo\n")
	    avlTree.ItInOrder()
	    fmt.Println("\nTecle [ENTER]")
	    fmt.Scanln()
	 }
	 case 9: {
	    Clear()
	    fmt.Println("Percurso em profundidade Pós-Ordem iterativo\n")
	    avlTree.ItPostOrder()
	    fmt.Println("\nTecle [ENTER]")
	    fmt.Scanln()
	 }
	 case 10: {
	    Clear()
	    fmt.Println("Percurso em profundidade Pré-Ordem recursivo\n")
	    avlTree.RecPreOrder()
	    fmt.Println("\nTecle [ENTER]")
	    fmt.Scanln()
	 }
	 case 11: {
	    Clear()
	    fmt.Println("Percurso em profundidade Em-Ordem recursivo\n")
	    avlTree.RecInOrder()
	    fmt.Println("\nTecle [ENTER]")
	    fmt.Scanln()
	 }
	 case 12: {
	    Clear()
	    fmt.Println("Percurso em profundidade Pós-Ordem recursivo\n")
	    avlTree.RecPostOrder()
	    fmt.Println("\nTecle [ENTER]")
	    fmt.Scanln()
	 }
	 default: {
	    fmt.Println("Opção Inválida!\nTecle [ENTER]")
	    fmt.Scanln(&op)
	 }
      }
   }
}
