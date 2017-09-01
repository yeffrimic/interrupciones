/*
Este ejemplo es para entender el funcionamiento de la interrupciones en arduino 
Circuito:
boton conectado a negativo y al pin 22 
teensyLC, funciona en cualquier pin que diga Interrupt en arduino tambien
Las interrupciones tienen prioridad sobre nuestro codigo por eso 
es que podemos salir del while true sin problema. 

*/
/***********************************
 *              Librerias          * 
 ********************************* */
#include <avr/io.h>
#include <avr/interrupt.h>

/***********************************
 *              variables          * 
 ********************************* */
volatile boolean estado = false;// utilizamos volatile

void setup() {
  pinMode(22, INPUT_PULLUP);
  attachInterrupt(22, cambioDeEstado, RISING);
  pinMode(5, OUTPUT);
}

void loop() {
  while (true) {// cuando ponemos un while True se supone que nada lo saca del loop 
    digitalWrite(5, estado);//
  }
}
void cambioDeEstado() {
  estado = !estado;// actualizamos el estado con la negacion del estado anterior
}
