# parcial_micro2025.1
comportamiento del programa
Switch 1 → alterna LED 1. (intermitencia)
Switch 2 → alterna LED 2. (intermitencia)
Switch 3 → Activa la secuencia secuencia especial de LEDs. (#8. Los LEDs se encienden en secuencia descendente, mayor a menor número de pin)
La secuencia se ejecuta cada 150 ms (controlada con millis()).
Se utiliza un delay(200)para evitar rebotes en los interruptores.
updateLEDs()mantiene el estado de los LED actualizado.
