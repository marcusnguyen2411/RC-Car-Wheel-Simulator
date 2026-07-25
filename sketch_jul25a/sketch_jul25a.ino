const int totalLEDs = 5;
int pinList[] = {8,9,10,11,12};
int readPin = A7;
double maxScale = 255.0;
double distance = maxScale/4.0;
double half = distance/2.0;

struct Pair {
  double dist;
  int pin;
};

Pair valueList[totalLEDs];


void setup() {
  Serial.begin(9600);
  for (int x = 0; x < totalLEDs; x++) {
    pinMode(pinList[x], OUTPUT);
  }
  pinMode(readPin,INPUT);

  double temp = 0;
  for (int x = 0; x < totalLEDs; x++) {
    valueList[x].dist = temp;
    valueList[x].pin = pinList[x];
    Serial.print(valueList[x].dist);
    Serial.println(valueList[x].pin);
    temp += distance;
  }

}

void loop() {
  double position = (analogRead(readPin)*maxScale)/1023.0;
  for (int x = 0; x < totalLEDs; x++) {
    double middle = valueList[x].dist;
    int pinNo = valueList[x].pin;
    if ((position >= middle - half) && (position <= middle + half)) {
      adjustBrightness(position,middle,pinNo);
    } else{
      analogWrite(pinNo,0);
    }
  }

}

void adjustBrightness(double position, double middle, int pinNo) {
  double diff = abs(position - middle);
  double brightness = (1.0 - (diff / half)) * maxScale;
  analogWrite(pinNo, brightness);
}
