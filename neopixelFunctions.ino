void neoPixelsRed()
{
    #define PIN            12
    #define NUMPIXELS      6
    Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

    pixels.begin(); // This initializes the NeoPixel library.
  
    for(int i=0;i<NUMPIXELS;i++)
    {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(255,0,0));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
}
void neoPixelsGreen()
{
    #define PIN            12
    #define NUMPIXELS      6
    Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

    pixels.begin(); // This initializes the NeoPixel library.
  
    for(int i=0;i<NUMPIXELS;i++)
    {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(0,255,0));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
}
void neoPixelsBlue()
{
    #define PIN            12
    #define NUMPIXELS      6
    Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

    pixels.begin(); // This initializes the NeoPixel library.
  
    for(int i=0;i<NUMPIXELS;i++)
    {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(0,0,255));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
}

