# Curto

## Descrição
**Curto** é um projeto didático desenvolvido para ensinar conceitos fundamentais de programação em C. O programa simula um jogo de cartas simples, abordando tópicos como estruturas, enumerações, ponteiros, funções e modularização.

## Funcionalidades
- **Cartas**: Cada carta possui um **naipe** (`OUROS`, `ESPADAS`, `COPAS`, `PAUS`) e um **valor** (`4-7`, `DAMA`, `VALETE`, `REI`, `AS`, `2`, `3`).
- **Baralho**: Um baralho padrão é inicializado e embaralhado, contendo todas as combinações de cartas.
- **Jogadores**: Suporte para múltiplos jogadores, cada um com estratégias de aposta e jogada.
- **Rodadas**: Gerenciamento de rodadas, incluindo distribuição de cartas, apostas e resolução de mãos.
- **Jogo Completo**: Coordenação de rodadas, cálculo de penalidades e determinação do vencedor.

## Estrutura do Projeto
- **Arquivos principais**:
  - `main.c`: Ponto de entrada do programa.
  - `baralho.c`: Gerenciamento do baralho.
  - `rodada.c`: Lógica das rodadas.
  - `mao.c`: Resolução de mãos.
  - `jogo.c`: Controle geral do jogo.
- **Jogadores**:
  - Estratégias implementadas em `jogadores/aleatorio1.c`, `jogadores/aleatorio2.c`, `jogadores/simples.c`, `jogadores/simples2.c`.

## Compilação e Execução

### Compilação
Para compilar o programa principal, execute:
```bash
gcc main.c baralho.c rodada.c mao.c jogo.c jogadores/aleatorio1.c jogadores/aleatorio2.c jogadores/simples.c jogadores/simples2.c -o card_game
```

### Execução
Para executar o programa, utilize:
```bash
./card_game
```

## Licença
Este projeto é livre para uso acadêmico e didático. Sinta-se à vontade para modificá-lo e adaptá-lo às suas necessidades.
