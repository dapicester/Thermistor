/*
 * FlamingoEda thermistor library.
 *
 * This library provides a simple API for the thermistors.
 * The default configuration assumes that a vultage divider
 * is used.
 * As a reference, please see the thermistor block
 * provided by FlamingoEda.
 *
 * Library written by Paolo D'Apice <paolo.dapice@gmail.com>
 *
 * This code is in the public domain.
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
