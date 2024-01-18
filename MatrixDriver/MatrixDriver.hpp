#ifndef MATRIX_DRIVER_HPP_
#define MATRIX_DRIVER_HPP_

#include "user_config.h"

class MatrixDriver
{
    public:
        // setup pins
        void init_pin();

        // turn off all leds
        void off_all();

        // turn on all leds
        void on_all();

        // turn on(5V) led at (x, y)
        void digital_on(int x, int y);

        // turn on(0~100% power) led at (x,y)
        void analog_on(int x, int y, int power_rate);

        // turn off led at (x,y)
        void turn_off(int x, int y);

    private:
        int row_pin_[ROW_NUM];
        int column_pin_[COLUMN_NUM];
};


#endif