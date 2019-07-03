#include <SimpleTimer.h>

#define RESET_TIMER 60000
SimpleTimer timer_reset;

static volatile int working_counter = 0x00;
const int max_reset_counter = 120;

void setup()
{
  Serial.begin(115200);
  delay(500);
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println("Starting...");
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  delay(5000);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  Serial.println("Started!");
  Serial.println();
  timer_reset.setInterval(RESET_TIMER, resetProcedure);
}

void loop()
{
  timer_reset.run();
}

// Процедура перезагрузки
void resetProcedure()
{
  working_counter++;
  Serial.print("Working counter: ");
  Serial.println(working_counter);
  Serial.println();
  if (working_counter >= max_reset_counter)
  {
    working_counter = 0;
    Serial.println("Reseting system!");
    Serial.println();
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(5000);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    Serial.println("Started after reset!");
    Serial.println();
  }
}
