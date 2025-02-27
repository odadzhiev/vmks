#ifndef LIQUIDCRYSTAL_H
#define LIQUIDCRYSTAL_H

#include <iostream>
#include <string>

class LiquidCrystal {
public:
    LiquidCrystal(int rs, int enable, int d4, int d5, int d6, int d7);
    void begin(int cols, int rows);
    void setCursor(int col, int row);
    void print(const std::string &text);
    void print(float number);
    void clear();
};

#endif
