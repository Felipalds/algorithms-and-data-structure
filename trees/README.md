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

2. busca (recursivo): {

}

## Percursos / encaminhamentos em árvores
- ### Busca em largura (amplitude)
    - Busca realizada nível a nível da árvore, iniciando com o nível da raiz, depois indo para o nível de seus filhos, depois para o nível de seus netos, e assim sucessivamente.
    - Percurso em largura = (root, root-left, root-right, root-left-left, root-left-right, root-right-left, root-right-right, root-left-left-left, ...)
- ### Busca em profundidade
    - considere o comando raíz como alguma ação a ser tomada no root, como uma visita (printf por exemplo)
    1. #### Pré-ordem (recursivo)
        - Busca abrindo todas as possibilidades de cada nó
        - Indo o mais fundo possível em cada nó
        - Raíz -> pré-ordem(esquerda) -> pré-ordem(direita)
        - mais usada para percursos ou trajetos, não para valores
    2. #### Ordem
        - ordem(esquerda) -> raiz -> ordem(direita)
        - mais usada para valores, não para percursos
    3. #### Pós-ordem
        - pós-ordem(esquerda) -> pós-ordem(direita) -> raiz
