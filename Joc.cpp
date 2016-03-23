
#include "Joc.h"
#include "../lib/libreria.h"
#include <cstdlib>

#include "Resultats.h"


int llegirEvent()
{
    int tecla;

    if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
        tecla = TECLA_ESQUERRA;
    else
        if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
            tecla = TECLA_DRETA;
        else
            if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
                tecla = TECLA_ABAIX;
            else
                if (Keyboard_GetKeyTrg(KEYBOARD_ESCAPE))
                    tecla = TECLA_ESC;
    return tecla;
}

int aleatori(int min, int max)
{
	int aleatori = rand() % (max - min + 1) + min;
	return aleatori;
}

void tractarEvent(int tecla, FigTetris& fig, Fons& fons)
{
	// TODO
	// Adaptar el mateix tractament de cada possible event (tecla) que vau fer a la sessió 1, modificant el codi per
	// utilitzar els mètodes de les classes FigTetris i Fons
	switch(tecla)
	{
		case TECLA_ESQUERRA:
                fig.moureFig(-MIDA_Q, 0, fons);
			break;
		case TECLA_DRETA:
				fig.moureFig(MIDA_Q, 0, fons);
			break;
		case TECLA_ABAIX:
                fig.moureFig(0, 2 * MIDA_Q, fons);
			break;
		default: break;
	}
}

void crearFigTetris(FigTetris* figTetrisActual)
{
    // TODO
    // Heu de crear totes les figures del tetris utilitzant el mètode create de la classe FigTetris i guardar cadascuna de les figures
    // en una de les posicions de l'array de figures que es passa com a paràmetre
    for(int i = 0; i < MAX_FIG; i++)
    {
        figTetrisActual[i].create(i);
    }
}

int joc(int nivell)
{
    // TODO
    // Definicions i Inicialitzacions necessàries per utilitzar la llibreria gràfica
    // Ha de ser el mateix codi que teniu a la versió de la primera sessió
    Game joc;
    joc.Init();
    // TODO
    // Definicions dels objectes del fons i resultats
    Resultats resultats;
    Fons fons;

	// Declaracions de variables. No s'han de modificar
    int tecla = 0; // Valor de la tecla pressionada en cada iteració del joc
    bool metaAconseguida; // Indica si la figura ha arribat a la última línia del taules
    bool finalTemps; // Indica si se'ns ha acabat el temps per completar la última línia del tauler
	int velocitatJoc = 80; // Indica velocitat del joc, quantes més linies es fan més ràpida és
	int contVPeca; // Comptador per controlar la velocitat
	int vides = 3; // Nº de vides
	int punts = 0; // Punts
	int diffT = 0; // Control del temps del joc
	time_t now;

    //Inizialitzar llavor per a la funció rand()
	srand((unsigned)time(NULL));
	// Inicialtizar variable per control del temps
    now = time(NULL);

    // TODO
    // Inicialitzar els gràfics del fons i resultat cridant als mètodes Inicialitzar de les classes fons i resultat
    // per al fons "data/GraficsTetris/fons.png");
    // per el resultat "data/GraficsTetris/Resultats.png"
    resultats.inicialitzar("data/GraficsTetris/fons.png");
    fons.inicialitzar("data/GraficsTetris/Resultats.png");
   	// TODO
   	// Mostrem la finestra del joc com a la sesio 1
    joc.Video_ShowWindow();

    // TODO
    // Declaració d'un array per guardar totes les figures del tetris.
    // Inicialitza els gràfics de totes les figures de l'array amb la funció CrearFigTetris
    FigTetris figures[MAX_COLORS];
    for(int i = 0; i < MAX_COLORS; i++)
    {
        figures[i].create(i);
    }


	do
    {
        // Definició i inicialització aleatoria de la figura del tetris
        int indexFig  = aleatori(INI_FIG, FI_FIG);


        // TODO
        // Inicialitzacio de la posicio de la figura que s'ha generat aleatòriament utilitzant els mètodes setPosX i setPosY de la figura que
        // ocupa la posició indexFig dins de l'array de figures
        // La posició x vindria donada per ( (INICI_X) + ( ( rand() % ( ( (FI_X - INICI_X - (amplada en quadres figura actual * MIDA_Q)) / MIDA_Q ) + 1 ) ) * MIDA_Q ));
        // La posició y per (INICI_Y);
        figures[indexFig].setPosX(( (INICI_X) + ( ( rand() % ( ( (FI_X - INICI_X - figures[indexFig].amplada()) * MIDA_Q)) / MIDA_Q ) + 1 ) ) * MIDA_Q );
        figures[indexFig].setPosY(INICI_Y);
        // Inicialitzar variables que controlen si s'ha omplert la última línia i la velocitat del joc
        metaAconseguida = false;
        finalTemps = false;
        contVPeca = velocitatJoc / nivell;
        now = time(NULL);


        // TODO
        // Dibuixar el fons, els resultats, la figura actual (cridant els mètodes corresponents de cada objecte) i refrescar pantalla (com a la primera sessió)
        fons.pintaFons();
        resultats.pintaResultats(nivell, punts);
        figures[indexFig].draw();
        joc.VideoUpdate();

        do
        {
           // TODO
           // Permetre que es processin els events com a la sesio 1, llegir event i tractar event, igual que es fa a la primera sessió
            joc.ProcessEvents();
            tecla = llegirEvent();
            tractarEvent(tecla,figures[indexFig],fons);

            // Moviment de la figura segons la velocitat del joc
            contVPeca--;
            if(contVPeca == 0)
            {
                // TODO
                // Moure la figura una posicions cap avall i verificar si hem arribat a la última línia del tauler actualitzant
                // metaAconseguida a true si és així i les posicions corresponent de la última línia del tauler ams els colors de la figura
                // Això s'ha de fer cridant al mètode moureFig de la classe FigTetris.
                int dirX, dirY;
                figures[indexFig].moureFig(dirX, dirY, fons);

                contVPeca = velocitatJoc / nivell; // reinicialització comptador de velocitat
            }

            // TODO
            // Dibuixar el fons, els resultats, la figura actual (cridant els mètodes corresponents de cada objecte)
            fons.pintaFons();
            resultats.pintaResultats(nivell,punts);
            figures[indexFig].draw();

			// TODO
			// Actualitza la pantalla com a sesio 1.
            // COMMMMMMM?????????

            // Mira el temps que ha trigat
            diffT = difftime(time(NULL),  now);
            // Mira si triga molt i si ho fa perd una vida
            if(diffT > (TEMPS_PERDUA / nivell))
            {
                finalTemps = true;

                // TODO
                // Reinicialitzar el fons a negre (mètode posarNegre de la classe Fons)
                fons.posarNegre();

                // Decrementem nº de vides
                vides--;
                // Reinicialitzem control del temps
                now = time(NULL);
            }


            // TODO Mira si ha fet una linia
            if(fons.guanyar() /* TODO aqui hem de cridar al mètode guanyar de la classe Fons per saber si hem aconseguit fer una linia*/)
            {
                metaAconseguida = true;

                // TODO
                // Reinicialitzar el fons a negre (mètode posarNegre de la classe Fons)
                fons.posarNegre();

                // Incrementem puntuació i nivell
                punts += 1*nivell;
                nivell++;
                // Reinicialitzem control del temps
                now = time(NULL);

            }

        }while((tecla != TECLA_ESC) && (!metaAconseguida) && (!finalTemps) && (vides>0));

	}while((nivell<4) && (vides>0) && (tecla != TECLA_ESC));


	return punts;
}
