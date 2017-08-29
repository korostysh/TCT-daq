#include "instruments/include/standa.h"
#include <libusb-1.0/libusb.h>
#include <limits>
#include <iostream>
#include <instruments/include/standa_types.h>

int getSerial(libusb_device_handle *udev){
    int serial = 0;
    int bytesToGet = 512;
    unsigned char data[512];
    int bytes = libusb_control_transfer(udev, 0xC0, 0xC9, 0x00, 0, &data[0], bytesToGet, 1000);
    for(int i = 0; i < bytes; i++){
        serial = serial*10 + (data[i]-'0');
    }
    return serial;
}


Standa::Standa(const int &serial)
{
    this->m_serial = serial;
    this->m_handle = nullptr;
    this->m_position = std::numeric_limits<double>::quiet_NaN();

    libusb_device **devices;
    int dev_cnt = libusb_get_device_list(NULL, &devices);

    libusb_device_descriptor desc;
    for(int i = 0; i < dev_cnt; i++){
        libusb_get_device_descriptor(devices[i], &desc);

        if (desc.idVendor == 0x10c4 && desc.idProduct == 0x0230){
            libusb_open(devices[i], &(this->m_handle));
            if (this->m_serial == getSerial(this->m_handle)){
                this->m_device = devices[i];
                libusb_ref_device(this->m_device);
                std::cout<<"Device found!"<<std::endl;
                break;
            }
            else{
                libusb_close(this->m_handle);
                this->m_handle = nullptr;
            }
        }
    }
    libusb_free_device_list(devices, 1);

    if (!this->m_handle){
        throw std::runtime_error("No device found");
        return;
    }

    this->getVersion();


}

Standa::~Standa()
{
    libusb_close(this->m_handle);
    this->m_handle = nullptr;
    libusb_unref_device(this->m_device);
    this->m_device = nullptr;
}

void Standa::getVersion()
{
    int version = 0;
    int requestType = USB_DIR_IN | LIBUSB_RECIPIENT_DEVICE | USB_TYPE_STANDARD;
    char request = 0x06;
    unsigned char data[12];
    int length = libusb_control_transfer(this->m_handle, requestType, request, 0x0304, 0x0409, data, 12, 1000);
    for(int i = 2; i < length; i++)
        version = version * 100 + data[i];
    m_version = version;
}

void Standa::Stop(){

    int requestType = USB_DIR_IN | LIBUSB_RECIPIENT_DEVICE | USB_TYPE_VENDOR;
    char request      = 0x07;
    unsigned char data[12];
    libusb_control_transfer(this->m_handle, requestType, request, 0x0000, 0x0000, data, 0x0000, 1000);
}

bool Standa::GetTrailler(){

    int requestType = USB_DIR_IN | LIBUSB_RECIPIENT_DEVICE | USB_TYPE_VENDOR;
    char request = 0x82;
    unsigned char data[12];
    libusb_control_transfer(this->m_handle, requestType, request, 0x0000, 0x0000, data, 12, 1000);
    unsigned char seventh = data[7];
    return (seventh&(1<<6))?true:false;
    //return (st.trailer1,st.trailer2)
}

bool Standa::IsMoving(){

    int requestType = USB_DIR_IN | LIBUSB_RECIPIENT_DEVICE | USB_TYPE_VENDOR;
    char request = 0x82;
    unsigned char data[12];
    libusb_control_transfer(this->m_handle, requestType, request, 0x0000, 0x0000, data, 12, 1000);
    unsigned char seventh = data[7];
    return (seventh&1)?true:false;
    //return (st.trailer1,st.trailer2)
}

int Standa::getCurrentPosition()
{
    int requestType = USB_DIR_IN | LIBUSB_RECIPIENT_DEVICE | USB_TYPE_VENDOR;
    char request = 0x82;
    unsigned char data[12];
    libusb_control_transfer(this->m_handle, requestType, request, 0x0000, 0x0000, data, 12, 1000);
    int *position = reinterpret_cast<int*>(data);
    std::cout<<(*position)/8<<std::endl;
    return (*position)/8;
}

void Standa::setNewPosition(int position, int speed)
{
    auto data = goto_data(position, speed, 1, false, false, true, false, false, false);
    int requestType = USB_DIR_OUT | LIBUSB_RECIPIENT_DEVICE | USB_TYPE_VENDOR;
    char request = 0x80;
    __uint16_t length = 0x0003;
    __uint16_t wValue = data.lowerWord();
    __uint16_t wIndex = data.upperWord();
    unsigned char* buffer = reinterpret_cast<unsigned char*>(&data);
    libusb_control_transfer(this->m_handle, requestType, request, wValue, wIndex, reinterpret_cast<unsigned char*>(&data)+4, length, 1000);
}
