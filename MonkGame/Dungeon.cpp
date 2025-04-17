#include "Dungeon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>


Dungeon::Dungeon() {
    std::srand(std::time(nullptr)); // seed for randomness
}

void Dungeon::generate() {
    // 1) Create the treasure room and keep it aside
    auto treasureRoom = RoomFactory::createRoom("Treasure");

    // 2) Build the list of the other required rooms
    std::vector<std::shared_ptr<Room>> tempRooms;
    tempRooms.push_back(RoomFactory::createRoom("Empty"));
    tempRooms.push_back(RoomFactory::createRoom("Upgrade"));
    tempRooms.push_back(RoomFactory::createRoom("Monster"));
    tempRooms.push_back(RoomFactory::createRoom("Monster"));

    // Optional extra rooms
    std::vector<std::string> extraTypes = { "Empty", "Monster", "Upgrade" };
    int extraCount = std::rand() % 3;  // 0–2 extra
    for (int i = 0; i < extraCount; ++i) {
        tempRooms.push_back(RoomFactory::createRoom(
            extraTypes[std::rand() % extraTypes.size()]
        ));
    }

    // 3) Shuffle only these other rooms
    std::shuffle(
        tempRooms.begin(), tempRooms.end(),
        std::mt19937{ std::random_device{}() }
    );

    // 4) Move them into the dungeon’s room list…
    rooms = std::move(tempRooms);

    // …then append the treasure room at the end
    rooms.push_back(treasureRoom);

    // 5) Connect them in sequence (linear graph)
    connectRooms();

    // 6) Your start is still the first room
    startingRoom = rooms[0];
}


void Dungeon::connectRooms() {
    // Unidirectional: room[i] → room[i+1] only
    for (size_t i = 0; i + 1 < rooms.size(); ++i) {
        rooms[i]->addConnection(rooms[i + 1]);
    }
}


void Dungeon::explore() {
    auto currentRoom = startingRoom;
    while (true) {
        currentRoom->onEnter();

        // If we have no forward connections, we're at the end (treasure or dead‑end)
        const auto& connections = currentRoom->getConnectedRooms();
        if (connections.empty()) {
            std::cout << "No more rooms to explore. Game over!\n";
            break;
        }

        // Otherwise list your one (or more, if extras) forward paths
        std::cout << "\nConnected rooms:\n";
        for (size_t i = 0; i < connections.size(); ++i) {
            std::cout << i + 1 << ". " << connections[i]->getType() << "\n";
        }

        std::cout << "Choose a room to go to (0 to quit): ";
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "Exiting exploration.\n";
            break;
        }
        else if (choice > 0 && choice <= static_cast<int>(connections.size())) {
            currentRoom = connections[choice - 1];
        }
        else {
            std::cout << "Invalid choice, try again.\n";
        }
    }
}

