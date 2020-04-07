#define TRANSITION 500

#define PIN_MIN 10
#define PINS 4

void setup()
{
  for (int i = 0; i < PINS; i++)
    pinMode(i + PIN_MIN, OUTPUT);
}

void loop()
{
  int active = (millis() % (TRANSITION * 4)) / TRANSITION;

  for (int i = 0; i < PIN_MIN; i++)
    digitalWrite(i + PIN_MIN, i == active ? LOW : HIGH);
}