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

using namespace jsonrpc;
using namespace std;

int main() {
  motor_info m2 {"motor2", "6.5"};
  HttpClient httpclient("http://127.0.0.1:7374"); //forest server, this essentially "talks" to our forest server
  hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;
  Json::Value myv2;
  Json::Value gps;
  gps["location"] = "car";

  HttpClient httpclientCar("http://127.0.0.1:7374");
  hw5Client myClientCar(httpclientCar, JSONRPC_CLIENT_V2); 

  HttpServer httpserver(7376);
  Myhw5Server s(httpserver,
		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  
  Json::Value finish;

   try {
  myv = myClientCar.move2("move", "motor_info",
    m2.dump2JSON(),
    gps,
    "car");} 
    catch (JsonRpcException & e) {
  cerr << e.what() << endl;
}
std::cout << myv.toStyledString() << std::endl;


try {
    finish = myClientCar.done();
    } catch (JsonRpcException &e) {
  cerr << e.what() << endl;
}

  //while (s.is_done == false) 
  //{
  //s.StartListening();
  //}

  s.StartListening();
  std::cout << "Hit enter to stop the server" << endl;
  getchar();

  s.StopListening();



} 