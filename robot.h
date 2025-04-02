#ifndef ROBOT_H
#define ROBOT_H

#include <Arduino.h>
#include <NewPing.h>//ESP8266.h>


class Motor {
private:
  int _pin_A, _pin_B, _speedMax, _speedSlow;
  boolean _flipMotor = false;

public:
  Motor(int _pinA, int _pinB)
  {
    _pin_A = _pinA;
    _pin_B = _pinB;
    _speedMax = 255;
    _speedSlow = 160;
    ledcAttach(_pin_A, 2000, 8);
    ledcAttach(_pin_B, 2000, 8);
  }

  void flipMotor(boolean flip)
  {
    _flipMotor = flip;
  }

  void run(int _speed)
  {
    if(_flipMotor)_speed = -_speed;
    if(_speed > 0)
    {
      if(_speed > _speedMax)_speed = _speedMax;
      ledcWrite(_pin_A, 0);
      ledcWrite(_pin_B, _speed);
    }
    else if(_speed <= 0)
    {
      _speed = -_speed;
      if(_speed > _speedMax)_speed = _speedMax;
      ledcWrite(_pin_A, _speed);
      ledcWrite(_pin_B, 0);
    }
  }
  void go(int, int);
  void stop();
};

class Cutter
{
private:
  int _pin_C1;
  int _pin_C2;
  int _pin_C3;
  int _speedMax;
  int _speedSlow;
  // int LED_CHANELL_3A;
  int FREQ;
  int RESOLUTION;

public:
  Cutter(int _C1, int _C2, int _C3 ){
    _pin_C1 = _C1;
    _pin_C2 = _C2;
    _pin_C3 = _C3;
    pinMode(_pin_C1, OUTPUT);
    pinMode(_pin_C2, OUTPUT);
    ledcAttach(_pin_C3, 2000, 8);
  }
  
  void start(int _speed){
    digitalWrite(_pin_C1, HIGH);
    digitalWrite(_pin_C2, HIGH);
    ledcWrite(_pin_C3, _speed);
  }

  void stop(){
    digitalWrite(_pin_C1, LOW);
    digitalWrite(_pin_C2, LOW);
    ledcWrite(_pin_C3, 0);
  }
};


class Sensor { 
private:
  int _pin_A;

public:
  Sensor(int _pinA){
    _pin_A = _pinA;
    pinMode(_pin_A, INPUT);
  }

  int get(){
    int _sensor_bool;
    if (digitalRead(_pin_A))  {_sensor_bool = 0;}    // The switch is not activated the variable Bump is false
    if (!digitalRead(_pin_A)) {_sensor_bool = 1;}
    return _sensor_bool;
  }
};

class Sonar {
private:
  int _pin_A;
  int Max_Distance_Sonar = 20;
  NewPing *sonar1;

public:
  Sonar(int _pinA) {
    sonar1 = new NewPing(_pinA, _pinA, 80);
  }

  int get(){
    int _sonar_bool;
    int _distanceX = sonar1->ping_cm();
    if (_distanceX <= Max_Distance_Sonar ) {_sonar_bool = 1;}
    if (_distanceX > Max_Distance_Sonar )  {_sonar_bool = 0;}
    return _sonar_bool;
  }
};


// class XX {
// private:
//   int _pin_A;

// public:

// };


#endif