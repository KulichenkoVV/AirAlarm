#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>

void button_init(void);
void button_get_data(uint8_t *data, uint32_t size_data);

#endif // BUTTON_H