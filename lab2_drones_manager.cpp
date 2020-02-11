#include "lab2_drones_manager.h"

// TODO: Implement all of the listed functions below

DronesManager::DronesManager() {
}

DronesManager::~DronesManager() {
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	return (lhs.prev == rhs.prev) && (lhs.next == rhs.next) && (lhs.droneID == rhs.droneID) 
		&& (lhs.range == rhs.range) && (lhs.yearBought == rhs.yearBought);
}

unsigned int DronesManager::get_size() const {
	return 0;
}

bool DronesManager::empty() const {
	return false;
}
DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
	DroneRecord* curr = first;
	if (curr == NULL) {
		return DroneRecord(0);
	} else {
		for (int i = 1; i < (int)index && curr; i++) {
			curr = curr->next;
		}
	}
	return *curr;
}

unsigned int DronesManager::search(DroneRecord value) const {
	return 0;
}

void DronesManager::print() const {
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
	if (!first || index == 0) {
		insert_front(value);
		++size;
		return true;
	}
	else {
		DroneRecord* val = new DroneRecord(value);
		DroneRecord* curr = first;
		for (int i = 0; i < (int)index; i++) {
			if (!(curr->next)) {
				return false;
			}
			curr = curr->next;
		}
		value.prev = curr->prev;
		value.next = curr;
		++size;
		return true;
	}
}

bool DronesManager::insert_front(DroneRecord value) {
	return false;
}

bool DronesManager::insert_back(DroneRecord value) {
	return false;
}

bool DronesManager::remove(unsigned int index) {
	if (index == 0) {
		remove_front();
	}
	DroneRecord* curr = first;
	if (!curr) {
		return false;
	}
	for (int i = 0; i < (int)index; i ++) {
		if (!(curr->next)) {
			remove_back();
			--size;
			return true;	
		}
	}
	DroneRecord* back = curr->prev;
	back->next = curr->next;
	delete curr;
	curr = NULL;
	--size;
	return true;
}

bool DronesManager::remove_front() {
	return false;
}

bool DronesManager::remove_back() {
	return false;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	if (!first) {
		return false;	
	}
	else {
		DroneRecord* curr = first;
		for (int i = 0; i < (int)index && curr; i++) {
			if (!curr -> next) {
				return false;
			}
			curr = curr->next;
			
		}
		*curr = value;

		return true;
	}
}

bool DronesManager::reverse_list() {
	return false;
}

