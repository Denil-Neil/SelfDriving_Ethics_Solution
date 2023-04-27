
#ifndef _car_alert_H_
#define _car_alert_H_

// Person.h

//json stuff
#include <string>
#include <iostream>
#include "CommonFunctions.h"

#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>

class car_alert
{
 private:
 std::string name;
 std::string message;
 public:
  car_alert(std::string n, std::string m);
  car_alert();
  std::string getName();
  std::string getmessage();
  virtual Json::Value dump2JSON();
  virtual bool JSON2Object(Json::Value);
};

#endif  /* _PERSON_H_ */