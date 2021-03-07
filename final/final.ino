#include <Keypad.h>
const byte ROWS = 4; /* four rows */
const byte COLS = 3; /* four columns */
/* define the symbols on the buttons of the keypads */
char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'},
};
byte rowPins[ROWS] = {6, 7, 8, 9}; /* connect to the row pinouts of the keypad */
byte colPins[COLS] = {10, 11, 12}; /* connect to the column pinouts of the keypad */

/* initialize an instance of class NewKeypad */
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
unsigned long loopCount;
unsigned long startTime;
String msg;

//select lines declaration
int s1a = 0;
int s1b = 1;
int s1c = 2;
int s2a = 3;
int s2b = 4;
int s2c = 5;
int r;
int c;

void setup()
{
//    Serial.begin(9600);
    pinMode(s1a, OUTPUT);
    pinMode(s1b, OUTPUT);
    pinMode(s1c, OUTPUT);
    pinMode(s2a, OUTPUT);
    pinMode(s2b, OUTPUT);
    pinMode(s2c, OUTPUT);
}

int getKeypadIntegerMulti()
{
    int value = 0;                                // the number accumulator
    int keyvalue;                                 // the key pressed at current moment
    int isnum;
//    Serial.println("Enter the digits ");
//    Serial.print("You have typed: ");
    do
    {
        keyvalue = customKeypad.getKey();                   // input the key
        isnum = (keyvalue >= '0' && keyvalue <= '9');       // is it a digit?
        if (isnum)
        {
//            Serial.print(keyvalue - '0');
            value = value * 10 + keyvalue - '0';            // accumulate the input number
        }

    } while (isnum || !keyvalue);                           // until not a digit or while no key pressed
    
//    Serial.println(" ");
//    Serial.print("Returning from funtion: ");
//    Serial.println(value);
    return value;
}

void loop()
{
    int val = getKeypadIntegerMulti();
//    Serial.println("Value is: ");
//    Serial.println(val);
    int r = val / 10;
    int c = val % 10;
//     Serial.println(r);
//    Serial.print("row : ");
//    Serial.println(r);
//    Serial.print("col : ");
//    Serial.println(c);

    if (r == 1)
    {
        digitalWrite(s1a, LOW);
        digitalWrite(s1b, LOW);
        digitalWrite(s1c, LOW);
      //  Serial.println("get in to r==1 ");
    }

    if (r == 2)
    {
        digitalWrite(s1a, HIGH);
        digitalWrite(s1b, LOW);
        digitalWrite(s1c, LOW);
      //  Serial.println("get in to r==2 ");
    }

    if (r == 3)
    {
        digitalWrite(s1a, LOW);
        digitalWrite(s1b, HIGH);
        digitalWrite(s1c, LOW);
     //   Serial.println("get in to r==3 ");
    }

    if (r == 4)
    {
        digitalWrite(s1a, HIGH);
        digitalWrite(s1b, HIGH);
        digitalWrite(s1c, LOW);
      //  Serial.println("get in to r==4 ");
    }

    if (r == 5)
    {
        digitalWrite(s1a, LOW);
        digitalWrite(s1b, LOW);
        digitalWrite(s1c, HIGH);
      //  Serial.println("get in to r==5 ");
    }

    if (r == 6)
    {
        digitalWrite(s1a, HIGH);
        digitalWrite(s1b, LOW);
        digitalWrite(s1c, HIGH);
        Serial.println("get in tor==6 ");
    }

    if (r == 7)
    {
        digitalWrite(s1a, LOW);
        digitalWrite(s1b, HIGH);
        digitalWrite(s1c, HIGH);
        Serial.println("get in tor==7 ");
    }

    if (r == 8)
    {
        digitalWrite(s1a, HIGH);
        digitalWrite(s1b, HIGH);
        digitalWrite(s1c, HIGH);
        Serial.println("get in tor==7 ");
    }

    if (c == 1)
    {
        digitalWrite(s2a, LOW);
        digitalWrite(s2b, LOW);
        digitalWrite(s2c, LOW);
        Serial.println("get in to c==1 ");
    }

    if (c == 2)
    {
        digitalWrite(s2a, HIGH);
        digitalWrite(s2b, LOW);
        digitalWrite(s2c, LOW);
        Serial.println("get in to c==2 ");
    }

    if (c == 3)
    {
        digitalWrite(s2a, LOW);
        digitalWrite(s2b, HIGH);
        digitalWrite(s2c, LOW);
        Serial.println("get in to c==3 ");
    }

    if (c == 4)
    {
        digitalWrite(s2a, HIGH);
        digitalWrite(s2b, HIGH);
        digitalWrite(s2c, LOW);
        Serial.println("get in to c==4 ");
    }

    if (c == 5)
    {
        digitalWrite(s2a, LOW);
        digitalWrite(s2b, LOW);
        digitalWrite(s2c, HIGH);
        Serial.println("get in to c==5 ");
    }

    if (c == 6)
    {
        digitalWrite(s2a, HIGH);
        digitalWrite(s2b, LOW);
        digitalWrite(s2c, HIGH);
        Serial.println("get in toc==6 ");
    }

    if (c == 7)
    {
        digitalWrite(s2a, LOW);
        digitalWrite(s2b, HIGH);
        digitalWrite(s2c, HIGH);
        Serial.println("get in to c==7 ");
    }

    if (c == 8)
    {
        digitalWrite(s2a, HIGH);
        digitalWrite(s2b, HIGH);
        digitalWrite(s2c, HIGH);
        Serial.println("get in to c==7 ");
    }

    delay(3000);
}
