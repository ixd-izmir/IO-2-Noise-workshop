/**
 *    A slider for Arduino Note
 *
 Author: Daniele Savasta based on Guido Example

 */

import processing.serial.*;
import de.bezier.guido.*;


Slider slider;
Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial por

void setup ()
{
  size(400, 400);

  // make the manager

  Interactive.make( this );

  // create a slider

  slider = new Slider( 2, 2, width-4, 100 );
  String portName = Serial.list()[1]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
}

void draw ()
{
  background( 0 );

  fill( 255 - (slider.value * 255) );
  ellipse( width/2, height/2, 150, 150 );
  /*fill( slider.value * 255 );
  ellipse( width/2, height/2, 70, 70 );*/
  myPort.write(byte(slider.value*1000));         //send a 1
  println(slider.value);
 }

public class Slider
{
  float x, y, width, height;
  float valueX = 0, value;

  Slider ( float xx, float yy, float ww, float hh )
  {
    x = xx;
    y = yy;
    width = ww;
    height = hh;

    valueX = x;

    // register it
    Interactive.add( this );
  }

  // called from manager
  void mouseDragged ( float mx, float my )
  {
    valueX = mx - height/2;

    if ( valueX < x ) valueX = x;
    if ( valueX > x+width-height ) valueX = x+width-height;

    value = map( valueX, x, x+width-height, 0, 1 );
  }

  void draw ()
  {
    noStroke();

    fill( 100 );
    rect(x, y, width, height);

    fill( 120 );
    rect( valueX, y, height, height );
  }
}
