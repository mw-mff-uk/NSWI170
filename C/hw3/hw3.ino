#define N_PERIODS 16
#define PERIOD_DURATION 500

#define N_LEDS 4
#define N_BTNS 3

#define PRESS_DELAY 700
#define PRESS_PERIOD 250

const int led_pins[] = {10, 11, 12, 13};
const int btn_pins[] = {A1, A2, A3};

const int btn_actions[] = {1, 15, 3};

unsigned short count;
unsigned long t;

short btn_pressed[N_BTNS];
unsigned long btn_emmit_at[N_BTNS];
unsigned long btn_last_interaction[N_BTNS];

void led(unsigned short pins)
{
  pins = pins & 0xF;

  for (int i = 0; i < N_LEDS; i++)
    digitalWrite(led_pins[i], ((pins & (0x1 << i)) > 0) ? LOW : HIGH);
}

void setup()
{
  Serial.begin(9600);

  count = 0;

  for (int i = 0; i < N_LEDS; i++)
    pinMode(led_pins[i], OUTPUT);

  for (int i = 0; i < N_BTNS; i++)
  {
    pinMode(btn_pins[i], INPUT);

    btn_pressed[i] = 0;
    btn_emmit_at[i] = 0;
    btn_last_interaction[i] = 0;
  }
}

void loop()
{
  t = millis();

  led(count);

  for (int i = 0; i < N_BTNS; i++)
  {
    short pressed = abs(digitalRead(btn_pins[i]) - 1);
    short delta = pressed - btn_pressed[i];

    // If the button pressed or released
    if (delta != 0)
    {
      // press and realease at the exact same time fallback
      if (btn_last_interaction[i] == t)
        continue;

      btn_last_interaction[i] = t;

      Serial.print("Button ");
      Serial.print(i);
      Serial.println(delta == 1 ? " pressed" : " released");
    }

    // If button pressed
    if (delta == 1)
    {
      count = (count + btn_actions[i]) % N_PERIODS;
      btn_emmit_at[i] = t + PRESS_DELAY; // Plan next tick
    }

    // If button down
    if (delta == 0 && pressed == 1)
    {
      if (t >= btn_emmit_at[i])
      {
        count = (count + btn_actions[i]) % N_PERIODS;
        btn_emmit_at[i] += PRESS_PERIOD; // Plan next tick

        Serial.print("Button ");
        Serial.print(i);
        Serial.println(" down");
      }
    }

    btn_pressed[i] = pressed;
  }
}