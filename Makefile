
# Makefile for f2022, ecs36b
# https://macappstore.org/libjson-rpc-cpp/
# https://github.com/cinemast/libjson-rpc-cpp

CC = g++ -std=c++17
CFLAGS = -g -I/opt/homebrew/include

# LDFLAGS = 	-L/Users/sfwu/vcpkg/installed/arm64-osx/lib -ljsoncpp -L/opt/homebrew/lib/ -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl

LDFLAGS = 	-ljsoncpp -L/opt/homebrew/lib/ -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl

INC	=	CommonFunctions.h
INC_CL	=	JvTime.h car_alert.h motor_info.h 
OBJ	=	 JvTime.o car_alert.o motor_info.o 

# rules.
all: 	car  motor1 motor2 # hw5server # hw5client 

#
#
# <target> : [... tab...] <dependency>
# [... tab ....] <action>

hw5client.h:		ecs36b_hw5.json
	jsonrpcstub ecs36b_hw5.json --cpp-server=hw5Server --cpp-client=hw5Client

hw5server.h:		ecs36b_hw5.json
	jsonrpcstub ecs36b_hw5.json --cpp-server=hw5Server --cpp-client=hw5Client

hw5client.o:		hw5client.cpp hw5client.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) hw5client.cpp

hw5server.o:	hw5server.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) hw5server.cpp

car.o:		car.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) car.cpp

motor1.o:		motor1.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) motor1.cpp

motor2.o:		motor2.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) motor2.cpp

ecs36b_JSON.o:		ecs36b_JSON.cpp $(INC)
	$(CC) -c $(CFLAGS) ecs36b_JSON.cpp

JvTime.o:	JvTime.cpp JvTime.h $(INC)
	$(CC) -c $(CFLAGS) JvTime.cpp 

car_alert.o:	car_alert.cpp car_alert.h $(INC)
	$(CC) -c $(CFLAGS) car_alert.cpp

motor_info.o:	motor_info.cpp motor_info.h $(INC)
	$(CC) -c $(CFLAGS) motor_info.cpp

hw5server:	 hw5server.o ecs36b_JSON.o $(OBJ)
	$(CC) -o hw5server hw5server.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

car:	 car.o ecs36b_JSON.o $(OBJ)
	$(CC) -o car car.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

motor1:	 motor1.o ecs36b_JSON.o $(OBJ)
	$(CC) -o motor1 motor1.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

motor2:	 motor2.o ecs36b_JSON.o $(OBJ)
	$(CC) -o motor2 motor2.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

hw5client:	 hw5client.o ecs36b_JSON.o $(OBJ)
	$(CC) -o hw5client hw5client.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

clean:
	rm -f *.o *~ core hw5client.h hw5server.h hw5client hw5server village forest grandmaHome