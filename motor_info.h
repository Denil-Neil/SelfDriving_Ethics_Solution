#ifndef _motor_info_H_
#define _motor_info_H_

#include <string>
#include <iostream>
#include "CommonFunctions.h"

#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>

class motor_info
{
 private:
 std::string name;
 std::string safety_rating;
 public:
  motor_info(std::string n, std::string rating);
  motor_info();
  std::string getMotor_info();
  std::string getRating();
  virtual Json::Value dump2JSON();
  virtual bool JSON2Object(Json::Value);
};


#endif /* _ITEM_H_ */
