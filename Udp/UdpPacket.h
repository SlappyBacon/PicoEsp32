#ifndef _UdpPacket_h
#define _UdpPacket_h
#include <IPAddress.h>
class UdpPacket {
private:
	IPAddress remoteIpAddress_;
	unsigned int remotePort_;
	char * data_;
	UdpPacket();
public:
	UdpPacket(IPAddress remoteIpAddress, unsigned int remotePort, char * data);
	const IPAddress remoteIpAddress();
	const unsigned int remotePort();
	const char* data();
	bool operator == (const UdpPacket & compareTo);
	static const UdpPacket empty;
};
#endif

