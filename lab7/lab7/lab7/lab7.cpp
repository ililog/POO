#include<iostream>

float operator"" _Kelvin(unsigned long long k) {
    return static_cast<float>(k - 273.15);
}
float operator"" _Kelvin(long double k) {
    return static_cast<float>(k - 273.15);
}

float operator"" _Fahrenheit(unsigned long long f) {
    return static_cast<float>((f - 32.0) * 5.0 / 9.0);
}

float operator"" _Fahrenheit(long double f) {
    return static_cast<float>((f - 32.0) * 5.0 / 9.0);
}

//static_cast ---> intre tipuri de date related (int, float, char, bool)
//dynamic_cast --> downcasting. pointer parinte -> pointer copil
//const_cast ----> intre o variabila const si o variabila care nu e const
//reinterpret_cast -> intre orice si orice

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    std::cout << "300 Kelvin = " << a << " Celsius\n";
    std::cout << "120 Fahrenheit = " << b << " Celsius\n";

    return 0;
}
