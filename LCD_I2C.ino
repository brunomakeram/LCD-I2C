/*
LIGAÇÕES COM I2C NO ARDUÍNO:
GND PLACA NO GND DO I2C
5V DA PLCA NO VCC DO I2C
SCL DO I2C NO PINO ANALÓGICO 4 DA PLACA
SDA DO I2C NO PINO ANALÓGICO 5 DA PLACA

CASO O POTENCIÔMETRO DO I2C NÃO FUNCIONE(NÃO LIGUE NEM APAREÇA MENSAGEM):
1 - USE UM JUMPER FÊMEA-FÊMEA LIGANDO OS PINOS DO LED I2C
2 - LIGUE UM JUMPER FÊMEA NO V0 DO I2C "TERCEIRO PINO DA ESQUERDA PRA DIREITA LCD PRA CIMA"
3 - LIGUE UM RESISTOR DE 2K NA OUTRA PONTA DO JUMPER FÊMEA
4 - LIGUE A SEGUNDA PONTA DO RESISTOR A OUTRO JUMPER MACHO-FÊMEA
5 - LIGUE O PINO DO JUMPER NO GND DA PLACA(ARDUÍNO)
*/

#include <LiquidCrystal_I2C.h>

// Classe para uso do LCD com I2C...
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Frase fixa da primeira linha...
String palavra_digitada = "Voce Digitou:";
// Recebe a palavra digita...
String digitar_palavra = "";

void setup() {
  Serial.begin(9600);
  // "init();" inicializa o LCD
  lcd.init();
  // "backlight();" acende a luz de fundo...
  lcd.backlight();
}

void loop() {
  // Limpa a tela antes de pedir a nova palavra
  lcd.clear();
  // Pede para digitar a palavra...
  Serial.println("Digite a palavra...");

  // Espera o usuário digitar na serial...
  while (Serial.available() == 0) {
    delay(100);
  }

  // Lê até apertar Enter...
  digitar_palavra = Serial.readStringUntil('\n');
  // Limpa os espaços do início, fim e quebra de linhas...
  digitar_palavra.trim();

  // Limpa a tela para garantir que não tenha lixo do ciclo anterior
  lcd.clear();
  
  // "0" é a coluna de cima, a primeira, da esquerda pra direita...
  // "0" é linha de cima, a primeira, da esquerda pra direita...
  lcd.setCursor(0,0);
  // "11" caracteres na palavra +1 no espaço e 1 no ":"...
  lcd.print(palavra_digitada);
  
  // "0" primeira coluna de baixo a esquerda...
  // "1" segunda linha, de baixo...
  lcd.setCursor(0,1);
  lcd.print(digitar_palavra);
  
  // Tempo para a pessoa ler o que digitou
  delay(3000); 

  // "clear();" Limpa e mostra os créditos
  lcd.clear();
  // Créditos...
  lcd.setCursor(0,0);
  lcd.print("Desenvolvido por");
  lcd.setCursor(0,1);
  lcd.print("Bruno Maker 2026");
  
  // Tempo mostrando os créditos
  delay(2000);
  
  // O "loop();" chega ao fim e recomeça automaticamente...
}