# 🎛️ Arduino Potentiometer LED Tracker

An Arduino Mega project of mine that maps analog potentiometer input to a 5-LED dynamic display.

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
