#include "Waterfall_FastLED.h"

#include "FastLED.h"
CRGB leds[LENGTH_OF_LED_STRING];

#include <microDS3231.h>
MicroDS3231 rtc;
//Подключение RTC к Ардуино: GND > GND, VCC > VCC 3,3, SDA > D21, SCL > D22

// Проверяем, что задаваемое время работы программ не превышают допустимый предел значений
#if (MIN_PROG_RUNNING_TIME > MAX_RUNNING_TIME || MAX_PROG_RUNNING_TIME > MAX_RUNNING_TIME)
#error Error! Time (MIN_PROG_RUNNING_TIME or MAX_PROG_RUNNING_TIME) exceed maximum (60minutes)
#endif

void setup()
{
  FastLED.addLeds<WS2812, LED_STRING_PIN, GRB>(leds, LENGTH_OF_LED_STRING);
  FastLED.setBrightness(25); // задаем яркость светодиодной ленты, 0-100 %
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  turnoff_all_leds();  // Гасим все светодиоды
  //rtc.setTime(COMPILE_TIME); // Установка текущей даты и времени, равное времени компиляции программы
}


void loop()
{
  static byte flag = 0; // флаг для пуск/стоп запускаемой программы светодиодной ленты по времени
  static unsigned long myTimer;  // переменная для millis и rnd_time
  static unsigned long myTimer2; // переменная для millis и ASKCLOCK
  static byte number_of_current_program = random(NUMBER_OF_PROGRAMS + 1); // генерируем, после подачи питания, номер первой запускаемой программы работы светодиодной ленты
  static uint32_t program_running_time = MIN_PROG_RUNNING_TIME; // время работы первой запускаемой программы работы светодиодной ленты, после подачи питания

  ///// Рандомная генерация номера запускаемой программы работы светодиодной ленты через промежуток времени, генерируемый рандомно
  if (millis() - myTimer >= program_running_time)
  {
    myTimer = millis();
    number_of_current_program = random(0, NUMBER_OF_PROGRAMS + 1); // генерируем номер запускаемой программы работы светодиодной ленты
    program_running_time = random(MIN_PROG_RUNNING_TIME, MAX_PROG_RUNNING_TIME);  // генерируем промежуток времени через который запускается новая программа работы светодиодной ленты
  }

  ///// Опрос часов реального времени
  if (millis() - myTimer2 >= ASKING_CLOCK)
  {
    myTimer2 = millis();
    set_or_reset_flag_by_time(& flag); // пуск/стоп запускаемой программы работы светодиодной ленты если время пришло
  }

  ///// Включаем/выключаем работу программ с кнопки
  if (!digitalRead(BUTTON)) // если кнопка была нажата
  {
    flag = !flag; // пуск/стоп запускаемой программы
    flag ? digitalWrite(RELAY_PIN, HIGH) : digitalWrite(RELAY_PIN, LOW); // включение/вЫключение реле включения питания светодиодной ленты и фонтана
    delay(1000); // пауза для подавления возможного дребезга контактов кнопки
  }

  ///// Старт программы работы светодиодной ленты № number_of_current_program, если флаг был установлен, или гасим светодиоды, если нет
  switching_of_program(flag, number_of_current_program);
}


// Гасим все светодиоды
void turnoff_all_leds(void)
{
  for (int i = 0; i < LENGTH_OF_LED_STRING; i++)
  {
    leds[i].setRGB(0, 0, 0);
  }
  FastLED.show();
}


///// Пуск/стоп запускаемой программы светодиодной ленты по времени
void set_or_reset_flag_by_time(byte* flag)
{
  if (rtc.getHours() == START_HOURS && rtc.getMinutes() == START_MINUTES) // время включения
  {
    *flag = 1; // пуск работы программ
    digitalWrite(RELAY_PIN, HIGH); // включение реле включения питания светодиодной ленты и фонтана
  }
  if (rtc.getHours() == STOP_HOURS && rtc.getMinutes() == STOP_MINUTES) // время вЫключения
  {
    *flag = 0; // стоп работы программ
    digitalWrite(RELAY_PIN, LOW); // вЫключение реле включения питания светодиодной ленты и фонтана
  }
}


///// Выбор запускаемой программы работы светодиодной ленты, если флаг установлен, или гасим светодиоды, если не установлен
void switching_of_program(byte flag, byte number_of_current_program)
{
  if (flag)
  {
    switch (number_of_current_program)
    {
      case 0: program_0(); break;
      case 1: program_1(); break;
      case 2: program_2(); break;
      case 3: program_3(); break;
      case 4: program_4(); break;
      case 5: program_5(); break;
      case 6: program_6(); break;
      case 7: program_7(); break;
      default: break;
    }
  }
  else
  {
    for (int i = 0; i < LENGTH_OF_LED_STRING; i++)
    {
      leds[i].setRGB(0, 0, 0);
    }
    FastLED.show();
  }
}
