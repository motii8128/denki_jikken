#ifndef MATRIX_DRIVER_HPP_
#define MATRIX_DRIVER_HPP_

#include "user_config.h"

class MatrixDriver
{
    public:
        void init_pin();

        void off_all();
        void on_all();
        
        void digital_on(int x, int y);
        void analog_on(int x, int y, int power_rate);
        void turn_off(int x, int y);

    private:
        int row_pin_[4];
        int column_pin_[5];
        int input_pin;
};


#endif