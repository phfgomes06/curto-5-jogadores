# Curto

## Descrição
Este é um projeto didático desenvolvido para alunos de **Introdução à Programação**, com o objetivo de ensinar conceitos fundamentais de programação em C, como estruturas, enumerações, ponteiros, funções e modularização. O programa simula um jogo de cartas simples com suporte a jogadores, baralhos, rodadas e fases de apostas.

---

## Como Compilar e Executar

### Compilação
Compile todos os arquivos com o seguinte comando:
```bash
gcc main.c card.c deck.c player.c hand.c betting.c round.c game.c -o card_game
```

### Execução
Execute o programa com o comando:
```bash
./card_game
```

---

## Funcionalidades do Código

### 1. **Cartas**
- Cada carta possui um **naipe** (`HEARTS`, `DIAMONDS`, `CLUBS`, `SPADES`) e um **valor** (`2-7`, `ACE`, `JACK`, `QUEEN`, `KING`).

### 2. **Baralho**
- Um baralho padrão é inicializado e embaralhado, contendo todas as combinações de cartas possíveis.

### 3. **Jogadores**
- Cada jogador possui:
  - Nome
  - Cartas na mão (até 6 cartas)
  - Ponteiros para funções que definem estratégias de aposta e jogada.

### 4. **Mãos**
- Representa as cartas jogadas por cada jogador em uma rodada.

### 5. **Apostas**
- Gerencia a estimativa de vitorias de cada jogador por rodada.

### 6. **Rodadas**
- Representa uma única rodada do jogo, incluindo a fase de apostas.

### 7. **Jogo Completo**
- Coordena a sequência de rodadas, gerencia o baralho, jogadores e determina o vencedor/ perdedir final.

## Licença
Este projeto é livre para uso acadêmico e didático. Sinta-se à vontade para modificá-lo e adaptá-lo às suas necessidades.
