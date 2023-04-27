
// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>

// for JsonRPCCPP
#include <iostream>
#include "hw5server.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
// #include "hw5client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdio.h>

// ecs36b
#include "car_alert.h"
#include "motor_info.h"
#include <time.h>

using namespace jsonrpc;
using namespace std; 

// std::map (key, value pairs)
/* std::map<std::string, Item *> Item;
std::map<std::string, Person *> Person_Map; */

// my location
//GPS_DD process_here;

class Myhw5Server : public hw5Server
{
public:
  Myhw5Server(AbstractServerConnector &connector, serverVersion_t type);

  virtual Json::Value move(const std::string& action,
			   const std::string& class_id,
			   const Json::Value& json_object,
			   const Json::Value& location,
			   const std::string& object_id);

  virtual Json::Value move2(const std::string& action,
			   const std::string& class_id,
			   const Json::Value& json_object,
			   const Json::Value& location,
			   const std::string& object_id);
         
  virtual Json::Value done();  

  std::map<std::string, motor_info *> motor_info_Map;
  std::map<std::string, car_alert *> car_alert_Map;
  bool is_done = false;
};

Myhw5Server::Myhw5Server(AbstractServerConnector &connector, serverVersion_t type)
  : hw5Server(connector, type)
{
  std::cout << "Myhw5Server Object created" << std::endl;
}

// member functions
//can most likely just make a move2 function for items

Json::Value Myhw5Server::move
(const std::string& action, const std::string& class_id,
 const Json::Value& json_object, const Json::Value& location,
 const std::string& object_id)
{
  Json::Value result;
    car_alert * lv_car_ptr;
      if (car_alert_Map.find(object_id) != car_alert_Map.end()) {
      lv_car_ptr = car_alert_Map[object_id];
    } else {
      lv_car_ptr = new car_alert {};
      car_alert_Map[object_id] = lv_car_ptr;
    }
  lv_car_ptr->JSON2Object(json_object);
  result = json_object;
std::cout << "result: \n" << result.toStyledString() << std::endl;
return result;
}

Json::Value Myhw5Server::move2
(const std::string& action, const std::string& class_id,
 const Json::Value& json_object2, const Json::Value& location,
 const std::string& object_id2)
{
  Json::Value result2;
    motor_info * lv_motor_ptr;
      if (motor_info_Map.find(object_id2) != motor_info_Map.end()) {
      lv_motor_ptr = motor_info_Map[object_id2];
    } else {
      lv_motor_ptr = new motor_info {};
      motor_info_Map[object_id2] = lv_motor_ptr;
    }
  lv_motor_ptr->JSON2Object(json_object2);
  result2 = json_object2;
std::cout << "result: \n" << result2.toStyledString() << std::endl;
return result2;
}

Json::Value Myhw5Server::done()
{
  Json::Value result;
  result["done"] = "Data sent";
  std::cout << "- sending to next Server\n" << result.toStyledString() << std::endl;
  is_done = true;
  return result;
}
