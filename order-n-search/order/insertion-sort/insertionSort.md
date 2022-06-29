# InsertionSort
- baseia-se no processo de ordenação de cartas de baralho
- dividido em duas partes, uma parte ordenada e outra parte ainda não ordenada
- na primeira parte, coloca-se o primeiro elemento
- a partir daí, seleciona-se o primeiro elemento da segunda parte e inserimos no local certo na parte já ordenada
- repete-se até não haver mais elementos na parte a ser ordenada
## Comparações
- <b>quadrático</b>
- depende do estado inicial da lista
- melhor caso: <i>C = n - 1</i> - linear
- pior caso: <i>C = 1/2(n² - n)</i> - tão ruim quando bolha e selection
- caso médio: <i>C = 1/4(n² - n)</i>

## Comportamento
- natural (bom para conjuntos quase ordenados)
- estável (não rearranja elementos com chaves iguais)
- desvantagens: o vetor precisa ser rearranjado a cada vez que um elemento é posto em sua posição correta