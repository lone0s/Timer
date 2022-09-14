#include <iostream>
#include "chrono.h"
#include "../Logger/Logger.h"


int main() {
    Chrono chrono = Chrono();
    for (int h = 0 ; h < 3 ; h++)
    {
        for (int i = 0; i < 10; i++) {
            double a = 1;
            int num1 = 0;
            int num2 = 1;
            int num_temp;
            int num_next = 1;
            int n = 1000;
            chrono.start();
//    std::cin >> n;
            if (n >= 1)
                std::cout << 0 << " ";
            if (n >= 2)
                std::cout << 1 << " ";
            for (int i = 0; i < n - 2; i++) {
                num_next = num1 + num2;
                std::cout << num_next << " ";
                num1 = num2;
                num2 = num_next;
            }
            std::cout << std::endl;
            chrono.end();
            Logger logger = Logger("cptLog", 0, false, "");
            logger.log("V" + std::to_string(h) + "  " "iteration: " + std::to_string(i) + " - " + chrono.howMuchTimePassed(), 2);
        }
    }
    return 0;
}
