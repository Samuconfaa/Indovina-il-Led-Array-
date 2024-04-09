/*
Autore: Samuconfaa
Titolo: Indovina il Led
Descrizione: Quando viene premuto uno dei pulsanti, il programma seleziona casualmente 
uno dei quattro LED e lo accende. Se il pulsante premuto corrisponde al LED acceso, l'utente vince.
Data: 9 Aprile 24
Versione: 1
*/

const int BUZZER = 8;
const int LED_PIN[] = {10, 11, 12, 13};  // array per i pin dei LED
const int BUTTON_PIN[] = {4, 5, 6, 7};   // array per i pin dei pulsanti


void setup() {
  // led e pulsanti
  for (int i = 0; i < 4; ++i) {
    pinMode(LED_PIN[i], OUTPUT);
    pinMode(BUTTON_PIN[i], INPUT);
  }

  // buzzer
  pinMode(BUZZER, OUTPUT);

  // seme
  randomSeed(millis());
}


void loop() {
  // inizializzazione a non premuto
  int buttonPressed = -1;
  
  // ricerca del bottone premuto		
  for (int b = 0; b < 4; ++b) {
    if (digitalRead(BUTTON_PIN[b]) == HIGH) { 
      delay(200); 
      buttonPressed = b; // memorizza numero bottone premuto
    }
  }

  // controllo se il bottone premuto
  if (buttonPressed != -1) {
    int ledChosen = random(4); // generazione numero led			

    // tutti i led off
    for (int l = 0; l < 4 ; ++l)
      digitalWrite(LED_PIN[l], LOW);

    // accensione led generato random
    digitalWrite(LED_PIN[ledChosen], HIGH);

    // controllo se è lo stesso del bottone
    if (buttonPressed == ledChosen)
      tone(BUZZER, 440, 100);
  }
}
