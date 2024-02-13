#include "MatrixDriver.hpp"
#include "Func.hpp"
#include <time.h>

#include <stdlib.h>

MatrixDriver driver;
int count = 0;

void setup()
{
  driver.init_pin();
  driver.off_all();
  Serial.begin(115200);

  
}

void loop()
{
  // all_flush(driver,10);
  // vertical_snake(driver,10, 10);
  // grad(driver,10, 1000);
  // grad_updown(driver, 10, 1000);
  // grad_downup(driver,10, 1000);
  cycron(driver, 10, 5);
  // fl_rr(driver, 10, 5);
  // rr_fl(driver, 10, 5);
  // rand_flush(driver, 10, 10);
}

void select_func(int value)
{
  switch(value)
  {
    case 0:
      all_flush(driver,50);
      break;

    case 1:
      vertical_snake(driver,50, 1);
      break;

    case 2:
      grad(driver,50, 100);
      break;


    case 3:
      grad_updown(driver,50, 100);
      break;

    case 4:
      grad_downup(driver,50, 100);
      break;

    case 5:
      cycron(driver, 50, 5);
      break;
      
    case 6:
      fl_rr(driver, 50, 5);
      break;

    case 7:
      rr_fl(driver, 50, 5);
      break;

    case 8:
      rand_flush(driver, 50, 5);
      break;

    default:
      break;
  }
}