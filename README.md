# README - Simulador de Caches

## Objetivo
Este projeto consiste na implementação de um simulador de caches parametrizável, permitindo a configuração do número de conjuntos, tamanho do bloco, nível de associatividade e política de substituição.

## Estrutura do Projeto
O simulador foi desenvolvido em uma linguagem de programação de livre escolha e recebe os parâmetros de configuração via linha de comando.

## Como Executar
Para executar o simulador, utilize o seguinte formato de linha de comando:
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

Se `flag_saida = 0`, a saída pode ser formatada livremente com textos explicativos. Se `flag_saida = 1`, a saída segue o formato:
```
<total_acessos>, <taxa_hit>, <taxa_miss>, <taxa_miss_compulsório>, <taxa_miss_capacidade>, <taxa_miss_conflito>
```

## Formato do Arquivo de Entrada
O arquivo de entrada contém os endereços de acesso à cache em formato binário (big endian, 32 bits cada endereço). Quatro arquivos de teste são fornecidos (`bin_100.bin`, `bin_1000.bin`, `bin_10000.bin` e `bin_186676.bin`), além de versões `.txt` para visualização dos valores.

## Compilação e Dependências
Se houver bibliotecas específicas necessárias para a compilação e execução, listar abaixo.

## Envio do Código
Os arquivos fonte e executáveis (se houver) devem ser compactados em um arquivo `.zip`, nomeado com a matrícula de um dos membros do grupo (exemplo: `12345678.zip`), e enviados via e-aula.

## Avaliação
A avaliação do projeto será dividida em duas etapas:
1. **Automatizada (Peso 5):** Identificação de similaridade entre códigos e execução de benchmarks.
2. **Apresentação (Peso 5):** Apresentação do código para o professor, onde cada membro deve responder corretamente sobre o funcionamento do simulador.

---
**Autores:**
- Nome 1 - Matrícula
- Nome 2 - Matrícula
