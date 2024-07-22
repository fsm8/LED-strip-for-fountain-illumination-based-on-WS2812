
///// радуга на ленте
void program_0(void)
{
  static byte counter;
  for (int i = 0; i < LENGTH_OF_LED_STRING; i++)
  {
    if ((i >= 0 && i < STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING) || (i > ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING && i < STARTING_NUMBER_OF_LED_FOR_BACKLIGHT))
    {
      leds[i].setRGB(0, 0, 0); // гасим светодиоды между первой и второй подсветками
    }
    if (i >= STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING && i <= ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING)
    {
      leds[i].setHue(counter + i * 255 / (ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING - STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING));
    }
    if (i > STARTING_NUMBER_OF_LED_FOR_BACKLIGHT)
    {
      leds[i].setRGB(255, 255, 255); // зажигаем белые светодиоды в конце ленты
    }
  }
  counter += 2;  // counter меняется от 0 до 255
  FastLED.show();
  delay(random(1, 10));  // скорость движения радуги
}


///// радуга рандомно
void program_1(void)
{
  for (int i = 0; i < LENGTH_OF_LED_STRING; i++)
  {
    if ((i >= 0 && i < STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING) || (i > ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING && i < STARTING_NUMBER_OF_LED_FOR_BACKLIGHT))
    {
      leds[i].setRGB(0, 0, 0);
    }
    if (i >= STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING && i <= ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING)
    {
      leds[i].setHue(random(0, 255));
    }
    if (i > STARTING_NUMBER_OF_LED_FOR_BACKLIGHT)
    {
      leds[i].setRGB(255, 255, 255);
    }
  }
  FastLED.show();
  delay(random(15, 125));  // скорость движения радуги
}


///// на черном фоне зажигаются светодиоды
void program_2(void) {
  for (int i = 0; i < LENGTH_OF_LED_STRING; i++)
  {
    if ((i >= 0 && i < STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING) || (i > ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING && i < STARTING_NUMBER_OF_LED_FOR_BACKLIGHT))
    {
      leds[i].setRGB(0, 0, 0);
    }
    if (i >= STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING && i <= ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING)
    {
      if (i == random(0, LENGTH_OF_LED_STRING))
      {
        leds[i].setHue(random(0, 255));
      }
    }
    if (i > STARTING_NUMBER_OF_LED_FOR_BACKLIGHT)
    {
      leds[i].setRGB(255, 255, 255);
    }
  }
  FastLED.show();
  FastLED.clear();
  delay(random(10, 100));
}


// на черном фоне бегущая цветная точка
void program_3(void)
{
  long cnt = random(2);
  if (cnt)
  {
    for (int ii = 0; ii < LENGTH_OF_LED_STRING; ii++)
    {
      if (ii > STARTING_NUMBER_OF_LED_FOR_BACKLIGHT)
      {
        leds[ii].setRGB(255, 255, 255);
      }
      for (int i = STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING; i < ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING; i++)
      {
        if (i == ii)
        {
          leds[i].setHue(random(0, 255));
        }
        else
        {
          leds[i].setRGB(0, 0, 0);
        }
      }
      FastLED.show();
    }
  }
  else
  {
    for (int ii = LENGTH_OF_LED_STRING - 1; ii >= 0; ii--)
    {
      if (ii > STARTING_NUMBER_OF_LED_FOR_BACKLIGHT)
      {
        leds[ii].setRGB(255, 255, 255);
      }
      for (int i = STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING; i < ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING; i++)
      {
        if (i == ii)
        {
          leds[i].setHue(random(0, 255));
        }
        else
        {
          leds[i].setRGB(0, 0, 0);
        }
      }
      FastLED.show();
    }
  }
}


// плавное изменение яркости белого фона подводной подсветки
void program_4(void)
{
  for (int ii = 0; ii <= 255; ii++)
  {
    for (int i = 0; i < LENGTH_OF_LED_STRING; i++)
    {
      if ((i >= 0 && i < STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING) || (i > ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING && i < STARTING_NUMBER_OF_LED_FOR_BACKLIGHT))
      {
        leds[i].setRGB(0, 0, 0);
      }
      if (i >= STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING && i <= ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING)
      {
        leds[i].setRGB(ii, ii, ii);
      }
      if (i > STARTING_NUMBER_OF_LED_FOR_BACKLIGHT)
      {
        leds[i].setRGB(255, 255, 255);
      }
    }
    FastLED.show();
  }
  for (int ii = 255; ii >= 0; ii--)
  {
    for (int i = LENGTH_OF_LED_STRING - 1; i >= 0; i--)
    {

      if ((i >= 0 && i < STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING) || (i > ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING && i < STARTING_NUMBER_OF_LED_FOR_BACKLIGHT))
      {
        leds[i].setRGB(0, 0, 0);
      }
      if (i >= STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING && i <= ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING)
      {
        leds[i].setRGB(ii, ii, ii);
      }
      if (i > STARTING_NUMBER_OF_LED_FOR_BACKLIGHT)
      {
        leds[i].setRGB(255, 255, 255);
      }
    }
    FastLED.show();
  }
}


// зажигается рандомным цветом по одному
void program_5(void)
{
  int R = random(0, 255);
  int G = random(0, 255);
  int B = random(0, 255);
  for (int i = 0; i < LENGTH_OF_LED_STRING; i++)
  {
    if ((i >= 0 && i < STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING) || (i > ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING && i < STARTING_NUMBER_OF_LED_FOR_BACKLIGHT))
    {
      leds[i].setRGB(0, 0, 0);
      FastLED.show();
    }
    if (i >= STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING && i <= ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING)
    {
      leds[i].setRGB(R, G, B);
      FastLED.show();
    }
    if (i > STARTING_NUMBER_OF_LED_FOR_BACKLIGHT)
    {
      leds[i].setRGB(255, 255, 255);
      FastLED.show();
    }
    //leds[i].setRGB(R, G, B);
    //FastLED.show();
  }
  delay(random(300, 800));
  FastLED.clear();
}


// плавно зажигается снизу вверх разноцветным
void program_6(void)
{
  for (int i = 0; i < LENGTH_OF_LED_STRING; i++)
  {
    if ((i >= 0 && i < STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING) || (i > ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING && i < STARTING_NUMBER_OF_LED_FOR_BACKLIGHT))
    {
      leds[i].setRGB(0, 0, 0);
      FastLED.show();
    }
    if (i >= STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING && i <= ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING)
    {
      leds[i].setHue(random(0, 255));
      FastLED.show();
    }
    if (i > STARTING_NUMBER_OF_LED_FOR_BACKLIGHT)
    {
      //leds[i].setRGB(255, 255, 255);
      leds[i].setHue(random(0, 255));
      FastLED.show();
    }
    //leds[i].setHue(random(0, 255));
    //FastLED.show();
  }
  delay(random(300, 800));
  FastLED.clear();
}


void program_7(void)
{
  int color = random(0, 125);
  for (int i = STARTING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING; i < ENDING_NUMBER_OF_LED_FOR_UNDER_WATER_LIGHTNING; i++)
  {
    leds[i].setHue(color);
  }
  FastLED.show();
  delay(random(300, 800));
  FastLED.clear();
}
