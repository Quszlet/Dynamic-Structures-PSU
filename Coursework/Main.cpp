#include<iostream>
#include <iomanip>
#include <variant>
#include <chrono>
#include "Time.h"
#include "UserInterface.h"

using namespace std;


int main() {
    setlocale(LC_ALL, "ru");
    UserInterface::StartApp();
    return 0;
}

