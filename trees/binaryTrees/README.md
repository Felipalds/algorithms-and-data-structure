# Binary Search Tree

Elementos à esquerda são menores.

Elementos à direita são maiores.

Tendência em ficar desorganizada.

Tendência em virar lista - há algoritmos que resolvem isso!

### Inserção

- Maior a esquerda
- menor a direita

### Remoção

- Fusão (tiramos um dos ramos e promovemos e o outro, penduramos novamente). Causa um grande problema de desbalanceamento.
- Cópia (copiamos o sucessor, mais a esquerda da direita ou o predecessor, mais a direita da esquerda,  da raíz e colocamos lá! Simples assim. Caso ele não tenha filhos no lugar certo, apenas um pendurado no outro lado, tiramos ele assim mesmo e subimos o filho errado.)

### Percurso

Largura (breathfirst)

- Pegamos todos os itens que estão no mesmo nível

Profundidade (depth first)

Pré ordem

1. Visitar nó
2. Recursão à esquerda do nó
3. Recursão à direita do nó

Em Ordem

1. Recursão à esquerda do nó
2. Visitar nó
3. Recursão à direita do nó

Pós ordem

1. Recursão à esquerda do nó
2. Recursão à direita do nó
3. Visitar nó
