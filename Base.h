#pragma once
//#include <Psapi.h>
using json = nlohmann::json;
typedef unsigned short uint16;
namespace natives {
	typedef int16_t             int16;
	typedef int32_t             int32;
	typedef int64_t             int64;
	typedef std::atomic_bool    flag;
}

string server_ip = "127.0.0.1";
uint16 server_port = 17777;


ENetHost* server;


inline int message_(ENetPacket* packet) {
	if (packet->dataLength > 3u) {
		return *(packet->data);
	}
	return 0;
}
char* text_(ENetPacket* packet) {
	char zero = 0;
	memcpy(packet->data + packet->dataLength - 1, &zero, 1);
	return (char*)(packet->data + 4);
}
inline void send_(ENetPeer* peer, int num, char* data, const int len) {
	const auto packet = enet_packet_create(nullptr, len + 5, ENET_PACKET_FLAG_RELIABLE);
	memcpy(packet->data, &num, 4);
	if (data != nullptr) {
		memcpy(packet->data + 2, data, len);
	}
	char zero = 0;
	memcpy(packet->data + 2 + len, &zero, 1);
	enet_peer_send(peer, 0, packet);
}
int init_enet() {
	enet_initialize();
	ENetAddress address;
	enet_address_set_host(&address, server_ip.c_str());
	address.port = server_port;
	server = enet_host_create(&address, 1024, 1, 0, 0);
	server->checksum = enet_crc32;
	enet_host_compress_with_range_coder(server);
	return 0;
}