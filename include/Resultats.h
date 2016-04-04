#ifndef RESULTATS_H
#define RESULTATS_H

#include "../lib/libreria.h"

// Posici� de la graella per nostrar puntuacio i nivell;
const int POS_RESX = 350;
const int POS_RESY = 325;

// Posicio de les centenes dels punts i del pas d'una unitat a una altre.
const int POS_PUNTS_RESX = 530;
const int POS_PUNTS_RESY = 460;
const int PAS_DIGIT_X = 20;

// Posicio del nivell
const int POS_NIV_RESX = 530;
const int POS_NIV_RESY = 405;

class Resultats
{
    public:
        Resultats();
        virtual ~Resultats();
        void inicialitzar(const char*);
        void pintaResultats(int , int);

    protected:
    private:
        Sprite m_resultats;
        Sprite m_digits[10];
        void escriuDigit(int , int , int );
        void escriuNumero(int ,int ,int ,int );
};

#endif // RESULTATS_H
