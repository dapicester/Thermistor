/*
 * Library written by Paolo D'Apice <paolo.dapice@gmail.com>
 *
 * This code is in the public domain.
 */

#include "Thermistor.h"
#include <Arduino.h>
#include <math.h>

/// O Celcius degrees in Kelvin.
static const float ZERO = 273.15;

Thermistor::Thermistor(int p, float b, int r, int t)
        : pin(p), beta(b), r0(r), t0(t), k(beta/(t0 + ZERO)) {}

float Thermistor::temperature() {
    analog = analogRead(pin);
    compute();
    return temp;
}

void Thermistor::compute() {
    temp = beta / (log(1024.0 / analog - 1) + k);
    temp -= ZERO; // Kelvin to Celcius
}

