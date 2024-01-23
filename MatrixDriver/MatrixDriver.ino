#include "MatrixDriver.hpp"

void MatrixDriver::init_pin()
{
  for(int i = 0; i < ROW_NUM; i++)
  {
    row_pin_[i] = ROW_PINS[i];
    pinMode(row_pin_[i], OUTPUT);
  }

  for(int i = 0; i < COLUMN_NUM; i++)
  {
    column_pin_[i] = COLUMN_PINS[i];
    pinMode(column_pin_[i], OUTPUT);
  }
}

void MatrixDriver::off_all()
{
  for(int x = 0; x < COLUMN_NUM; x++)
  {
    for(int y = 0; y < ROW_NUM; y++)
    {
      turn_off(x, y);
    }
  }
}

void MatrixDriver::on_all()
{
  for(int x = 0; x < COLUMN_NUM; x++)
  {
    for(int y = 0; y < ROW_NUM; y++)
    {
      digital_on(x, y);
    }
  }
}

void MatrixDriver::digital_on(int x, int y)
{
  digitalWrite(row_pin_[y], HIGH);
  digitalWrite(column_pin_[x], LOW);
}

void MatrixDriver::analog_on(int x, int y, int power_rate)
{
  int value = map(power_rate, 0, 100, 0, 255);
  analogWrite(row_pin_[y], value);
  digitalWrite(column_pin_[x], LOW);
}

void MatrixDriver::turn_off(int x, int y)
{
  digitalWrite(row_pin_[y], LOW);
  digitalWrite(column_pin_[x], HIGH);
}