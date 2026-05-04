Sistema de Gerenciamento de Estacionamento Rotativo

**Nome:** CHRYSTOPHER GREGORY LUZ COSTA

**Matrícula:** 20250052871

Este é um sistema simples desenvolvido em C para calcular o custo de estacionamento rotativo baseado em tipo de veículo e tempo de permanência.

## Descrição do Problema
O sistema calcula o valor a pagar por um veículo em um estacionamento rotativo, considerando o tipo de veículo, tempo de permanência e regras especiais como desconto para longas estadias e multa para excessos.

## Parte 1 – Modelagem

### 1. Análise do Problema
#### Como funciona um estacionamento rotativo na vida real
Um estacionamento rotativo é um sistema onde os veículos pagam por tempo limitado de uso do espaço. O motorista registra a entrada, estaciona por um período, e ao sair paga baseado no tempo decorrido. Em sistemas reais, isso é automatizado com sensores, cartões ou aplicativos móveis, mas aqui simulamos o cálculo manual do custo.

#### Quais decisões o sistema precisa tomar
- Validar o tipo de veículo informado pelo usuário.
- Calcular o valor base baseado no tipo e tempo.
- Aplicar desconto se o tempo exceder 5 horas.
- Aplicar multa se o tempo exceder 10 horas.
- Exibir a nota fiscal com todos os detalhes.

### 2. Definição das Variáveis
- **Nome**: `placa`  
  **Tipo**: char[8]  
  **Finalidade**: Armazenar a placa do veículo (ex: ABC1234).

- **Nome**: `tipoVeiculo`  
  **Tipo**: int  
  **Finalidade**: Armazenar o tipo do veículo (1=Carro, 2=Moto, 3=Caminhonete).

- **Nome**: `horas`  
  **Tipo**: int  
  **Finalidade**: Tempo de permanência em horas.

- **Nome**: `valorBase`  
  **Tipo**: float  
  **Finalidade**: Valor base calculado (horas * tarifa do tipo).

- **Nome**: `desconto`  
  **Tipo**: float  
  **Finalidade**: Valor do desconto aplicado (10% se >5 horas).

- **Nome**: `multa`  
  **Tipo**: float  
  **Finalidade**: Valor da multa aplicada (+R$ 20 se >10 horas).

- **Nome**: `valorFinal`  
  **Tipo**: float  
  **Finalidade**: Valor final a pagar (valorBase - desconto + multa).

- **Nome**: `tipoTexto`  
  **Tipo**: char[20]  
  **Finalidade**: Nome do tipo do veículo para exibição (ex: "Carro").

### 3. Regras de Negócio
O sistema considera:
- **Tipos de veículos**:
  - Carro
  - Moto
  - Caminhonete
- **Tempo de permanência**: Em horas (inteiro).
- **Tabela de preços**:
  - Carro: R$ 5/h
  - Moto: R$ 3/h
  - Caminhonete: R$ 8/h
- **Regras adicionais**:
  - Até 1 hora: valor mínimo (calculado normalmente).
  - Acima de 5 horas: desconto de 10% sobre o valor base.
  - Acima de 10 horas: multa adicional de R$ 20.

### 4. Fluxograma do processamento
```
Início
  |
  v
Entrada de dados (placa, tipoVeiculo, horas)
  |
  v
Switch-case para tipoVeiculo:
  - Case 1: tipoTexto = "Carro", valorBase = horas * 5.0
  - Case 2: tipoTexto = "Moto", valorBase = horas * 3.0
  - Case 3: tipoTexto = "Caminhonete", valorBase = horas * 8.0
  - Default: Erro, encerrar
  |
  v
If horas > 5:
  desconto = valorBase * 0.10
Else:
  desconto = 0
  |
  v
If horas > 10:
  multa = 20.0
Else:
  multa = 0
  |
  v
valorFinal = valorBase - desconto + multa
  |
  v
Saída dos resultados (nota fiscal)
  |
  v
Fim
```

## Explicação da Lógica
O programa lê os dados de entrada, usa switch-case para definir o tipo e calcular o valor base, aplica regras de desconto e multa com if/else, calcula o valor final e imprime a nota fiscal.

## Como compilar e executar
### Opção 1 - Online (recomendado para teste rápido)
Acesse https://www.onlinegdb.com/, selecione linguagem C, cole o código e clique em "Run"

### Opção 2 - Local (com GCC)
```bash
gcc main.c -o estacionamento
./estacionamento

## Exemplo de entrada e saída
**Entrada:**
```
Digite a placa do veiculo: ABC1234
Digite o tipo do veiculo: 1
Digite o tempo de permanencia (em horas): 6
```

**Saída:**
```
=== NOTA FISCAL ===
Placa: ABC1234
Tipo do veiculo: Carro
Tempo de permanencia: 6 hora(s)
Valor base: R$ 30.00
Desconto (10% por >5h): -R$ 3.00
Multa: R$ 0,00
VALOR FINAL: R$ 27.00
```
      
