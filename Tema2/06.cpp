#include <iostream>

int main ()
{
    enum class Dias : char { MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};

    struct UnDia {
        unsigned num_dia;
        Dias dia;
    };

    UnDia dos_abril {2, Dias::TUESDAY};
    UnDia uno_abril {1, Dias::MONDAY};

    if (dos_abril.dia == Dias::TUESDAY)
        std::cout << "Hoy es Martes\n";

    if (uno_abril.dia == Dias::MONDAY)
        std::cout << "Hoy es Lunes\n";

    return 0;    

}
