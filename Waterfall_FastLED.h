
#define START_HOURS   18  // время включения, час запускаемой программы работы светодиодной ленты
#define START_MINUTES 00  // время включения, мин
#define STOP_HOURS    22  // время вЫключения, час
#define STOP_MINUTES  30  // время вЫключения, мин

#define ASKING_CLOCK 30000  // Время, мс, между опросами часов реального времени

#define LED_STRING_PIN 12                               // пин подключения вывода Din светодиодной ленты
#define RELAY_PIN 2                                         // реле включения питания ленты
#define BUTTON 15                                           // Кнопка принудительного включения/выключения работы программ

#define NUMBER_OF_PROGRAMS 8                                // число запускаемых программ работы светодиодной ленты
#define LENGTH_OF_LED_STRING 297                            // всего светодиодов в ленте = 297

#define STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING 50
#define ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING 157
#define STARTING_NUMBER_OF_LED_FOR_BACKLIGHT ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING+35

#define MAX_RUNNING_TIME 3600000 // максимально задаваемое время работы программы, 60 минут

#define MIN_PROG_RUNNING_TIME 10000 // минимальное время работы программы работы светодиодной ленты, мс
#define MAX_PROG_RUNNING_TIME 30000 // максимальное время работы программы работы светодиодной ленты, мс
