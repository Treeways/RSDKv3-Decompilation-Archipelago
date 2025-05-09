#include <cstdint>

void SCDAP_ResetAllItems();
void SCDAP_ReceiveItem(int64_t id, bool state);
void SDCAP_CheckLocation(int64_t location);
void SCDAP_SendItem();


void SCDAP_Init();
void SCDAP_Shutdown();

bool SCDAP_IsConnected();
const char* SCDAP_GetConnectionStatusAsString();
