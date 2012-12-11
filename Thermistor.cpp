/*
  Thermistor.cpp - FlamingoEda thermistor library.

  Copyright (c) 2012 Paolo D'Apice <paolo.dapice@gmail.com>.
  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
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

