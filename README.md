# 🎛️ Arduino Potentiometer LED Tracker

An Arduino Mega project of mine that maps analog potentiometer input to a 5-LED dynamic display.

---

## 📹 Project Demonstration

<!-- You will paste your video link here in Step 3 -->

---

## 💻 Circuit Logic Snippet

```cpp
void adjustBrightness(double position, double middle, int pinNo) {
  double diff = abs(position - middle);
  double brightness = (1.0 - (diff / half)) * 255.0;

  if (brightness < 0) brightness = 0;
  if (brightness > 255) brightness = 255;

  analogWrite(pinNo, (int)brightness);
}