#pragma once
#include <iostream>
using namespace std;

class Color {
  public:
    // Color() : red(0), green(0), blue(0) alpha(0)
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    Color() : red(0), green(0), blue(0), alpha(255) {}

    uint8_t getRed() const {
      return red;
    }

    uint8_t getGreen() const {
      return green;
    }

    uint8_t getBlue() const {
      return blue;
    }

    uint8_t getAlpha() const {
      return alpha;
    }

    friend std::ostream& operator<<(std::ostream& os, const Color& color) {
      os << "RGBA: (" << static_cast<uint8_t>(color.getRed()) << ", " << static_cast<uint8_t>(color.getGreen()) << ", " << static_cast<uint8_t>(color.getBlue()) << ", " << static_cast<uint8_t>(color.getAlpha()) << ")";
      return os;
    }

  private:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};

uint8_t colorClamping(uint8_t value){
  if(value>255){
    return 255;
  }
  else if(value<0){
    return 0;
  }
  else {
    return value;
  }
}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a){
  red = colorClamping(r);
  green = colorClamping(g);
  blue = colorClamping(b);
  alpha = colorClamping(a);
}

Color colorAddition(Color a, Color b) {
  uint8_t newRed = colorClamping(a.getRed() + b.getRed());
  uint8_t newGreen = colorClamping(a.getGreen() + b.getGreen());
  uint8_t newBlue = colorClamping(a.getBlue() + b.getBlue());
  uint8_t newAlpha = colorClamping(a.getAlpha() + b.getAlpha());
  Color newColor(newRed, newGreen, newBlue, newAlpha);
  return newColor;
}

Color floatTimesColor(float n, Color color){
  uint8_t newRed = colorClamping(static_cast<uint8_t> (n * color.getRed()));
  uint8_t newGreen = colorClamping(static_cast<uint8_t> (n * color.getGreen()));
  uint8_t newBlue = colorClamping(static_cast<uint8_t> (n * color.getBlue()));
  uint8_t newAlpha = colorClamping(static_cast<uint8_t> (n * color.getAlpha()));
  Color newColor(newRed, newGreen, newBlue, newAlpha);
  return newColor;
}
