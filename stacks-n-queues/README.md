# Pilhas e filas
- são <b>políticas de acesso</b> impostas à certas estruturas de dados
## Implementação:
-  Vetores:
    - estáticos
    - dinâmicos
- Listas:
    - simplesmente encadeadas
    - duplamente encadeadas
- Atenção:
    - não podemos remover nem inserir elementos pelo meio, isso causará a destruição da pilha ou da fila!
## Pilhas (stacks)
- Operações:
    1. Push (inserir na pilha)
    2. Pop (remover da pilha)
- São estuturas do tipo LIFO (last in, first out)
- Semelhante a uma pilha de pratos, o primeiro que entra é o último a sair, e o último que entra, é o primeiro a sair
- Inserção é sempre no final, remoção sempre no final
- Usos:
    - compilador (parênteses e chaves)
## Filas (queue)
- Operações:
    1. Enqueue (inserir na fila) - enfileirar
    2. Dequeue (remover da fila) - desenfileirar
- São estruturas do tipo FIFO (first in, first out)
- Semelhante à uma fila de banco (primeiro que entra é o primeiro que sai)
- Inserção é sempre no final, e remoção é sempre no começo
- Usos:
    - Procedimentos no processador (S.O.)