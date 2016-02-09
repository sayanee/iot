/* Firmware to flash on Particle Photon */

void setup() {
  pinMode(D1, INPUT_PULLUP);
  pinMode(D0, INPUT_PULLDOWN);
}

void loop() {
  delay(1500);

  if (digitalRead(D1) == HIGH) {
    System.sleep(D0, RISING);

    while (Particle.connected() != true) {
      delay(50);
    }

    delay(1000);
    Particle.publish("bell");
  }
}
