#include <Archipelago.h>

void SCDAP_ResetAllItems() {}
void SCDAP_ReceiveItem(int64_t id, bool state) {}
void SDCAP_CheckLocation(int64_t location) {}

void SCDAP_Init() {
	AP_Init("localhost:38281", "Sonic CD", "Player1", "");
	AP_SetItemClearCallback(&SCDAP_ResetAllItems);
	AP_SetItemRecvCallback(&SCDAP_ReceiveItem);
	AP_SetLocationCheckedCallback(&SDCAP_CheckLocation);

	AP_Start();
}

void SCDAP_Shutdown() {
	AP_Shutdown();
}
