/*------------------------------------------------------------------------------

  LIDARLite Arduino Library
  LIDARLite.h

  This library provides quick access to all the basic functions of LIDAR-Lite
  via the Arduino interface. Additionally, it can provide a user of any
  platform with a template for their own application code.

  Copyright (c) 2016 Garmin Ltd. or its subsidiaries.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

------------------------------------------------------------------------------*/
#ifndef LIDARLite_h
#define LIDARLite_h

#define LIDARLITE_ADDR_DEFAULT 0x62

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "I2C.h"

typedef uint8_t byte;

class LIDARLite {
  public:
      LIDARLite(uint8_t = LIDARLITE_ADDR_DEFAULT, int = 0);

      void configure(int = 0);
      void reset();
      int distance(bool = true);
      void write(char, char);
      void read(char, int, byte*, bool);
      void correlationRecordToSerial(char = '\n', int = 256);
  private:
      I2C* i2c;
};

#endif
