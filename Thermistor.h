/*
  Thermistor.h - FlamingoEda thermistor library.

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

#ifndef THERMISTOR
#define THERMISTOR

/// Simple interface to thermistors.
class Thermistor {
public:

    /**
     * New thermistor on the given pin.
     * @param pin The used pin.
     * @param beta The beta coefficient - from datasheet.
     * @param r0 The resistance at t0 - from datasheet (ohms).
     * @param t0 The reference temperature - from datasheet (C degrees)
     */
    Thermistor(int pin, float beta = 4300.0, int r0 = 10000, int t0 = 25);

    /// Get the temperature.
    float temperature();

    /// Get the measured sensor value.
    int value() const {
        return analog;
    }

private:
    /// Steinhard-hard equation
    void compute();

private:
    const int pin;
    const float beta;
    const int r0;
    const int t0;
    const float k;

    int analog;
    float temp;
};

#endif // THERMISTOR
