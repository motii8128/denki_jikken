#ifndef FUNC_HPP_
#define FUNC_HPP_

#include "MatrixDriver.hpp"
#include <stdlib.h>

struct Vec
{
  int x;
  int y;
};

void all_flush(MatrixDriver driver, int delay_ms)
{
  driver.on_all();
  delay(delay_ms);
  driver.off_all();
  delay(delay_ms);
}

void vertical_snake(MatrixDriver driver, int delay_ms, int times)
{
  int count = 0;
  while(count < times)
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
    count++;
  }
}

void grad(MatrixDriver driver, int delay_ms, int times)
{
  int count = 0;
  while(count < times)
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
  driver.off_all();
  delay(delay_ms);
}

void grad_updown(MatrixDriver driver, int delay_ms, int times)
{
  int value[4] = {25, 50, 75, 100};

  int count = 0;
  while(count < times)
  {
    for(int i = 0; i < COLUMN_NUM; i++)
    {
      for(int j = 0; j < ROW_NUM; j++)
      {
        driver.analog_on(i, j, value[i]);
        value[i] += 20;
        if(value[i] == 100)
        {
          value[i] = 0;
        }
      }
    }
    count++;
    delay(delay_ms);
  }
  driver.off_all();
  delay(delay_ms);
}

void grad_downup(MatrixDriver driver, int delay_ms, int times)
{
  int value[4] = {25, 50, 75, 100};

  int count = 0;
  while(count < times)
  {
    for(int i = 0; i < ROW_NUM; i++)
    {
      for(int j = 0; j < COLUMN_NUM; j++)
      {
        driver.analog_on(j, i, value[i]);
      }
      value[i] += 20;
        if(value[i] == 100)
        {
          value[i] = 0;
        }
    }
    count++;
    delay(delay_ms);
  }
  driver.off_all();
  delay(delay_ms);
}

void cycron(MatrixDriver driver, int delay_ms, int times)
{
  int count = 0;
  while(count < times)
  {
    driver.digital_on(0, 0); 
    delay(delay_ms);
    driver.turn_off(0, 0);
    driver.digital_on(1, 0); 
    delay(delay_ms);
    driver.turn_off(1, 0);
    driver.digital_on(2, 0); 
    delay(delay_ms);
    driver.turn_off(2, 0);
    driver.digital_on(3, 0); 
    delay(delay_ms);
    driver.turn_off(3, 0);
    driver.digital_on(4, 0); 
    delay(delay_ms);
    driver.turn_off(4, 0);
    driver.digital_on(4, 1); 
    delay(delay_ms);
    driver.turn_off(4, 1);
    driver.digital_on(4, 2); 
    delay(delay_ms);
    driver.turn_off(4, 2);
    driver.digital_on(4, 3); 
    delay(delay_ms);
    driver.turn_off(4, 3);
    driver.digital_on(3, 3); 
    delay(delay_ms);
    driver.turn_off(3, 3);
    driver.digital_on(2, 3); 
    delay(delay_ms);
    driver.turn_off(2, 3);
    driver.digital_on(1, 3); 
    delay(delay_ms);
    driver.turn_off(1, 3);
    driver.digital_on(0, 3); 
    delay(delay_ms);
    driver.turn_off(0, 3);
    driver.digital_on(0, 2); 
    delay(delay_ms);
    driver.turn_off(0, 2);
    driver.digital_on(0, 1); 
    delay(delay_ms);
    driver.turn_off(0, 1);
    driver.digital_on(1, 1); 
    delay(delay_ms);
    driver.turn_off(1, 1);
    driver.digital_on(2, 1); 
    delay(delay_ms);
    driver.turn_off(2, 1);
    driver.digital_on(3, 1); 
    delay(delay_ms);
    driver.turn_off(3, 1);
    driver.digital_on(3, 2); 
    delay(delay_ms);
    driver.turn_off(3, 2);
    driver.digital_on(2, 2); 
    delay(delay_ms);
    driver.turn_off(2, 2);
    driver.digital_on(1, 2); 
    delay(delay_ms);
    driver.turn_off(1, 2);

    count++;
  }
}

void grad_lr(MatrixDriver driver, int delay_ms, int times)
{
  int value[5] = {20, 40, 60, 80, 100};

  int count = 0;
  while(count < times)
  {
    for(int i = 0; i < COLUMN_NUM; i++)
    {
      for(int j = 0; j < ROW_NUM; j++)
      {
        driver.analog_on(i, j, value[i]);
      }
      value[i] += 20;
      if(value[i] == 100)
      {
        value[i] = 20;
      }
    }
    count++;
    delay(delay_ms);
  }
  driver.off_all();
  delay(delay_ms);
}

