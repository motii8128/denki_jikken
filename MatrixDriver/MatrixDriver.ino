#include "MatrixDriver.hpp"

void MatrixDriver::init_pin()
{
  row_pin_[0] = ROW_0;
  row_pin_[1] = ROW_1;
  row_pin_[2] = ROW_2;
  row_pin_[3] = ROW_3;

  column_pin_[0] = COLUMN_0;
  column_pin_[1] = COLUMN_1;
  column_pin_[2] = COLUMN_2;
  column_pin_[3] = COLUMN_3;
  column_pin_[4] = COLUMN_4;

  pinMode(row_pin_[0], OUTPUT);
  pinMode(row_pin_[1], OUTPUT);
  pinMode(row_pin_[2], OUTPUT);
  pinMode(row_pin_[3], OUTPUT);

  pinMode(column_pin_[0], OUTPUT);
  pinMode(column_pin_[1], OUTPUT);
  pinMode(column_pin_[2], OUTPUT);
  pinMode(column_pin_[3], OUTPUT);
  pinMode(column_pin_[4], OUTPUT);
}

void MatrixDriver::off_all()
{
  digitalWrite(row_pin_[0], LOW);
  digitalWrite(row_pin_[1], LOW);
  digitalWrite(row_pin_[2], LOW);
  digitalWrite(row_pin_[3], LOW);

  digitalWrite(column_pin_[0], HIGH);
  digitalWrite(column_pin_[1], HIGH);
  digitalWrite(column_pin_[2], HIGH);
  digitalWrite(column_pin_[3], HIGH);
  digitalWrite(column_pin_[4], HIGH);
}

void MatrixDriver::on_all()
{
  digitalWrite(row_pin_[0], HIGH);
  digitalWrite(row_pin_[1], HIGH);
  digitalWrite(row_pin_[2], HIGH);
  digitalWrite(row_pin_[3], HIGH);

  digitalWrite(column_pin_[0], LOW);
  digitalWrite(column_pin_[1], LOW);
  digitalWrite(column_pin_[2], LOW);
  digitalWrite(column_pin_[3], LOW);
  digitalWrite(column_pin_[4], LOW);
}

void MatrixDriver::digital_on(int x, int y)
{
  digitalWrite(row_pin_[y], HIGH);
  digitalWrite(column_pin_[x], LOW);
}

void MatrixDriver::analog_on(int x, int y, float power_rate)
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
