#include <stdlib.h>
#include <stdio.h>
#include "lendlib.h"
#include "lendlibout.h"
#include "lendlibin.h"
#include "lendlibitem.h"

/**
 * @ingroup LendLib
 * @brief Die Main-Funktion.
 */
int main(int argc, char* argv[]){
#ifndef CGI
	prepareOut();	///- Ausgabevariablen vorbereiten
#else 
	printf("Content-Type: text/html");
	printf("\n\n")  ;
#endif
	printHead();	///- Kopfzeilen ausgeben
	readfile();	///- Einträge aus Datei einlesen (falls sie existiert)
#ifdef CGI	/// CGI-Ausgabe:
	getPost();		///- HTML Anweisunf verarbeiten
	printHTMLInter();	///- Interface ausgeben
#else	/// Terminalausgabe:
	printItems();	///- aus Datei erhaltene Medien anzeigen
	getInput();		///- Nutzerinput verarbeiten
#endif	/// beide:	
	saveDBtoFile();		///- Daten in Datei speichern
	printFoot();	///- Fußzeilen ausgeben
	freeAll(&myLib);	///- Speicher freigeben
	return 0;
}