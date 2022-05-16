# trees
## binary trees
- estrutura de dados utilizada para armazenamento
- é um tipo de grafo (acíclico e conexo)
### Estrutura:
- idêntica à lista duplamente encadeada
- node : {
    - ponteiro para um filho esquerdo
    - info
    - ponteiro para um filho direito
}
- ligação não é mais lateral, mas sim hierárquica
- o primeiro nó é o nó raíz (root)
- a última linha hierárquica é chamada de folhas (filhos = NULL)
- os outros são nós internos (ramos) - incluindo o root
- cada filho possui um único pai (acíclico)
### aridade
- é o número <b>máximo</b> de filhos por nó
- aridade 2 = binária
- aridade 3 = ternária
- aridade n = n-ária - grafos
### Binary Search Trees
- os nós possuem uma ordenação intrínseca
- por exemplo: valores a esquerda são valores menores que do pai
- valores a direita são valores maiores que seu pai
### algoritmos
1. inserção:
{
    - começa pela raíz, sempre começa como nula
    // se começar pelo 2, terá somente lado direito?
    - a árvore depente da ordem de inserção
}
