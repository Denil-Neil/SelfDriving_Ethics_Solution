#include "car_alert.h"

car_alert::car_alert(std::string n, std::string m)
{
    this->name = n;
    this->message = m;
}

car_alert::car_alert()
{
    this->name = "";
     this->message = "";
}
std::string car_alert::getName()
{
    return this->name;
}

std::string car_alert::getmessage()
{
    return this->message;
}

Json::Value
car_alert::dump2JSON
(void)
{
  Json::Value result {};

  if (this->name != "")
    {
      result["Name"] = this->name;
    }
  result["Message"] = this->message;

  return result;
}

bool car_alert::JSON2Object (Json::Value arg_jv)
{

  if ((arg_jv.isNull() == true) ||
      (arg_jv.isObject() != true))
    {
      return false;
    }

  if (((arg_jv["Name"]).isNull() == true) || ((arg_jv["Name"]).isString() != true))
    {
      return false;
    }

  // we allow GPS_DD to be modified (for mobility)
  this->name = (arg_jv["Name"]).asString();
  this->name = (arg_jv["Message"]).asString();
  return true;
}