
#ifndef INDICATION_H
#define INDICATION_H

#include <stdint.h>

void indic_init(void);
void indic_get_data(uint8_t *data, uint32_t size_data);

#endif // INDICATION_H