Moody Plant

Die Mozzi Dateien wurden �berarbeitet weil sie in einer anderen IDE nicht funktioniert haben... es sollten aber auch mit den normalen mozzi files alles gut gehen.
Die TrueRMS library muss allerdings eingebunden werden!


Der code wurde urspr�nglich mit "PURR data" (=neues Pd extended) z erstellt. 
Ich habe ihn angepasst, dass er auch auch mit vanilla funktionieren sollte, aber man muss die libraries  'comport',  'zexy' und 'cyclone' installiert haben 
(Pd-->hilfe-->finde externals online--> diese libraries suchen und installieren)

alternativ Purr data downloaden:     https://github.com/agraef/purr-data/releases



der arduino code ist zum einlesen des ersten analog inputs und zum weiterleiten �ber den serial output.

zum starten des programms, muss 'main.pd' ge�ffnet werden. der richtige port muss ausgew�hlt werden (muss gegebenenfalls ge�ndert werden, standard ist port 5 weil ich dort meinen arduino anstecke). Den richtigen port kann man am besten �ber die arduino IDE finden(?).

ein kleiner bug ist, dass man zuerst die arduino IDE �ffnen muss und den serial monitor (Tools-->serial monitor) �ffnen muss (hier sollten im 10ms takt werte ausgegeben werden)

wenn diese werte ausgegeben werden, kann der serial monitor geschlossen werden und in Pd der port ge�ffnet werden ('open port' klicken).



der input pin f�r das signal von der pflanze ist pin A0 (es gibt auch einen output pin (A1) mit dem LEDs angesteuert werden k�nnen wenn die pflanze "spricht").