#ifndef ARCHIPELAGO_HPP
#define ARCHIPELAGO_HPP

template <typename T> std::string int_to_hex(T i, int widthNumerator = 1, int widthDenomenator = 1);

void SCDAP_ResetAllItems();
void SCDAP_ReceiveItem(int64_t id, bool state);
void SDCAP_CheckLocation(int64_t location);
void SCDAP_SendItem();

void SCDAP_Init();
void SCDAP_Shutdown();

bool SCDAP_IsConnected();
const char *SCDAP_GetConnectionStatusAsString();

const std::string SCDAP_GenerateUUID(const int &activeStageList, const int &stageListPosition, const int &x, const int &y);

#endif
