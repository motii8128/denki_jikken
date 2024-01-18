#ifndef MATRIX_DRIVER_HPP_
#define MATRIX_DRIVER_HPP_

#define ROW_0 3
#define ROW_1 5
#define ROW_2 6
#define ROW_3 9

#define COLUMN_0 10
#define COLUMN_1 11
#define COLUMN_2 12
#define COLUMN_3 13
#define COLUMN_4 8

#define INPUT A1

class MatrixDriver
{
    public:
        void init_pin();

        void off_all();
        void on_all();
        
        void digital_on(int x, int y);
        void analog_on(int x, int y, float power_rate);
        void turn_off(int x, int y);

    private:
        int row_pin_[4];
        int column_pin_[5];
        int input_pin;
};


#endif