#include "Fons.h"

Fons::Fons()
{
    // Constructor. No s'ha de modificar.
    // Crea els gràfics que s'utilitzaran per dibuixar els quadrats de colors al tauler a mesura que les figures vagin arribant a baix de tot
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
    // També heu d'inicialitzar totes les posicions de la matriu m_tauler  a color negre, excepte la primera i ultima columna
    // i la última fila que s'han d'inicialitzar a gris. D'aquesta manera marquem que tot el tauler està buit. Per fer-ho podeu utilitzar
    // els mètodes posarNegre() i posarGris()
    posarNegre();
    posarGris();
}
void Fons::posarNegre()
{
    // TODO
    // Heu d'inicialitzar totes les posicions interiors (que no són límits) de la matriu m_tauler a negre
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
    // Heu d'inicialitzar la última fila de la matriu m_tauler a gris
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
    // Heu de pintar tots els quadres del fons del tauler que no són negres i que per tant corresponen a figures que ja s'han col·locat al tauler.
    // De moment, tots els quadres de color (no negres) estaran a l'úlitima línia del tauler
    // Recordeu que els quadres grisos del tauler ja estan pintats a la imatge del fons i no els heu de tornar a dibuixar.
    m_fons.Draw(0,0);
    for(int j = 1; j < MAX_COL; j++)
    {
        switch(m_tauler[MAX_FILA - 1][j])
        {
            case COLOR_GROC:
                m_quadrats[COLOR_GROC].Draw((MAX_FILA - 1) * MIDA_Q, j * MIDA_Q);
                break;
            case COLOR_TARONJA:
                m_quadrats[COLOR_TARONJA].Draw((MAX_FILA - 1) * MIDA_Q, j * MIDA_Q);
                break;
            case COLOR_ROIG:
                m_quadrats[COLOR_ROIG].Draw((MAX_FILA - 1) * MIDA_Q, j * MIDA_Q);
                break;
            case COLOR_MAGENTA:
                m_quadrats[COLOR_MAGENTA].Draw((MAX_FILA - 1) * MIDA_Q, j * MIDA_Q);
                break;
            case COLOR_VERD:
                m_quadrats[COLOR_VERD].Draw((MAX_FILA - 1) * MIDA_Q, j * MIDA_Q);
                break;
            case COLOR_BLAUCEL:
                m_quadrats[COLOR_BLAUCEL].Draw((MAX_FILA - 1) * MIDA_Q, j * MIDA_Q);
                break;
            case COLOR_BLAUFOSC:
                m_quadrats[COLOR_BLAUFOSC].Draw((MAX_FILA - 1) * MIDA_Q, j * MIDA_Q);
                break;

        }
    }


}

void Fons::setTauler(int fila, int columna, int color)
{
    // TODO
    // Heu de modificar el valor de color de la posició fila, columna del tauler (valor de la matriu m_tauler) amb el color que es passa com a paràmetre.
    m_tauler[fila][columna] = color;

}


bool Fons::guanyar()
{
	// TODO
	// Heu de retornar cert si la última línia del tauler que no està gris està tota pintada de colors
	// i fals si hi ha algun quadre a negre.
	bool totPintat = true;
	int  j = 0;

	while(totPintat && (j < MAX_COL))
    {
        if(m_tauler[MAX_FILA - 1][j] == COLOR_NEGRE)
            totPintat = false;

        j++;
    }
    return totPintat;
}
