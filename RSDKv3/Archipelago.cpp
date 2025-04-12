#include <Archipelago.h>

void clear_item_states() {}
void add_item_to_state(int64_t id, bool state) {}
void mark_location_checked(int64_t location) {}

void init_archipelago() {
	AP_Init("localhost:38281", "Clique", "Player1", "");
	AP_SetItemClearCallback(clear_item_states);
	AP_SetItemRecvCallback(add_item_to_state);
	AP_SetLocationCheckedCallback(mark_location_checked);

	AP_Start();
}
