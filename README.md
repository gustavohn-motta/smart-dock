# 🛌 Dock Inteligente para Cama Motorizada Integrada com Alexa

## ❕ Introdução
Este projeto tem como objetivo apresentar os pontos essenciais para a montagem de um **dock inteligente** para controle de cama motorizada integrado com **AWS Alexa** e conexões **Wi-Fi**.  

O foco é atender pessoas **acamadas ou com mobilidade reduzida**, que encontram dificuldades ou impossibilidade em usar as mãos para operar o controle da cama (ajuste de leito, encosto e pernas).  

A proposta também prioriza que a comunidade possa **implementar e adaptar facilmente**, utilizando módulos de circuitos eletrônicos comuns e um **esquema simples de montagem**.

---

## ⚙️ Funcionamento
O dock atua como um **acionador inteligente**, simulando os comandos do controle da cama motorizada.  
Ele é capaz de realizar ações como:
- Subir encosto
- Ajustar inclinação das pernas
- Subir altura do leito
- (Outros comandos podem variar conforme o modelo do controle da cama)

---

## ⚙️ Componentes Eletrônicos Utilizados
- **ESP8266 NodeMCU v3**
- **PCA9685** – Servo Driver
- **XL4005 Step Down** – Regulador de Tensão
- **Servo 9g** – Motor

---

## 🔷 Configuração do Ambiente

### Boards Manager
* https://arduino.esp8266.com/stable/package_esp8266com_index.json

### Bibliotecas Requeridas
#### [EspAlexa (integração com Alexa)]
  * https://github.com/Aircoookie/Espalexa  
#### [Adafruit PWM Servo Driver Library (controle de servos)]
  * https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library
  * https://github.com/adafruit/Adafruit_BusIO

---

## 👉 Objetivo
Fornecer uma solução **acessível e inclusiva**, que permita a automação de camas hospitalares ou residenciais, **melhorando a qualidade de vida** de pessoas com mobilidade reduzida.

---

## 🧑‍🤝‍🧑 Contribuições
Este projeto é **aberto à comunidade** e está em desenvolvimento, em breve irei complementar o repositório com esquemas de ligações entre os componentes e tambem irei adicionar os arquivos para impressão3 do corpo do dock.  
Sugestões, melhorias e novas implementações são bem-vindas!

---

## � Licença
Distribuído sob a licença MIT. Consulte o arquivo `LICENSE` para mais detalhes.
