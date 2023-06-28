# Listas duplamente encadeadas
## List:
- first
- length
- last
## Node:
- info
- prev (ponteiro para o nó anterior)
- next
------
- agora podemos navegar em duas direções na lista
------
## Algoritmos
1. Inicialização
- exatamente igual à lista simplesmente encadeada
- garantir que não haverá lixo na lista
2. Desalocação
- varrer a lista
- desalocar nó por nó
- aux aponta p/ first
- first aponta para next do aux
- desaloca aux
3. Verificar se é NULL
4. Escrever a lista
- podemos printar do início pro fim e também de forma inversa, na mesma função, passando um parâmetro bool inverse.
5. Insert Left
- aux aponta para um TNode, alocado dinamicamente
- ```como limitar a memória para um script e testar erros de alocação?```
- prev é NULL
- next é o atual first
- prev do atual first aponta p/ aux
- first aponta p/ aux
- !caso particular! caso a lista esteja vazia, devemos mexer com o last
6. Insert Right
- aux aponta para um TNode alocado dinamicamente
- next é NULL
- prev aponta para last
- next do last aponta para aux
- !caso particular! caso a lista esteja vazia, devemos mexer com o first
- a = b = x significa que a e b recebem x

