#ifndef FISTBUMP_H
#define FISTBUMP_H

typedef enum {
    FISTBUMP_IDLE,
    FISTBUMP_RESOLVING_DNS,
    FISTBUMP_CONNECTING_TCP,
    FISTBUMP_AWAITING_ID,
    FISTBUMP_SENDING_UDP,
    FISTBUMP_AWAITING_MATCH,
    FISTBUMP_MATCHED,
    FISTBUMP_ERROR,
} FistbumpState;

typedef struct NET_DatagramSocket NET_DatagramSocket;

typedef struct {
    int player;        // 1 or 2
    char ip[64];       // remote peer IP string
    int remote_port;   // remote peer game port (parsed from "ip:port")
} MatchResult;

void Fistbump_Start(const char* server_ip, int tcp_port, int udp_port);
void Fistbump_Run();
FistbumpState Fistbump_GetState();
const MatchResult* Fistbump_GetResult();  // valid when MATCHED
NET_DatagramSocket* Fistbump_GetSocket(); // ephemeral UDP socket, valid when MATCHED
void Fistbump_Reset();

#endif
