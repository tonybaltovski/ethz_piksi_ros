#ifndef PIKSI_MULTI_CPP_DEVICE_DEVICE_USB_H_
#define PIKSI_MULTI_CPP_DEVICE_DEVICE_USB_H_

#include <libserialport.h>
#include "piksi_multi_cpp/device/device.h"

namespace piksi_multi_cpp {

class DeviceUSB : public Device {
 public:
  DeviceUSB(const SerialNumber& id);

  // List all unique Piksi multi devices using the usb serial number.
  static SerialNumbers discoverAllSerialNumbers();
  bool open() override;
  int32_t read(uint8_t* buff, uint32_t n) const override;
  void close() override;

 private:
  static SerialNumber identifyPiksiAndGetSerialNumber(struct sp_port* port);
  static void printDeviceInfo(struct sp_port* port);
  static void printPorts();
  bool allocatePort();

  struct sp_port* port_;
};
}  // namespace piksi_multi_cpp

#endif  // PIKSI_MULTI_CPP_DEVICE_DEVICE_USB_H_