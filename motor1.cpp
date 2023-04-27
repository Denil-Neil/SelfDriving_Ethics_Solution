
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

using namespace jsonrpc;
using namespace std;

int main() {
  motor_info m1 {"motor1", "8.5"};  
  HttpClient httpclient("http://127.0.0.1:7376"); //forest server, this essentially "talks" to our forest server
  hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;
  Json::Value myv2;
  Json::Value gps;
  gps["location"] = "car";

  HttpClient httpclientCar("http://127.0.0.1:7374");
  hw5Client myClientCar(httpclientCar, JSONRPC_CLIENT_V2);

  HttpServer httpserver(7375);
  Myhw5Server s(httpserver,
		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)

  Json::Value finish;
  
  try {
  myv = myClientCar.move2("move", "motor_info",
    m1.dump2JSON(),
    gps,
    "car");} 
    catch (JsonRpcException & e) {
  cerr << e.what() << endl;
}
std::cout << myv.toStyledString() << std::endl;
  
  s.StartListening();
  std::cout << "Hit enter to stop the server" << endl;
  getchar();

  s.StopListening();

  
}

//1:09:36

  
