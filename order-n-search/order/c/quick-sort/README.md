# Merge Sort

- Criado por Hoare, 1960 e publicado em 1962
- Algoritmo mais rápido da história, no limite matemático (com toda a demonstração)
- Baseado em Divide'n'Conquer
  - divide-se o conjunto em elementos menores, que são ordenados recursivamente, até chegar em um conjunto unitário
  - depois há a reordenação e recombinação final
- Melhoramento no método básico de ordenação por permutação (Bubble)

## Funcionamento
- Escolha de um elemento central, chamado pivô
- Elementos <= ao pivô, pivô, elementos >= pivô
- Todos os elementos devem ser ordenados
- Após a ordenação, chamamos recursivamente nas duas metades, definindo outros pivôs
- 