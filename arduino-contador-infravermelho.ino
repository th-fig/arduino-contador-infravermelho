#include <IRremote.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

#define pin_receptor 5 // pino do sensor de infravermelho
#define ir_add 0x1 // codigo infravermelho para aumentar o numero
#define ir_sub 0x9 // codigo infravermelho para diminuir o numero
#define ir_reset 0xC // codigo infravermelho para voltar o numero para 0

// variavel para armazenar o numero
int num = 0;

void setup() {
  IrReceiver.begin(pin_receptor);
  Wire.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {

  if (IrReceiver.decode()) {
  switch (IrReceiver.decodedIRData.command) {
  	case ir_add:
    num = num + 1;
    break;
    
    case ir_sub:
    num = num - 1;
    break;
    
    case ir_reset:
    num = 0;
    break;
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(num);
  }
  IrReceiver.resume();
  delay(10);
}
