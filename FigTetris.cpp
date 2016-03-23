#include "FigTetris.h"

FigTetris::FigTetris()
{
    // Constructor. No s'ha de modificar
}

FigTetris::~FigTetris()
{
    // Destructor. No s'ha de modificar
}

void FigTetris::setPosX(int posX)
{
    // TODO
    // Heu de modificar el valor de l'atribut m_posX (posició x de la figura) amb el valor posX que es passa com a paràmetre
    m_posX = posX;
}

void FigTetris::setPosY(int posY)
{
    // TODO
    // Heu de modificar el valor de l'atribut m_posY (posició y de la figura) amb el valor posY que es passa com a paràmetre
    m_posY = posY;
}

void FigTetris::draw()
{
    // TODO
    // Heu de dibuixar el gràfic de la figura del tetris a la posicio m_posX, m_posY


}

void FigTetris::create(int indexFig)
{
    // TODO
    // Heu de crear una de les figures del tetris en funció de l'índex que es passa com a paràmetre
    // A continuació teniu el gràfic que heu d'utilitzar per cada possible valor de indexFig
    // I: ("data/Graficstetris/palblaucel1.png")
    // O:("data/Graficstetris/q4groc1.png")
    // T:("data/Graficstetris/tmagenta2.png")
    // L:("data/Graficstetris/ltaronja2.png")
    // P:("data/Graficstetris/pblaufosc4.png")
    // S:("data/Graficstetris/sverd1.png")
    // Z:("data/Graficstetris/zroig1.png")
    // Per cada figura, a més a més de crear el gràfic heu d'inicialitzar la resta dels atributs de la classe (amplada, alçada, index i color)
     switch(indexFig)
     {
        case I:
            m_figura.Create("data/Graficstetris/palblaucel1.png");
            m_alcada = 3;
            m_amplada = 1;
            m_indexFig = I;
            m_color = COLOR_BLAUCEL;
            break;
        case O:
            m_figura.Create("data/Graficstetris/q4groc1.png");
            m_alcada = 2;
            m_amplada = 2;
            m_indexFig = O;
            m_color = COLOR_GROC;
            break;
        case T:
            m_figura.Create("data/Graficstetris/tmagenta2.png");
            m_alcada = 2;
            m_amplada = 3;
            m_indexFig = T;
            m_color = COLOR_MAGENTA;
            break;
        case L:
            m_figura.Create("data/Graficstetris/ltaronja2.png");
            m_alcada = 2;
            m_amplada = 3;
            m_indexFig = L;
            m_color = COLOR_TARONJA;
            break;
        case P:
            m_figura.Create("data/Graficstetris/pblaufosc4.png");
            m_alcada = 2;
            m_amplada = 3;
            m_indexFig = P;
            m_color = COLOR_BLAUFOSC;
            break;
        case S:
            m_figura.Create("data/Graficstetris/sverd1.png");
            m_alcada = 2;
            m_amplada = 4;
            m_indexFig = S;
            m_color = COLOR_VERD;
            break;
        case Z:
            m_figura.Create("data/Graficstetris/zroig1.png");
            m_alcada = 2;
            m_amplada = 4;
            m_indexFig = Z;
            m_color = COLOR_ROIG;
            break;

     }
}

int FigTetris::amplada()
{
    // TODO
    // Retorna l'amplada de la figura
    return m_amplada;
}

int FigTetris::alcada()
{
    // TODO
    // Retorna l'alçada de la figura
    return m_alcada;
}

bool FigTetris::moureFig(int dirX, int dirY, Fons& fons)
{
    bool espot;
    // TODO:
    // Heu d'analitzar si es pot fer el moviment indicat a dirX i dirY en funció de l'estat del fons i de la posició actual de la figura.
    // Si el moviment és possible, haure de modificar com correspongui el valor dels atributs m_posX i m_posY per actualitzar la posició
    // de la figura d'acord al moviment indicat. La funció ha de retornar true si la figura ha arribat a l'última línia del tauler

    // Els valors de dirX i dirY que indiquen el moviment poden ser de moment:
    // -1, 0: moviment a l'esquerra. Aqui sempre retornem fals.
    // 1, 0: moviment a la dreta. Aqui sempre retornem fals.
    // 0, 1: moviment a baix. Aqui a més hem de veure si ja hem arribat a baix de tot. Si hem arribat retornarem true,
    //       i actualitzarem la última línia del tauler del fons amb els quadres del color de la figura actual.
    // 0, 2: moviment a baix de dues posicions. Aqui a més hem de veure si ja hem arribat a baix de tot. Si hem arribat retornarem true,
    //       i actualitzarem la última línia del tauler del fons amb els quadres del color de la figura actual.
    if(dirX == 0)
    {
        if(dirY == 1)
            {
                m_posY++;

            }
        else
            if(dirY == 2)
            {
                m_posY = m_posY + 2;
            }
        if(m_posY == FI_Y)
        {
            espot = true;
            fons.pintaFons();

        }
    }
    else
        if(dirY == 0)
        {
            if(dirX == -1)
                dirX--;
            else
                if(dirX == 1)
                    dirX++;
            espot = false;
        }
        return espot;

}

void FigTetris::figuraEncaixada(Fons& fons)
{
	// TODO:
	// Aquest mètode s'ha de cridar quan la figura arriba a baix de tot.
	// Modifica els quadres corresponents a l'amplada de la figura actual a les posicions de la última línia del tauler el fons amb els colors de la figura actual
	for(int i = 0; i < amplada(); i++)
    {
        fons.pintaFons();
    }
}
