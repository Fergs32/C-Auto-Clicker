#include <iostream> 
#include <vector> 
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <Windows.h> 
#include <chrono>
#include <psapi.h>
#include <stdio.h>

class TextAttr {
    friend std::ostream& operator<<(std::ostream& out, TextAttr attr)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attr.value);
        return out;
    }
public:
    explicit TextAttr(WORD attributes): value(attributes) {}
private:
    WORD value;
};