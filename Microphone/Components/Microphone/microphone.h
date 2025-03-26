#ifndef MICROPHONE_H
#define MICROPHONE_H

#include <stdint.h>

void mp_init(void);
void mp_get_data(uint8_t *data, uint32_t size_data);

#endif // MICROPHONE_H