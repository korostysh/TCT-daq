#ifndef OSCILLOSCOPE_H
#define OSCILLOSCOPE_H

#include "include/Definition.h"
#include "include/Instrument.h"
#define OUR_SCOPE_IP            "192.168.1.2"

#define LECROY_SERVER_PORT      1861	/* as defined by LeCroy */

#define CMD_BUF_LEN             8192
#define MAX_TCP_CONNECT		5	/* time in secs to get a connection */
#define MAX_TCP_READ		5	/* time in secs to wait for the DSO
                       to respond to a read request */
#define BOOL                    int
#define TRUE                    1
#define FALSE                   0
#define LECROY_EOI_FLAG				0x01
#define LECROY_SRQ_FLAG				0x08
#define LECROY_CLEAR_FLAG			0x10
#define LECROY_LOCKOUT_FLAG			0x20
#define LECROY_REMOTE_FLAG			0x40
#define LECROY_DATA_FLAG			0x80

#define LECROY_READ_TIME_OUT			10

#define LECROY_TCP_MINIMUM_PACKET_SIZE		64






class Oscilloscope : public Instrument
{


public:
    Oscilloscope(ConnectionType pConectionType, std::string pAddress, std::string pName);
    ~Oscilloscope() {
        ;
    }
    void Initialize();
   std::vector<double> GetOsccilloscopeSignals(bool Ch1, bool Ch2, bool Ch3, bool Ch4);
private:

    void LECROY_TCP_bored_now(int);		/* catch signal routine */
    int LECROY_TCP_write(int, char *);
    int LECROY_TCP_read(int, char *, int, int);
    int LECROY_TCP_connect(char *, int);
    int LECROY_TCP_disconnect(int);
};

#endif // OSCILLOSCOPE_H
