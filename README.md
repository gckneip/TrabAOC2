# README - Simulador de Caches

## Objetivo
Este projeto consiste na implementação de um simulador de caches parametrizável, permitindo a configuração do número de conjuntos, tamanho do bloco, nível de associatividade e política de substituição.

## Estrutura do Projeto
O simulador foi desenvolvido em uma linguagem de programação de livre escolha e recebe os parâmetros de configuração via linha de comando.

## Como Executar
Para executar o simulador, primeiramente rode o makefile para compilar os arquivos do programa:
```sh
make
```
Em seguida utilize o seguinte formato de linha de comando:
```sh
cache_simulator <nsets> <bsize> <assoc> <substituição> <flag_saida> arquivo_de_entrada
```
Onde:
- `cache_simulator` - Nome do executável do simulador.
- `nsets` - Número de conjuntos na cache.
- `bsize` - Tamanho do bloco em bytes.
- `assoc` - Grau de associatividade.
- `substituição` - Política de substituição: `R` (Random), `F` (FIFO) ou `L` (LRU).
- `flag_saida` - Define o formato da saída (`0` para formato livre, `1` para formato padronizado).
- `arquivo_de_entrada` - Arquivo binário contendo os endereços de acesso à cache.

### Exemplo de Execução
```sh
cache_simulator 256 4 1 R 1 bin_100.bin
```
Saída esperada:
```
100 0.92 0.08 1.00 0.00 0.00
```

## Formato de Saída
A saída do simulador consiste em um relatório com estatísticas de desempenho:
- `Total de acessos`
- `Taxa de hit`
- `Taxa de miss`
- `Taxa de miss compulsório`
- `Taxa de miss de capacidade`
- `Taxa de miss de conflito`

Se `flag_saida = 0`, a saída será através de uma tabela no prompt: 
```
Métrica                      Valor               
--------------------------------------------
Total de acessos:             186676              
Total de Misses:              79226               
Hit Rate:                     0.575596            
Miss Rate:                    0.424404            
Compulsory Miss Rate:         0.000403908         
Capacity Miss Rate:           79194               
Conflict Miss Rate:           0  
```
Se `flag_saida = 1`, a saída segue o formato:
```
<total_acessos>, <taxa_hit>, <taxa_miss>, <taxa_miss_compulsório>, <taxa_miss_capacidade>, <taxa_miss_conflito>
```
---
**Autores:**
- Gustavo Cunha Kneip
- Antônio Araujo de Brum
