
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
#include "hw5server.cpp"
#include "hw5client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;
using namespace std;

int main() {
  
  car_alert car {"auto_v", "since m1 has higher safety rating, m1 is going to be crashed by auto_V"};
  car_alert car2 {"auto_v", "since m2 has lower safety rating, m2 is safe from the crash"};

  HttpClient httpclient1("http://127.0.0.1:7375"); //forest server, this essentially "talks" to our forest server
  hw5Client myClient1(httpclient1, JSONRPC_CLIENT_V2);

  HttpClient httpclient2("http://127.0.0.1:7376"); //forest server, this essentially "talks" to our forest server
  hw5Client myClient2(httpclient2, JSONRPC_CLIENT_V2);


  Json::Value myv;
  Json::Value myv2;
  Json::Value gps;
  Json::Value gps2;
  gps["location"] = "motor1";
  gps2["location"] = "motor2";

Json::Value finish;

try {
    finish = myClient1.done();
    } catch (JsonRpcException &e) {
  cerr << e.what() << endl;
}

  HttpServer httpserver(7374);
  Myhw5Server s(httpserver,
		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)

  while (s.is_done == false) 
  {
    s.StartListening();
  }
  s.StopListening();
  std::cout << myv.toStyledString() << std::endl;
  
  try {
  myv = myClient1.move("move", "car_alert",
    car.dump2JSON(),
    gps,
    "motor1");} 
    catch (JsonRpcException & e) {
  cerr << e.what() << endl;
}

  try {
  myv2 = myClient2.move("move", "car_alert",
    car2.dump2JSON(),
    gps,
    "motor2");} 
    catch (JsonRpcException & e) {
  cerr << e.what() << endl;
}

}