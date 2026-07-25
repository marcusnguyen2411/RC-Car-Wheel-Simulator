# \# 🎛️ Arduino Potentiometer LED Tracker

# 

# An Arduino Mega project of mine that maps analog potentiometer input to a 5-LED dynamic display.

# 

# \---

# 

# \## 📹 Project Demonstration

# 

# <!-- You will paste your video link here in Step 3 -->

# 

# \---

# 

# \## 💻 Circuit Logic Snippet

# 

# ```cpp

# void adjustBrightness(double position, double middle, int pinNo) {

# &#x20; double diff = abs(position - middle);

# &#x20; double brightness = (1.0 - (diff / half)) \* 255.0;

# 

# &#x20; if (brightness < 0) brightness = 0;

# &#x20; if (brightness > 255) brightness = 255;

# 

# &#x20; analogWrite(pinNo, (int)brightness);

# }

