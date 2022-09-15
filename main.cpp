#include <iostream>
#include <cstring>
#include "chrono.h"
#include "../Logger/Logger.h"

void fibonnaci(int iterations) {
    int n = 0;
    long last1, last2, mem;
    if(iterations >= 0) {
        while (n <= iterations) {
            if (n == 0) {
                last2 = 0;
                std::cout << "[ " << last2 << " ] ";
                n++;
            } else if (n == 1) {
                last1 = 1;
                std::cout << "[ " << last1 << " ] ";
                n++;
            } else {
                mem = last1;
                last1 = last1 + last2;
                last2 = mem;
                n++;
                std::cout << "[ " << last1 << " ] ";
            }
        }
        std::cout << std::endl;
    }
}

void factorial(int n) {
    int iter = 1;
    long res = 1;
    if (n >= 0) {
        if (n == 0) {
            res = 0;
            std::cout << "[ " << res << " ] ";
        }
        else {
            while (iter <= n) {
                res *= iter;
                std::cout << "[ " << res << " ] ";
                iter++;
            }
        }
        std::cout << std::endl;
    }
}

bool isFuncName(const std::string &name) {
    return (name == "fibonnaci" || name == "factorial");
}


int main(int argc,char* argv[]) {
    /*
     * Arguments necessaires : - nom de la fonction voulue |fibo |fact
     *                         - nombre d'itérations voulue
     *                         - eventuellement si on veut l'horodatage ? [Facultatif]
     */
    if (argc == 3) {
        if (isFuncName(argv[1])) {
            long iter = std::strtol(argv[2], nullptr,10); //error: returns LONG_MAX//LONG_MIN//ERANGE
            Logger logger = Logger(argv[1],0,true,R"(E:\ohno\Documents\C++\TPs\TP1\Chrono\runtime.txt)");
            Chrono timer = Chrono();

            if (iter) {
                if (std::strcmp(argv[1],"fibonnaci") == 0) {
                    timer.start();
                    fibonnaci(iter);
                    timer.end();
                    std::cout << timer.howMuchTimePassed() << std::endl;
                    logger.log(timer.howMuchTimePassed(), 0);
                }
                else {
                    timer.start();
                    factorial(iter);
                    timer.end();
                    std::cout << timer.howMuchTimePassed() << std::endl;
                    logger.log(timer.howMuchTimePassed(), 0);
                }
            } else
                std::cerr << "2nd argument for the n-value isn't a decimal value" << std::endl;
        } else
            std::cerr << "Program needs 2 arguments: <function name> <n-value>"
                         "\n<Func names> : [fibonnaci] [factorial]"
                         "\n<n-value> : only integer value" << std::endl;
    }
}
