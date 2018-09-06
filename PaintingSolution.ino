
// Declare pins for all sensors/attachments
int sensor1 = 6;
int sensor2 = 7;
int alarm = 8;


// Run setup
void setup()
{
    // Open the serial monitor at 9600 BAUD
    Serial.begin(9600);

    // Declare which pins are inputs and outputs
    pinMode(sensor1, INPUT);
    pinMode(sensor2, INPUT);
    pinMode(alarm, OUTPUT);
}

// Main
void loop()
{
    // Alarm counter variable
    int counter = 0;

    // Loop  to ensure accuracy of alarm and make sure that motion is detected at least 3 times in 2-3s
    // Will take 2s if both sensors pick up something and 3s if only one does - ensures accuracy
    for (int i = 0; i < 3; i++)
    {
        if (digitalRead(sensor1) == HIGH)
        {
            Serial.println("Sensor 1: Active");
            counter ++;
        }
        else
        {
            Serial.println("Sensor 1: Inactive");
        }

        if (digitalRead(sensor2) == HIGH)
        {
            Serial.println("Sensor 2: Active");
            counter ++;
        }
        else
        {
            Serial.println("Sensor 2: Inactive");
        }
        delay(500);
    }


    // Checks if the alarm counter reached the number to trigger it
    if(counter >= 3)
    {
        digitalWrite(alarm, HIGH); //Set the alarm to on
    } else
    {
        digitalWrite(alarm, LOW); //Set the alarm to off
    }

    // Resets variables and waits 3 seconds before checking everything again
    counter = 0;
    delay(3000);
}