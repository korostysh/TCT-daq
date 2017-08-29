#ifndef STANDA_H
#define STANDA_H
#include <libusb-1.0/libusb.h>

const char USB_DIR_IN = 0x80;
const char USB_DIR_OUT = 0x00;
const char USB_TYPE_STANDARD = 0x00;
const char USB_TYPE_VENDOR = 64;

class Standa
{
    int m_version;
    int m_serial;
    float m_position;
    libusb_device *m_device;
    libusb_device_handle *m_handle;

public:
    Standa(const int &serial);
    ~Standa();
    bool IsMoving();
    bool GetTrailler();
    void getVersion();
    void Stop();
    int getCurrentPosition();
    void setNewPosition(int position, int speed);
};

#endif // STANDA_H
