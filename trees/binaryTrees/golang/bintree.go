package main

import "fmt"

const CLEAR string = "\033[H\033[2J"

type DataType uint8

type BinTreeNode struct {
   data DataType // dado armazenado no nó
   left, right *BinTreeNode	// ponteiros para os filhos esquerdo e direito
}

func (btn *BinTreeNode)Init(l *BinTreeNode, d DataType, r *BinTreeNode) {
   btn.data = d
   btn.left = l
   btn.right = r
}

func (btn *BinTreeNode)GetData()(data DataType) {
   return btn.data
}

func (btn *BinTreeNode)SetData(d DataType) {
   btn.data = d
}

func (btn *BinTreeNode)GetLeft()(l *BinTreeNode) {
   return btn.left
}

func (btn *BinTreeNode)GetRight()(r *BinTreeNode) {
   return btn.right
}

func (btn *BinTreeNode)SetLeft(l *BinTreeNode) {
   btn.left = l
}

func (btn *BinTreeNode)SetRight(r *BinTreeNode) {
   btn.right = r
}

func (btn *BinTreeNode)Print() {
   fmt.Print(btn.data)
}

type BinTree struct {
   root *BinTreeNode
   numElements int8
}

func (bt *BinTree) Init()  {
   bt.root = nil
   bt.numElements = 0
}

func (bt *BinTree)Print(r *BinTreeNode, level int8) {
   if r == nil {
      return
   } else {
      bt.Print(r.GetRight(), level + 1)
      for i := int8(0); i < level; i++ {
	 	fmt.Print("------|")
      }
      r.Print() // imprime o nó
      fmt.Print("\n")
      bt.Print(r.GetLeft(), level + 1) 
   }
}

func (bt *BinTree)InsertNode(x DataType, root *BinTreeNode)(*BinTreeNode) {
   if root == nil { // nó nulo, tenta alocar um novo nó
      root = new(BinTreeNode)
      if root == nil {
	 	panic("Erro: Memória insuficiente!\n")
      } else {
	 	root.Init(nil, x, nil)  // novo nó inserido
	 	bt.numElements++			// incrementa número de elementos
	 	return root					// retorna o novo nó
      }
   } else { // nó não é nulo, verifica se tem que descer à esquerda ou à direita
      if x < root.GetData() {
	 	root.SetLeft(bt.InsertNode(x, root.GetLeft()))
      } else {
	 	root.SetRight(bt.InsertNode(x, root.GetRight()))
      }
      return root
   }
}

/******************************************
 * Insert(): Método de inserção na árvore *
 ******************************************/
func (bt *BinTree)Insert(x DataType) {
   bt.root = bt.InsertNode(x, bt.root)
}

/**************************************
 * Clear(): Função para limpar a tela *
 **************************************/
func Clear(){
   fmt.Print(CLEAR) // escape codes para limpar a tela (Unix)
}

/****************************
 * main(): Função principal *
 ****************************/
func main() {
	// Declaração de variáveis
	var (
    	 op DataType 
		 x DataType
    	 binTree BinTree
	)
	
	for {
    	Clear() // Limpa a tela
    	fmt.Println("ÁRVORES BINÁRIAS DE BUSCA")
    	fmt.Println("\t Menu Principal")
    	fmt.Println("[ 0] Sair")
    	fmt.Println("[ 1] Criar árvore")
    	fmt.Println("[ 2] Imprimir árvore")
    	fmt.Println("[ 3] Inserir elemento")
    	fmt.Println("[ 4] Remover elemento")
    	fmt.Println("[ 5] Procurar elemento")
      	fmt.Println("[ 6] Percurso em largura iterativo")
    	fmt.Println("[ 7] Percurso em profundidade pré-ordem iterativo")
    	fmt.Println("[ 8] Percurso em profundidade em-ordem iterativo")
    	fmt.Println("[ 9] Percurso em profundidade Pós-ordem iterativo")
    	fmt.Println("[10] Percurso em profundidade Pré-ordem recursivo")
    	fmt.Println("[11] Percurso em profundidade em-ordem recursivo")
    	fmt.Println("[12] Percurso em profundidade Pós-ordem recursivo")
    	fmt.Println("\nQual a sua opção? >> ")
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
	    		binTree.Init()
	    		fmt.Println("Árvore criada!\n Tecle [ENTER]")
	    		fmt.Scanln()
	 		}
			case 2: {
	    		Clear()
	    		fmt.Println("Árvore armazenada:")
	    		binTree.Print(binTree.root, 0)
	    		fmt.Println("\nNúmero de elementos na árvore: ", binTree.numElements)
	    		fmt.Println("\nTecle [ENTER]")
	    		fmt.Scanln()
	 		}
			case 3: {
	    		Clear()
	    		fmt.Println("Inserindo elemento")
	    		fmt.Print("Número a inserir >> ")
	    		fmt.Scanln(&x)
	    		binTree.Insert(x)
	    		fmt.Println("Elemento inserido. Tecle [ENTER]")
	    		fmt.Scanln()
	 		}
			default: {
	    		fmt.Println("Opção inválida!\nTecle [ENTER]")
	    		fmt.Scanln(&op)
	 		}
		}
	}
}
