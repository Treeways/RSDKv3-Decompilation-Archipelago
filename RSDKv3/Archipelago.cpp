#include <Archipelago.h>
#include "Archipelago.hpp"

bool connecting = false;

template <typename T> std::string int_to_hex(T i, int widthNumerator, int widthDenomenator) {
	if (std::is_same<T, int>::value) {
		std::stringstream stream;
		stream << std::setfill('0') << std::setw(sizeof(T) * widthNumerator / widthDenomenator) << std::uppercase
			<< std::hex << static_cast<unsigned long long>(i);
		return stream.str();
	}
	return "";
}

void SCDAP_ResetAllItems() {} // TODO
void SCDAP_ReceiveItem(int64_t id, bool state) {} // TODO
void SDCAP_CheckLocation(int64_t location) {} // TODO

void SCDAP_SendItem(int64_t location) {
	AP_SendItem(location);
}

void SCDAP_Init() {
	AP_Init("localhost:38281", "Sonic CD", "Player1", ""); // TODO: Make this dynamic
	AP_SetItemClearCallback(&SCDAP_ResetAllItems);
	AP_SetItemRecvCallback(&SCDAP_ReceiveItem);
	AP_SetLocationCheckedCallback(&SDCAP_CheckLocation);

	AP_Start();
}

void SCDAP_Shutdown() {
	AP_Shutdown();
}

/// @brief Is Archipelago connected, or did it refuse a connection recently?
/// @return True if currently authenticated or connected, false if rejected or disconnected
bool SCDAP_IsConnected() {
	AP_ConnectionStatus connection_status = AP_GetConnectionStatus();

	if (connection_status == AP_ConnectionStatus::Authenticated ||
	    connection_status == AP_ConnectionStatus::Connected)
		return true;
	return false;
}

const char* SCDAP_GetConnectionStatusAsString() {
	switch (AP_GetConnectionStatus()) {
		case AP_ConnectionStatus::Disconnected:
			return "Disconnected";
			break;
		case AP_ConnectionStatus::Connected:
			return "Connected";
			break;
		case AP_ConnectionStatus::Authenticated:
			return "Authenticated";
			break;
		case AP_ConnectionStatus::ConnectionRefused:
			return "ConnectionRefused";
			break;
	}
	return "Unknown";
}

const std::string SCDAP_GenerateUUID(const int &activeStageList, const int &stageListPosition, const int &x, const int &y) {
	std::stringstream stream;
	// stream << activeStageList << " " << int_to_hex(stageListPosition, 1, 2) << " " << int_to_hex(x) << " " << int_to_hex(y);
	stream << activeStageList << int_to_hex(stageListPosition, 1, 2) << int_to_hex(x) << int_to_hex(y);
	return stream.str();
}
