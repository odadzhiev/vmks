#include "LiquidCrystal.h"

LiquidCrystal::LiquidCrystal(int rs, int enable, int d4, int d5, int d6, int d7) {}

void LiquidCrystal::begin(int cols, int rows) {
    std::cout << "[LCD] Initialized (" << cols << "x" << rows << ")\n";
}

void LiquidCrystal::setCursor(int col, int row) {
    std::cout << "[LCD] Cursor set to (" << col << "," << row << ")\n";
}

void LiquidCrystal::print(const std::string &text) {
    std::cout << "[LCD] " << text << std::endl;
}

void LiquidCrystal::print(float number) {
    std::cout << "[LCD] " << number << std::endl;
}

void LiquidCrystal::clear() {
    std::cout << "[LCD] Screen cleared\n";
}
