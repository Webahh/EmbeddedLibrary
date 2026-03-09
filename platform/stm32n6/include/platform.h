#pragma once

/* Platform hooks (later: clocks, VTOR, cache, etc.) */
void platform_init_early(void);
void platform_init_late(void);