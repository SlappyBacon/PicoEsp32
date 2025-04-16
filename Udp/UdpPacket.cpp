#include "UdpPacket.h"
UdpPacket::UdpPacket() {
	IPAddress emptyAddress;
	remoteIpAddress_ = emptyAddress;
	
	remotePort_ = 0;

	char emptyData[0];
	data_ = emptyData;
}
UdpPacket::UdpPacket(IPAddress aRemoteIpAddress, unsigned int aRemotePort, char * aData) {
	remoteIpAddress_ = aRemoteIpAddress;
	remotePort_ = aRemotePort;
	data_ = aData;
}
const IPAddress UdpPacket::remoteIpAddress() {
	return remoteIpAddress_;
}
const unsigned int UdpPacket::remotePort() {
	return remotePort_;
}
const char * UdpPacket::data() {
	return data_;
}
bool UdpPacket::operator == (const UdpPacket & compareTo) {
	if (remoteIpAddress_ != compareTo.remoteIpAddress_) return false;
	if (remotePort_ != compareTo.remotePort_) return false;
	if (sizeof(data_) != sizeof(compareTo.data_)) return false;
	for (int i = 0; i < sizeof(data_); i++) {
		if (data_[i] != compareTo.data_[i]) return false;
	}
	return true;
}
const UdpPacket UdpPacket::empty = UdpPacket();