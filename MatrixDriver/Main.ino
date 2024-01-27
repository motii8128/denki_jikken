#include "MatrixDriver.hpp"



MatrixDriver driver;

void setup()
{
  driver.init_pin();
  driver.off_all();
}

void loop()
{
  vertical_snake(100);
}

void all_flush(int delay_ms)
{
  driver.on_all();
  delay(delay_ms);
  driver.off_all();
  delay(delay_ms);
}

void vertical_snake(int delay_ms)
{
  for(int i = 0; i < COLUMN_NUM; i++)
  {
    for(int j = 0; j < ROW_NUM; j++)
    {
      driver.digital_on(i, j);
      delay(delay_ms);
      driver.turn_off(i, j);
      delay(delay_ms);
    }
  }
}

void grad_horizontal(int delay_ms)
{
  int count = 0;
  while(count < 100)
  {
    for(int i = 0; i < COLUMN_NUM; i++)
    {
      for(int j = 0; j < ROW_NUM; j++)
      {
        driver.analog_on(i, j, count);
      }
    }
    count++;
    delay(delay_ms);
  }
  while(count > 0)
  {
    for(int i = 0; i < COLUMN_NUM; i++)
    {
      for(int j = 0; j < ROW_NUM; j++)
      {
        driver.analog_on(i, j, count);
      }
    }
    count--;
    delay(delay_ms);
  }
  driver.off_all();
  delay(delay_ms);
}