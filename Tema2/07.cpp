#include <iostream>

unsigned operator"" _h(unsigned long long hora){
        return (hora * 3600);
    }

unsigned operator"" _m(unsigned long long minutos){
        return (minutos * 60);
    }

unsigned operator"" _s(unsigned long long segundos){
        return (segundos);
    }

int main ()
{

    // time contains number of seconds.
    unsigned time = 1_h + 15_m + 30_s;

    std::cout << time << "\n";

    return 0;
}
