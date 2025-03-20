#include <Arduino.h> 

const int switchPins[3] = {2, 3, 4}; // Pines de los switches
const int ledPins[6] = {13, 12, 11, 10, 9, 8}; // Pines de los LEDs
bool ledStates[6] = {false, false, false, false, false, false}; // Estados de los LEDs

unsigned long previousMillis = 0;
const long interval = 150; // Intervalo de tiempo para la secuencia

// 
bool readSwitch(int pin);
void checkSwitches();
void toggleLed(int index);
void activateSequence();
void updateLEDs();

void setup() {
    Serial.begin(9600);
    for (int i = 0; i < 3; i++) {
        pinMode(switchPins[i], INPUT);  // INPUT normal (para pull-down)
    }
    for (int i = 0; i < 6; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
}

void loop() {
    checkSwitches(); // Verifica el estado de los switches
    updateLEDs();    // Actualiza los LEDs
}

bool readSwitch(int pin) {
    return digitalRead(pin) == HIGH;  // detecta correctamente con pull-down
}

void checkSwitches() {
    if (readSwitch(switchPins[0])) {
        toggleLed(0); // Enciende/apaga LED 0
        delay(200);   // Pequeño delay para evitar rebotes
    }
    if (readSwitch(switchPins[1])) {
        toggleLed(1); // Enciende/apaga LED 1
        delay(200);
    }
    if (readSwitch(switchPins[2])) {
        activateSequence(); // Activa la secuencia especial
    }
}

void toggleLed(int index) {
    ledStates[index] = !ledStates[index]; // Cambia el estado del LED
    digitalWrite(ledPins[index], ledStates[index]); // Enciende o apaga el LED
    Serial.print("LED ");
    Serial.print(index);
    Serial.println(ledStates[index] ? " ON" : " OFF");
}

void activateSequence() {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        
        //  Secuencia descendente de LEDs (del pin 13 al 8)
        for (int i = 0; i < 6; i++) {
            digitalWrite(ledPins[i], HIGH);  // Enciende el LED actual
            delay(300);                      // Mantiene encendido un momento
            digitalWrite(ledPins[i], LOW);   // Apaga el LED antes de pasar al siguiente
        }
    }
}

void updateLEDs() {
    for (int i = 0; i < 6; i++) {
        digitalWrite(ledPins[i], ledStates[i]);
    }
}
