#include "Resultats.h"

Resultats::Resultats()
{
    // Constructor. Crea tots els gràfics per mostrar el dígits. No s'ha de modificar
    m_digits[0].Create("data/numeros/numero0000.png");
    m_digits[1].Create("data/numeros/numero0001.png");
    m_digits[2].Create("data/numeros/numero0002.png");
    m_digits[3].Create("data/numeros/numero0003.png");
    m_digits[4].Create("data/numeros/numero0004.png");
    m_digits[5].Create("data/numeros/numero0005.png");
    m_digits[6].Create("data/numeros/numero0006.png");
    m_digits[7].Create("data/numeros/numero0007.png");
    m_digits[8].Create("data/numeros/numero0008.png");
    m_digits[9].Create("data/numeros/numero0009.png");
}

Resultats::~Resultats()
{
    // Destructor
}

void Resultats::inicialitzar(const char* rutaResultats)
{
   // TODO
   // Crea el gràfic que s'utilitza per mostrar els resultats a partir de la ruta que es passa com a paràmetre
   m_resultats.Create(rutaResultats);
}

void Resultats::pintaResultats(int nivell, int punts)
{
    // TODO
    // Pinta el grafic de fons dels resultats i mostra el nivell i els punts (que es passen com a paràmetres)
    // utilitzant el mètode escriuNumero
    m_resultats.Draw(POS_RESX,POS_RESY);
    escriuNumero(nivell, POS_NIV_RESX, POS_NIV_RESY, PAS_DIGIT_X);
    escriuNumero(punts, POS_PUNTS_RESX, POS_PUNTS_RESY, PAS_DIGIT_X);
}

void Resultats::escriuDigit(int n, int posX, int posY)
{
    // TODO
    // Escriu un digit a la posicio x,y que es passa com a paràmetre.
    // Els gràfics de cada dígit estan a l''atribut m_digits que s'inicialitza al constructor
     switch(n)
    {
        case 1: {
                    m_digits[1].Draw(posX,posY);
                    break;
        }
        case 2: {
                    m_digits[2].Draw(posX,posY);
                    break;
        }
        case 3: {
                    m_digits[3].Draw(posX,posY);
                    break;
        }
        case 4: {
                    m_digits[4].Draw(posX,posY);
                    break;
        }
        case 5: {
                    m_digits[5].Draw(posX,posY);
                    break;
        }
        case 6: {
                    m_digits[6].Draw(posX,posY);
                    break;
        }
        case 7: {
                    m_digits[7].Draw(posX,posY);
                    break;
        }
        case 8: {
                    m_digits[8].Draw(posX,posY);
                    break;
        }
        case 9: {
                    m_digits[9].Draw(posX,posY);
                    break;
        }
        case 0: {
                    m_digits[0].Draw(posX,posY);
                    break;
        }
    }
}


//Escriu numeros de fins a 3 xifres donant-li el numero i la posiciox i y de les centenes i la
// distancia entre unitats decenes i centenes en l'eix de les x
// No s'ha de modificar
void Resultats::escriuNumero(int n,int posX,int posY,int pasDigit)
{
    int divisor = 100;
    int posXActual = posX;
    int nActual =n;
    bool primerDigit = true;

    while (divisor > 0)
    {
        int d = nActual / divisor;
        nActual = nActual % divisor;
        divisor = divisor / 10;

        if ( (d > 0) || !primerDigit || (divisor == 0) )
        {
            escriuDigit( d , posXActual, posY);
            primerDigit = false;
        }

        posXActual += pasDigit;
    }
}
