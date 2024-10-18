#include <fmt/chrono.h>
#include <fmt/format.h>

/*BSS Segment*/
int foo;

/*Konstante Daten .rodata Segment*/
const int rodata = 45;

void doSomething(int value){
    value = value + 1;
    fmt::print("doSomething, value {}\n", value);
}

void doSomethingPTR(int* ptr){
    *ptr = *ptr + 1;
    fmt::print("doSomething, value {}\n", *ptr);
}

int* doReturnAPTR() {
    int value = 4711;
    fmt::print("doReturnAPTR, value {}\n", value);  // Klammerfehlstellung korrigiert
    return &value;  // Vorsicht: Rückgabe eines Zeigers auf eine lokale Variable führt zu undefiniertem Verhalten
}

auto main(int argc, char **argv) -> int
{
  
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", argv[0]);
    fmt::print("Value of foo {} address of foo {}\n", foo, fmt::ptr(&foo));
    /*Data Segment (initialisierte Daten)*/
    int bar = 42;
    doSomething(bar);
    fmt::print("The value of bar is: {}\n", bar);
    doSomethingPTR(&bar);
    fmt::print("The value of bar is: {}\n", bar);

    int* returnedPTR = doReturnAPTR();

    fmt::print("The value of the returned PTR is : {}\n", *returnedPTR);

    return 0; /* exit gracefully*/
}
