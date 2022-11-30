#ifndef __ANDROID_LEDS_INTERFACE_H__
#define __ANDROID_LEDS_INTERFACE_H__
#include <hardware/hardware.h>
#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

#define LEDS_HARDWARE_MODULE_ID "leds"

#define LEDS_HEADER_VERSION 1

#define LEDS_DEVICE_API_VERSION_1_0 \
  HARDWARE_DEVICE_API_VERSION_2(1, 0, LEDS_HEADER_VERSION)

#define LEDS_DEVICE_API_VERSION_2_0 \
  HARDWARE_DEVICE_API_VERSION_2(2, 0, LEDS_HEADER_VERSION)

#define LED_ID_USER "user"
#define LED_ID_POWER "power"

struct led_state_t {
  unsigned int maxBrightness;
  unsigned int minBrightness;
  unsigned int brightness;
};

struct led_device_t {
  struct hw_device_t common;
  int (*setBrightnessValue)(struct led_device_t *dev,
                            struct led_state_t const *state);
  unsigned int (*getBrightnessRange)(struct led_device_t *dev);
};
__END_DECLS
#endif  // __ANDROID_LEDS_INTERFACE_H__