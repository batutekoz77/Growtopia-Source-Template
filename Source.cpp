/* Warnings */
#define _WINSOCK_DEPRECATED_NO_WARNINGS

/* Include */
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <cstdint>
#include <map>
#include <signal.h>
#include <thread>
#include <random>

/* Library */
#include "enet/include/enet.h"
#include "include/nlohmann/json.hpp"

/* Header */
#include "RTParam.hpp"
#include "Color.h"
#include "Item.h"
#include "Base.h"
#include "Player.h"
#include "Packet.h"
#include "Webhook.h"
#include "Logs.h"
#include "SaveSystem.h"
#include "skStr.h"
#include "World.h"

/* Pragma */
#pragma comment(lib, "Ws2_32.lib")

vector<thread> threads;

int main() {
	// config();
	if (init_enet() == -1) std::cout << "Enet Cyka!!!" << std::endl;
	else {
		// items_dat();
	}

	ENetEvent event;
	while (true) {
		while (enet_host_service(server, &event, 3000) > 0) {
			ENetPeer* peer = event.peer;
			switch (event.type) {
			case ENET_EVENT_TYPE_CONNECT:
			{

				break;
			}
			case ENET_EVENT_TYPE_RECEIVE:
			{

				break;
			}
			case ENET_EVENT_TYPE_DISCONNECT:
			{

				break;
			}
			default:
				cout << pi(peer)->tankIDName << " Blyad sto eta enet type " << event.type << " !?" << endl;
				break;
			}
		}
	}
	return 0;
}