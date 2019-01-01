#include <utility>
#include <iostream>

const unsigned MAX = 10;

class Vector2
{
    int * v[MAX];
    unsigned tam;
    
    public:
        Vector2 (unsigned t)
        {
            tam = t;
            for (unsigned i = 0; i < MAX; i++)
            {
                v[i] = new int[tam];
            }
        }

        Vector2 (Vector2 &&ve)
        {
            tam = ve.tam;
            
            for (unsigned i = 0; i < MAX; i++)
            {
                v[i] = ve.v[i];
                ve.v[i] = nullptr;
            }
        }

        Vector2 & operator= (Vector2 &&ve)
        {
            tam = ve.tam;

            for (unsigned i = 0; i < MAX; i++)
            {
                delete v[i];
                v[i] = ve.v[i];
                ve.v[i] = nullptr;
            }

            return *this;
        }
            
};

int main ()
{
    Vector2 v1(5);
    Vector2 v2(5);

    v2 = std::move(v1);

    return 0;
} 
