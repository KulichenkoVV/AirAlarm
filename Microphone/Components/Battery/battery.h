
#ifndef BATTERY_H
#define BATTERY_H

#include <stdint.h>

void bat_init(void);
void bat_get_data(uint8_t *data, uint32_t size_data);

#endif // BATTERY_H