-----
# 🛠️ Utilities Library for Arduino - CFUtils

Esta é uma biblioteca para Arduino desenvolvida para simplificar a interação com componentes eletrônicos básicos, como **botões**, **LEDs** e **buzzers**. Ela também inclui recursos como um **gerenciador de eventos** e um **logger serial** para facilitar o debug de projetos.

---

## 📦 Componentes Suportados

| Componente | Classe | Arquivo Header |
| :--- | :--- | :--- |
| LED | `Led` | `Led.h` |
| Buzzer (com notas) | `Buzzer` | `Buzzer.h` |
| Botão Genérico (Base) | `Button` | `Button.h` |
| Botão de Pulso | `PushButton` | `PushButton.h` |
| Botão Deslizante | `SliderButton` | `SliderButton.h` |
| Logger Serial | `Logger` | `Logger.h` |
| Gerenciador de Eventos | `EventHandler` | `EventHandler.h` |
| Componente Base | `Component` | `Component.h` |

---

## 🧩 Organização da Biblioteca

```

/CFUtils/
├── examples/
│   └── BasicUsage/
│       └── BasicUsage.ino
└── src/
├── Button.h / Button.cpp
├── Buzzer.h / Buzzer.cpp
├── Component.h
├── Event.h
├── EventHandler.h / EventHandler.cpp
├── Led.h / Led.cpp
├── Logger.h / Logger.cpp
├── Note.h
├── PushButton.h / PushButton.cpp
└── SliderButton.h / SliderButton.cpp

````

---

###  UML - Diagrama de Classes

*Esta seção está reservada para o diagrama de classes do projeto, mostrando a relação entre as classes.*


## ⚙️ Instalação

1.  Baixe e extraia o conteúdo da pasta `CFUtils/`
2.  Copie a pasta para o diretório de bibliotecas do Arduino:
    * **Windows:** `Documentos/Arduino/libraries`
    * **Linux/Mac:** `~/Arduino/libraries/`
3.  Reinicie a IDE do Arduino.
4.  Acesse o exemplo em: `Arquivo > Exemplos > CFUtils > BasicUsage`.

---

## 🧪 Exemplo Principal

### `BasicUsage.ino`

Este sketch demonstra o uso combinado de vários componentes da biblioteca. A rotina principal geralmente inclui:

1.  **Logger:** Envia mensagens de status para o Serial Monitor.
2.  **LED:** Pisca para indicar que o programa está rodando.
3.  **Botões:** Aguarda a interação do usuário para disparar ações, como acender o LED ou tocar um som no buzzer.

Abra o **Serial Monitor** (baud rate: `9600`) para ver os logs gerados pela classe `Logger`.

---

## 💡 Exemplo de Uso (Logger e LED)

```cpp
#include <Logger.h>
#include <PushButton.h>

PushButton myButton(2);
Logger logger;

void onButtonPress() {
    logger.log(INFO, "Botão pressionado!");
}

void setup() {
    Logger::begin(9600);
    myButton.setEventCallback(onButtonPress);
}

void loop() {
    myButton.update();
}
````

-----

## 🧠 Requisitos

  * Placa Arduino (Uno, Nano, Mega ou compatível)
  * IDE Arduino 1.8+ ou 2.0+

-----

Projeto desenvolvido com fins educacionais e práticos para o trabalho final da disciplina de Computação Física.

-----

