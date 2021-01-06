Moody Plant

Die Mozzi Dateien wurden überarbeitet weil sie in einer anderen IDE nicht funktioniert haben... es sollten aber auch mit den normalen mozzi files alles gut gehen.
Die TrueRMS library muss allerdings eingebunden werden!


Der code wurde ursprünglich mit "PURR data" (=neues Pd extended) z erstellt. 
Ich habe ihn angepasst, dass er auch auch mit vanilla funktionieren sollte, aber man muss die libraries  'comport',  'zexy' und 'cyclone' installiert haben 
(Pd-->hilfe-->finde externals online--> diese libraries suchen und installieren)

alternativ Purr data downloaden:     https://github.com/agraef/purr-data/releases


Bedienung Pd GUI:

zum starten des programms, muss 'main.pd' geöffnet werden. der richtige port muss ausgewählt werden (muss gegebenenfalls geändert werden, standard ist port 5 weil ich dort meinen arduino anstecke). Den richtigen port kann man am besten über die arduino IDE finden(?).

ein kleiner bug ist, dass man zuerst die arduino IDE öffnen muss und den serial monitor (Tools-->serial monitor) öffnen muss (hier sollten regelmäßig werte (0-1024) mit prefix (zB "A") ausgegeben werden)

wenn diese werte ausgegeben werden, kann der serial monitor geschlossen werden und in Pd der port geöffnet werden ('open port' klicken).



der input pin für das signal von der pflanze ist pin A0 der 
der output pin für das 100Hz Signal ist pin 3 (nicht analog 3)

die schaltung sieht folgendermaßen aus:

                                         ________[analog input 0]	
[pin3]_______[10megaOhm Widerstand]_____|
                                        |________[Erde Blumentopf = kapazität]


(es gibt auch die möglichkeit in Pd um über einen output pin LEDs anzusteuern wenn die pflanze "spricht").