# Tarefa: Temporizador Periódico

## Descrição
Este projeto implementa um **semáforo** utilizando um **temporizador periódico** com a função `add_repeating_timer_ms()` da biblioteca **Pico SDK**. A cada **3 segundos**, o semáforo altera a cor do LED, seguindo a ordem **vermelho -> amarelo -> verde**.

A implementação é feita na **linguagem C**, para execução no microcontrolador **Raspberry Pi Pico W** e pode ser simulada utilizando o **Wokwi** ou **BitDogLab**.

---

## 📋 Requisitos da Atividade 1

Os seguintes requisitos foram implementados:

1. **Acionamento inicial**: O LED vermelho inicia ligado, seguido pelo amarelo e depois o verde.
2. **Temporização de 3 segundos**: O temporizador periódico alterna o estado do semáforo a cada **3.000ms**.
3. **Uso da função de callback `repeating_timer_callback()`** para controlar a mudança dos LEDs.
4. **Rotina principal** (`while(true)`) imprime uma mensagem a cada **1 segundo (1000ms)** na porta serial.
5. **Utiliza os GPIOs 11, 12 e 13** para os LEDs (verde, amarelo e vermelho).
6. **Simulação recomendada com BitDogLab** e execução no VS Code.

---

## 🔧 Configuração do Hardware

### 📌 Componentes Necessários:
- 1 x **Raspberry Pi Pico W**
- 3 x **LEDs** (Vermelho, Amarelo e Verde)
- 3 x **Resistores de 330 Ω**
- Jumpers para conexão
- Placa de ensaio (opcional)

### 📌 Ligação dos LEDs:

| Cor do LED | GPIO |
|------------|------|
| Vermelho   | 13   |
| Amarelo    | 12   |
| Verde      | 11   |

---

## 🖥️ Configuração do Ambiente de Desenvolvimento

### 📌 Ferramentas:
- **VS Code** (com extensão C/C++)
- **Pico SDK** (instalado e configurado)
- **CMake e Make**
- **Simulador Wokwi ou BitDogLab**

### 📌 Clonando o Repositório e Compilando:
```sh
# Clonar o repositório
git clone https://github.com/limarich/tarefa-temporizador-periodico.git
cd tarefa-temporizador

utilizar a biblioteca Raspberry Pico W para compilar o projeto
```

## 📜 Estrutura do Código

O programa está estruturado em **três partes principais**:
1. **Configuração dos pinos**: Define os LEDs como saída e inicia o semáforo no vermelho.
2. **Callback do Temporizador**: Alterna os LEDs a cada 3 segundos.
3. **Loop Principal**: Mantém o programa rodando e imprime mensagens na serial a cada segundo.

### 📌 Fluxograma da Lógica do Semáforo:
```text
[INÍCIO]
   |
   V
[Liga LED Vermelho]
   |
   V
(Espera 3s)
   |
   V
[Liga LED Amarelo]
   |
   V
(Espera 3s)
   |
   V
[Liga LED Verde]
   |
   V
(Espera 3s)
   |
   V
[Reinicia ciclo]
```

---

