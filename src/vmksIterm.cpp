#include "LiquidCrystal.h"
#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <thread>   
#include <chrono>   

using namespace std;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float a, previousTemp;

void pinMode(int pin, int mode) {
    cout << "[PIN] Pin " << pin << " set to " << (mode ? "OUTPUT" : "INPUT") << endl;
}

void digitalWrite(int pin, bool state) {
    cout << "[PIN] Pin " << pin << " set to " << (state ? "HIGH" : "LOW") << endl;
}

float analogRead(int pin) {
    return static_cast<float>(rand() % 1024);
}

void delay(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

int main() {
    srand(time(NULL));
    
    lcd.begin(16, 2);
    pinMode(6, 1);
    previousTemp = -999;

    while (true) {
        a = analogRead(1);
        a = a * 0.0048828125;
        a = (a - 0.5) * 100;

        if (a != previousTemp) {
            lcd.setCursor(0, 0);
            lcd.print("Temp: ");
            lcd.print(a);
            lcd.print(" C   "); 
            previousTemp = a;
        }

        if (a > 70 || a < 0) {
            digitalWrite(6, true);
        } else {
            digitalWrite(6, false);
        }

        delay(1000);
    }

    return 0;
}
