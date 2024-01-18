#include "MatrixDriver.hpp"


MatrixDriver driver;

void setup()
{
  driver.init_pin();
  driver.off_all();
}

void loop()
{
  test(500);
}

void test(int delay_ms)
{
  driver.on_all();
  delay(delay_ms);
  driver.off_all();
  delay(delay_ms);
}