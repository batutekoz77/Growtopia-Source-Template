#pragma once

struct Player {
	string tankIDName = "", tankIDPass = "";
	vector<pair<int, int>> inv;
};
#define pi(peer) ((Player*)(peer->data))

struct PlayerMoving {
	int32_t netID, effect_flags_check;
	int packetType, characterState, plantingTree, punchX, punchY, secondnetID;
	float x, y, XSpeed, YSpeed;
	int packet_3, packet_int_40 = 0;
};

BYTE* packPlayerMoving(PlayerMoving* dataStruct, int size_ = 56, int some_extra = 0) {
	BYTE* data = new BYTE[size_];
	memset(data, 0, size_);
	memcpy(data + 0, &dataStruct->packetType, 4);
	memcpy(data + 3, &some_extra, 4);
	memcpy(data + 4, &dataStruct->netID, 4);
	memcpy(data + 12, &dataStruct->characterState, 4);
	memcpy(data + 20, &dataStruct->plantingTree, 4);
	memcpy(data + 24, &dataStruct->x, 4);
	memcpy(data + 28, &dataStruct->y, 4);
	memcpy(data + 32, &dataStruct->XSpeed, 4);
	memcpy(data + 36, &dataStruct->YSpeed, 4);
	memcpy(data + 40, &dataStruct->packet_int_40, 4);
	memcpy(data + 44, &dataStruct->punchX, 4);
	memcpy(data + 48, &dataStruct->punchY, 4);
	return data;
}


void send_raw(ENetPeer* peer, int a1, void* packetData, int packetDataSize, int packetFlag, int delay = 0) {
	ENetPacket* p;
	if (peer) {
		if (a1 == 4 && *((BYTE*)packetData + 12) & 8) {
			p = enet_packet_create(0, packetDataSize + *((DWORD*)packetData + 13) + 5, packetFlag);
			int four = 4;
			memcpy(p->data, &four, 4);
			memcpy((char*)p->data + 4, packetData, packetDataSize);
			memcpy((char*)p->data + packetDataSize + 4, 0, *((DWORD*)packetData + 13));
			if (delay != 0) {
				int deathFlag = 0x19;
				memcpy(p->data + 24, &delay, 4);
				memcpy(p->data + 56, &deathFlag, 4);
			}
		}
		else {
			p = enet_packet_create(0, packetDataSize + 5, packetFlag);
			memcpy(p->data, &a1, 4);
			memcpy((char*)p->data + 4, packetData, packetDataSize);
			if (delay != 0) {
				int deathFlag = 0x19;
				memcpy(p->data + 24, &delay, 4);
				memcpy(p->data + 56, &deathFlag, 4);
			}
		}
		enet_peer_send(peer, 0, p);
	}
}

void send_inventory(ENetPeer* peer) {
	size_t inv_size = (pi(peer)->inv.size() > 476 ? 476 : pi(peer)->inv.size());
	int packetLen = 66 + (inv_size * 4) + 4, MessageType = 0x4, PacketType = 0x9, NetID = -1, CharState = 0x8, state56 = 6 + (inv_size * 4) + 4, bruh = 1;
	BYTE* d_ = new BYTE[packetLen];
	memset(d_, 0, packetLen);
	memcpy(d_, &MessageType, 1);
	memcpy(d_ + 4, &PacketType, 4);
	memcpy(d_ + 8, &NetID, 4);
	memcpy(d_ + 16, &CharState, 4);
	memcpy(d_ + 56, &state56, 4);
	memcpy(d_ + 60, &bruh, 4);
	memcpy(d_ + 61, &inv_size, 4);
	memcpy(d_ + 65, &inv_size, 4);
	vector<pair<uint16_t, uint8_t>> send_later;
	int offset = 67;
	for (int i_ = 0; i_ < inv_size; ++i_) {
		if (pi(peer)->inv[i_].first == 9850 || pi(peer)->inv[i_].first == 5930 || pi(peer)->inv[i_].first == 9812 || pi(peer)->inv[i_].first == 7782 || pi(peer)->inv[i_].first == 9902 || pi(peer)->inv[i_].first == 9636 || pi(peer)->inv[i_].first == 9726 || pi(peer)->inv[i_].first == 9500 || pi(peer)->inv[i_].first == 9584 || pi(peer)->inv[i_].first == 9586 || pi(peer)->inv[i_].first == 9588 || pi(peer)->inv[i_].first == 9590 || pi(peer)->inv[i_].first == 9550 || pi(peer)->inv[i_].first == 9582 || pi(peer)->inv[i_].first == 9580 || pi(peer)->inv[i_].first == 9578 || pi(peer)->inv[i_].first == 9572 || pi(peer)->inv[i_].first == 9570 || pi(peer)->inv[i_].first == 9568 || pi(peer)->inv[i_].first == 9566 || pi(peer)->inv[i_].first == 9564 || pi(peer)->inv[i_].first == 9562 || pi(peer)->inv[i_].first == 9560 || pi(peer)->inv[i_].first == 9558 || pi(peer)->inv[i_].first == 9490 || pi(peer)->inv[i_].first == 9492 || pi(peer)->inv[i_].first == 9490 || pi(peer)->inv[i_].first == 9492 || pi(peer)->inv[i_].first == 9516 || pi(peer)->inv[i_].first == 9540) send_later.push_back(make_pair(pi(peer)->inv[i_].first, pi(peer)->inv[i_].second));
		else {
			*(__int16*)(d_ + offset) = pi(peer)->inv[i_].first; offset += 2;
			*(__int8*)(d_ + offset) = pi(peer)->inv[i_].second; offset += 2;
		}
	}
	ENetPacket* const p_ = enet_packet_create(d_, packetLen, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, p_);
	delete[] d_;
	if (send_later.size() > 0) {
		PlayerMoving data_{};
		data_.packetType = 13;
		for (int i = 0; i < send_later.size(); i++) {
			data_.plantingTree = send_later[i].first;
			BYTE* raw = packPlayerMoving(&data_);
			raw[3] = send_later[i].second;
			send_raw(peer, 4, raw, 56, ENET_PACKET_FLAG_RELIABLE);
			delete[]raw;
		}
	}
}

void send_packet(ENetPeer* peer, const void* data, uintmax_t data_size, uint32_t flags)
{
	ENetPacket* packet = enet_packet_create(data, data_size, flags);
	if (!packet)
		return;

	if (enet_peer_send(peer, 0, packet) != 0)
		enet_packet_destroy(packet);
}

void send_packet(ENetPeer* peer, uint32_t type, const void* data, uintmax_t data_size, uint32_t flags)
{
	ENetPacket* packet = enet_packet_create(nullptr, 5 + data_size, flags);
	if (!packet)
		return;

	memcpy(packet->data, &type, 4);
	packet->data[data_size + 4] = 0;

	if (data)
		memcpy(packet->data + 4, data, data_size);

	if (enet_peer_send(peer, 0, packet) != 0)
		enet_packet_destroy(packet);
}