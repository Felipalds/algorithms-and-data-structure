# SelectionSort
- ordenação por seleção
- seleciona o elemento de menor valor e troca-o pelo primeiro elemento
- para os <i>n-1</i> elementos restantes, encontra o segundo menor elemento e troca-o pelo segundo elemento, e assim por diante.
## Análise
- <b>quadrático</b>
- curva mais achatada
- laço externo: <i>n-1</i> vezes
- laço interno: <i>1/2(n)</i> vezes
## Comparações:
- continua o mesmo
- <i>C = 1/2(n² - n)</i>
## Trocas:
- <b>linear</b>
- Melhor caso: <i>T = 3(n - 1)</i>
- Pior caso: <i>T = n²/4 + 3(n - 1)</i>
- Caso médio: T = n(log(n + y)), onde y = 0,57721, constante de Euler M.
