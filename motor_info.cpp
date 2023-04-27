#include "motor_info.h"

motor_info::motor_info(std::string n, std::string rating)
{
    this->name = n;
    this->safety_rating = rating;
}

motor_info::motor_info()
{
    this->name = "";
    this->safety_rating = "";
}

std::string motor_info::getMotor_info()
{
    return this->name;
}

std::string motor_info::getRating(){
    return this->safety_rating;
}


Json::Value
motor_info::dump2JSON
(void)
{
  Json::Value result = {};
  if (this->name != "")
    {
      result["Name"] = this->name;
    }
    result["Safety_rating"] = this->safety_rating;

  return result;
}

bool motor_info::JSON2Object (Json::Value arg_jv)
{

  if ((arg_jv.isNull() == true) ||
      (arg_jv.isObject() != true))
    {
      return false;
    }
  this->name = (arg_jv["Name"]).asString();
  this->safety_rating = (arg_jv["Safety_rating"]).asString();

  return true;
}