void fl_rr(MatrixDriver driver, int delay_ms, int times)
{
  int count = 0;
  while(count < times)
  {
    driver.digital_on(0, 0);
    delay(delay_ms);
    driver.turn_off(0, 0);

    driver.digital_on(1, 0);
    driver.digital_on(1, 1);
    driver.digital_on(0, 1);
    delay(delay_ms);
    driver.turn_off(1, 0);
    driver.turn_off(1, 1);
    driver.turn_off(0, 1);

    driver.digital_on(2, 0);
    driver.digital_on(2, 1);
    driver.digital_on(2, 2);
    driver.digital_on(1, 2);
    driver.digital_on(0, 2);
    delay(delay_ms);
    driver.turn_off(2, 0);
    driver.turn_off(2, 1);
    driver.turn_off(2, 2);
    driver.turn_off(1, 2);
    driver.turn_off(0, 2);

    driver.digital_on(3, 0);
    driver.digital_on(3, 1);
    driver.digital_on(3, 2);
    driver.digital_on(3, 3);
    driver.digital_on(2, 3);
    driver.digital_on(1, 3);
    driver.digital_on(0, 3);
    delay(delay_ms);
    driver.turn_off(3, 0);
    driver.turn_off(3, 1);
    driver.turn_off(3, 2);
    driver.turn_off(3, 3);
    driver.turn_off(2, 3);
    driver.turn_off(1, 3);
    driver.turn_off(0, 3);

    driver.digital_on(4, 0);
    driver.digital_on(4, 1);
    driver.digital_on(4, 2);
    driver.digital_on(4, 3);
    delay(delay_ms);
    driver.turn_off(4, 0);
    driver.turn_off(4, 1);
    driver.turn_off(4, 2);
    driver.turn_off(4, 3);
    count++;
  }
}

void rr_fl(MatrixDriver driver, int delay_ms, int times)
{
  int count = 0;
  while(count < times)
  {
    driver.digital_on(4, 0);
    driver.digital_on(4, 1);
    driver.digital_on(4, 2);
    driver.digital_on(4, 3);
    delay(delay_ms);
    driver.turn_off(4, 0);
    driver.turn_off(4, 1);
    driver.turn_off(4, 2);
    driver.turn_off(4, 3);

    driver.digital_on(3, 0);
    driver.digital_on(3, 1);
    driver.digital_on(3, 2);
    driver.digital_on(3, 3);
    driver.digital_on(2, 3);
    driver.digital_on(1, 3);
    driver.digital_on(0, 3);
    delay(delay_ms);
    driver.turn_off(3, 0);
    driver.turn_off(3, 1);
    driver.turn_off(3, 2);
    driver.turn_off(3, 3);
    driver.turn_off(2, 3);
    driver.turn_off(1, 3);
    driver.turn_off(0, 3);

    driver.digital_on(2, 0);
    driver.digital_on(2, 1);
    driver.digital_on(2, 2);
    driver.digital_on(1, 2);
    driver.digital_on(0, 2);
    delay(delay_ms);
    driver.turn_off(2, 0);
    driver.turn_off(2, 1);
    driver.turn_off(2, 2);
    driver.turn_off(1, 2);
    driver.turn_off(0, 2);

    driver.digital_on(1, 0);
    driver.digital_on(1, 1);
    driver.digital_on(0, 1);
    delay(delay_ms);
    driver.turn_off(1, 0);
    driver.turn_off(1, 1);
    driver.turn_off(0, 1);

    driver.digital_on(0, 0);
    delay(delay_ms);
    driver.turn_off(0, 0);

    count++;
  }
}

void grad_fl_rr(MatrixDriver driver, int delay_ms, int times)
{
  int count = 0;

  while(count < times)
  {
    driver.analog_on(0, 0, 20);

    driver.analog_on(1, 0, 40);
    driver.analog_on(1, 1, 40);
    driver.analog_on(0, 1, 40);

    driver.analog_on(2, 0, 60);
    driver.analog_on(2, 1, 60);
    driver.analog_on(2, 2, 60);
    driver.analog_on(1, 2, 60);
    driver.analog_on(0, 2, 60);

    driver.analog_on(3, 0, 80);
    driver.analog_on(3, 1, 80);
    driver.analog_on(3, 2, 80);
    driver.analog_on(3, 3, 80);
    driver.analog_on(2, 3, 80);
    driver.analog_on(1, 3, 80);
    driver.analog_on(0, 3, 80);

    driver.analog_on(4, 0, 100);
    driver.analog_on(4, 1, 100);
    driver.analog_on(4, 2, 100);
    driver.analog_on(4, 3, 100);

    delay(delay_ms);
    count++;
  }
}

void slash(MatrixDriver driver, int delay_ms, int times)
{
  struct Vec pos = {random(0, 4), random(0, 3)};

  int count = 0;
  while(count < times)
  {
    struct Vec target_pos = {random(0, 4), random(0, 3)};

    for(int i = pos.x; i < target_pos.x; i++)
    {
      for(int j = pos.y; i < target_pos.y; j++)
      {
        driver.digital_on(i, j);
        delay(delay_ms);
        driver.turn_off(i, j);
      }
    }
    count++;
    pos.x = target_pos.x;
    pos.y = target_pos.y;
  }
}

void rand_flush(MatrixDriver driver, int delay_ms, int times)
{
  int count = 0;
  while(count < times)
  {
    srand(1);

    int ax = random(0, 5);
    int ay = random(0, 4);

    int bx = random(0, 5);
    int by = random(0, 4);

    driver.digital_on(ax, ay);
    driver.digital_on(bx, by);
    delay(delay_ms);
    driver.turn_off(ax,ay);
    driver.turn_off(bx, by);

    count++;
  }
}

void one(MatrixDriver driver, int delay_ms)
{
  driver.digital_on(2, 0);
  driver.digital_on(2, 0);
  driver.digital_on(2, 0);
  driver.digital_on(2, 0);
}

int random(int min, int max)
{
    return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}
#endif