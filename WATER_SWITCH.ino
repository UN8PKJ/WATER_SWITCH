/*
 * Реле времени с управлением по радиоканалу
 * Copyright @2021 Oleg Koksharov
*/

#define DURATION  10000   //Продолжительность включения
#define PUSH      2000    //Максимальная продолжительность удержания кнопки
#define BUTTON    4       //Пин кнопки
#define RELAY     13      //Пин реле

bool state = false;
long timeout = millis();

void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(RELAY, OUTPUT);
}

void loop() 
{
  if (digitalRead(BUTTON))
  {
    state = !state;
    digitalWrite(RELAY, state);
    timeout = millis();
    delay(PUSH);
  }

  if ((timeout + DURATION) < millis())
  {
    state = false;
    digitalWrite(RELAY, state);
    timeout = millis();
  }
}
