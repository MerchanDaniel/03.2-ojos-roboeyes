// logboot.h
// ============================================
// RESPONSABILIDAD: Dibujar el logo de arranque y hacer el POST de pantalla.
// No sabe nada de: ojos, bus I2C ni comandos del Monitor Serie.
// ============================================

#ifndef LOGBOOT_H
#define LOGBOOT_H

#include <Arduino.h>
#include "display.h"
#include "logo.h"
#include "config.h"

// TODO 2.2: Pinta el marco del logo desde logo_bitmap y preséntalo en el panel.
// Pregunta Guía: ¿Qué debe verse en el panel durante la ventana de arranque?
inline void showLogo() {
    display.clearDisplay();
    display.drawBitmap(0,0, logo_bitmap, OLED_WIDTH, OLED_HEIGHT, SSD1306_WHITE);
    display.display();

    Serial.println(F("[BOOT] mostrando logo de arrange"));
    delay(LOGO_TIME_MS);
}

// TODO 2.3: Dibuja el cuadrado de autoprueba centrado e informa sus coordenadas.
// Pregunta Guía: ¿Cómo compruebas que el cuadrado quedó centrado sin medir a ojo?
inline void testDisplay() {
    display.clearDisplay();

    const int side= 32;
    int x = (OLED_WIDTH - side) / 2 ;
    int y = (OLED_HEIGHT - side) / 2 ;

    display.drawRect(x, y, side, side, SSD1306_WHITE);
    display.display();

    Serial.print(F("[POST] marco de prueba en x="));
    Serial.print(x);
    Serial.print(F(" y="));
    Serial.print(y);
    Serial.print(F(" w="));
    Serial.print(side);
    Serial.print(F(" h="));
    Serial.print(side);

    delay(1000);
}

#endif
