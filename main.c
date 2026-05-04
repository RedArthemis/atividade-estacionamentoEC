#include <stdio.h>
#include <string.h>

int main() {
    
    // DECLARAÇÃO DE VARIÁVEIS
   
    char placa[8];               // Placa do veículo (ex: ABC1234)
    int tipoVeiculo;             // 1 - Carro, 2 - Moto, 3 - Caminhonete
    int horas;                   // Tempo de permanência em horas
    float valorBase = 0;         // Valor base sem descontos/multas
    float desconto = 0;          // Valor do desconto (se houver)
    float multa = 0;             // Valor da multa (se houver)
    float valorFinal = 0;        // Valor final a pagar
    char tipoTexto[20];          // Nome do tipo do veículo para exibição

    
    // ENTRADA DE DADOS
    
    printf("=== SISTEMA DE ESTACIONAMENTO ROTATIVO ===\n");
    
    printf("Digite a placa do veiculo: ");
    scanf("%s", placa);
    
    printf("\n--- Tabela de tipos ---\n");
    printf("1 - Carro (R$ 5/h)\n");
    printf("2 - Moto (R$ 3/h)\n");
    printf("3 - Caminhonete (R$ 8/h)\n");
    printf("Digite o tipo do veiculo: ");
    scanf("%d", &tipoVeiculo);
    
    printf("Digite o tempo de permanencia (em horas): ");
    scanf("%d", &horas);
    
    
    // PROCESSAMENTO (switch-case + if/else)
    
    // 1. Define o valor base por hora conforme o tipo
    switch(tipoVeiculo) {
        case 1:
            strcpy(tipoTexto, "Carro");
            valorBase = horas * 5.0;
            break;
        case 2:
            strcpy(tipoTexto, "Moto");
            valorBase = horas * 3.0;
            break;
        case 3:
            strcpy(tipoTexto, "Caminhonete");
            valorBase = horas * 8.0;
            break;
        default:
            printf("\nERRO: Tipo de veiculo invalido!\n");
            return 1;  // Encerra o programa com erro
    }
    
    // 2. Regras adicionais (desconto/multa)
    // Até 1 hora: valor mínimo (já está correto, pois valorBase = 1h * tarifa)
    // Acima de 5 horas: desconto de 10%
    if(horas > 5) {
        desconto = valorBase * 0.10;
    }
    
    // Acima de 10 horas: multa adicional de R$ 20
    if(horas > 10) {
        multa = 20.0;
    }
    
    // 3. Cálculo do valor final
    valorFinal = valorBase - desconto + multa;
    
    
    // SAÍDA DOS RESULTADOS
  
    printf("\n=== NOTA FISCAL ===\n");
    printf("Placa: %s\n", placa);
    printf("Tipo do veiculo: %s\n", tipoTexto);
    printf("Tempo de permanencia: %d hora(s)\n", horas);
    printf("Valor base: R$ %.2f\n", valorBase);
    
    if(desconto > 0) {
        printf("Desconto (10%% por >5h): -R$ %.2f\n", desconto);
    } else {
        printf("Desconto: R$ 0,00\n");
    }
    
    if(multa > 0) {
        printf("Multa (>10h): +R$ %.2f\n", multa);
    } else {
        printf("Multa: R$ 0,00\n");
    }
    
    printf("VALOR FINAL: R$ %.2f\n", valorFinal);
    
    return 0;
}
