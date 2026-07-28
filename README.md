# 🎛️ Arduino Potentiometer LED Tracker

An Arduino-based steering wheel simulator that uses a potentiometer to drive a smooth, 5-LED light bar. As you turn, it dynamically fades the LEDs based on position - a test run for visual steering and turning indicators before applying it to my remote-controlled car project!

---

## 📹 Project Demonstration

https://github.com/user-attachments/assets/bb793892-e42d-4041-8466-c73a617ac297

---

## 💻 Circuit Logic Snippet

```cpp
void adjustBrightness(double position, double middle, int pinNo) {
  double diff = abs(position - middle);
  double brightness = (1.0 - (diff / half)) * maxScale;
  analogWrite(pinNo, brightness);
}
