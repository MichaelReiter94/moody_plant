Moody Plant

Die Mozzi Dateien wurden überarbeitet weil sie in einer anderen IDE nicht funktioniert haben... es sollten aber auch mit den normalen mozzi files alles gut gehen.
Die TrueRMS library muss allerdings eingebunden werden!


Der code wurde ursprünglich mit "PURR data" (=neues Pd extended) z erstellt. 
Ich habe ihn angepasst, dass er auch auch mit vanilla funktionieren sollte, aber man muss die libraries  'comport',  'zexy' und 'cyclone' installiert haben 
(Pd-->hilfe-->finde externals online--> diese libraries suchen und installieren)

alternativ Purr data downloaden:     https://github.com/agraef/purr-data/releases



der arduino code ist zum einlesen des ersten analog inputs und zum weiterleiten über den serial output.

zum starten des programms, muss 'main.pd' geöffnet werden. der richtige port muss ausgewählt werden (muss gegebenenfalls geändert werden, standard ist port 5 weil ich dort meinen arduino anstecke). Den richtigen port kann man am besten über die arduino IDE finden(?).

ein kleiner bug ist, dass man zuerst die arduino IDE öffnen muss und den serial monitor (Tools-->serial monitor) öffnen muss (hier sollten im 10ms takt werte ausgegeben werden)

wenn diese werte ausgegeben werden, kann der serial monitor geschlossen werden und in Pd der port geöffnet werden ('open port' klicken).



der input pin für das signal von der pflanze ist pin A0 (es gibt auch einen output pin (A1) mit dem LEDs angesteuert werden können wenn die pflanze "spricht").