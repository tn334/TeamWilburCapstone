bool red, yellow, green;


void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  red = true;
  yellow = true;
  green = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    char read = Serial.read();//read from computer (clears the buffer just in case)

    if(read == 'r')
    {
      if(red)
      {
        digitalWrite(2,HIGH);
        red = false;
        Serial.print("Red is on\n");
      }
      else
      {
        digitalWrite(2, LOW);//turn off
        red = true;
        Serial.print("Rd is off\n");
      }

    }
    else if(read == 'y')
    {
      if(yellow)
      {
        digitalWrite(3,HIGH);
        yellow = false;
        Serial.print("Yellow is on\n");
      }
      else
      {
        digitalWrite(3, LOW);//turn off
        yellow = true;
        Serial.print("Yellow is off\n");
      }

    }
    else if(read == 'g')
    {
      if(green)
      {
        digitalWrite(4,HIGH);
        green = false;
        Serial.print("Green is on\n");
      }
      else
      {
        digitalWrite(4, LOW);//turn off
        green = true;
        Serial.print("Green is off\n");
      }

    }
    else if(read == 'a')
    {
      if(yellow| red | green)
      {
        digitalWrite(3,HIGH);
        digitalWrite(2,HIGH);
        digitalWrite(4,HIGH);

        yellow = false;
        red = false;
        green = false;
        Serial.print("all are on\n");
      }
      else
      {
        digitalWrite(3,LOW);
        digitalWrite(2,LOW);
        digitalWrite(4,LOW);
        yellow = true;
        red = true;
        green = true;
        Serial.print("all are off\n");
      }

    }
    
  }
}
