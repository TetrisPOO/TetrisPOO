#include "Fons.h"

Fons::Fons()
{
    // Constructor. No s'ha de modificar.
    // Crea els gr�fics que s'utilitzaran per dibuixar els quadrats de colors al tauler a mesura que les figures vagin arribant a baix de tot
    m_quadrats[COLOR_GROC].Create("data/Graficstetris/q1groc.png");
    m_quadrats[COLOR_TARONJA].Create("data/Graficstetris/q1taronja.png");
    m_quadrats[COLOR_ROIG].Create("data/Graficstetris/q1roig.png");
    m_quadrats[COLOR_MAGENTA].Create("data/Graficstetris/q1magenta.png");
    m_quadrats[COLOR_VERD].Create("data/Graficstetris/q1verd.png");
    m_quadrats[COLOR_BLAUCEL].Create("data/Graficstetris/q1blaucel.png");
    m_quadrats[COLOR_BLAUFOSC].Create("data/Graficstetris/q1blaufosc.png");
}

Fons::~Fons()
{
    // Destructor. No s'ha de modificar
}

void Fons::inicialitzar(const char *rutaFons)
{
    // TODO
    // Heu de crear l'Sprite amb el dibuix del fons del tauler
    m_fons.Create(rutaFons);
    // Tamb� heu d'inicialitzar totes les posicions de la matriu m_tauler  a color negre, excepte la primera i ultima columna
    // i la �ltima fila que s'han d'inicialitzar a gris. D'aquesta manera marquem que tot el tauler est� buit. Per fer-ho podeu utilitzar
    // els m�todes posarNegre() i posarGris()
    posarNegre();
    posarGris();
}
void Fons::posarNegre()
{
    // TODO
    // Heu d'inicialitzar totes les posicions interiors (que no s�n l�mits) de la matriu m_tauler a negre
    for(int i = 0; i <  MAX_FILA; i++)
    {
        for(int j = 1; j < MAX_COL; j++)
            m_tauler[i][j] = COLOR_NEGRE;
    }

}

void Fons::posarGris()
{
    // TODO
    // Heu d'inicialitzar primera i ultima columnes de la matriu m_tauler a gris
    // Heu d'inicialitzar la �ltima fila de la matriu m_tauler a gris
    for(int i = 0 ; i < MAX_FILA; i++)
    {
        m_tauler[i][0] = COLOR_GRIS;
        m_tauler[i][MAX_COL-1] = COLOR_GRIS;
    }

    for(int i = 0; i <= MAX_COL; i++)
    {
        m_tauler[MAX_FILA - 1][i] = COLOR_GRIS;
    }
}

void Fons::pintaFons()
{
    // TODO:
    // Heu de pintar tots els quadres del fons del tauler que no s�n negres i que per tant corresponen a figures que ja s'han col�locat al tauler.
    // De moment, tots els quadres de color (no negres) estaran a l'�litima l�nia del tauler
    // Recordeu que els quadres grisos del tauler ja estan pintats a la imatge del fons i no els heu de tornar a dibuixar.
    /*m_fons.Draw(0,0);
    int color;

    for(int i = 1; i < MAX_COL; i++)
    {
        color = m_tauler[i][MAX_FILA - 1];
        m_quadrats[color].Draw(i * MIDA_Q, FI_Y - MIDA_Q);
    }*/
    m_fons.Draw(0,0);
    for(int i = 1; i < MAX_COL; i++)
    {
        switch(m_tauler[i][MAX_FILA - 1])
        {
            case COLOR_GROC:
                m_quadrats[COLOR_GROC].Draw(i * MIDA_Q, FI_Y - MIDA_Q);
                break;
            case COLOR_TARONJA:
                m_quadrats[COLOR_TARONJA].Draw(i * MIDA_Q, FI_Y - MIDA_Q);
                break;
            case COLOR_ROIG:
                m_quadrats[COLOR_ROIG].Draw(i * MIDA_Q, FI_Y - MIDA_Q);
                break;
            case COLOR_MAGENTA:
                m_quadrats[COLOR_MAGENTA].Draw(i * MIDA_Q, FI_Y - MIDA_Q);
                break;
            case COLOR_VERD:
                m_quadrats[COLOR_VERD].Draw(i * MIDA_Q, FI_Y - MIDA_Q);
                break;
            case COLOR_BLAUCEL:
                m_quadrats[COLOR_BLAUCEL].Draw(i * MIDA_Q, FI_Y - MIDA_Q);
                break;
            case COLOR_BLAUFOSC:
                m_quadrats[COLOR_BLAUFOSC].Draw(i * MIDA_Q, FI_Y - MIDA_Q);
                break;
        }
    }
}


void Fons::setTauler(int fila, int columna, int color)
{
    // TODO
    // Heu de modificar el valor de color de la posici� fila, columna del tauler (valor de la matriu m_tauler) amb el color que es passa com a par�metre.
    m_tauler[fila][columna] = color;

}


bool Fons::guanyar()
{
	// TODO
	// Heu de retornar cert si la �ltima l�nia del tauler que no est� gris est� tota pintada de colors
	// i fals si hi ha algun quadre a negre.
	bool totPintat = true;
	int  i = 1;
    while(totPintat && (i < (MAX_COL - 1)))
    {

          if(m_tauler[i][MAX_FILA - 1] == COLOR_NEGRE)
            {
                totPintat = false;
            }
            i++;
    }


    return totPintat;
}
