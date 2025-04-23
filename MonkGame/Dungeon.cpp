#include "Dungeon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

Dungeon::Dungeon() {
    std::srand(std::time(nullptr)); // Seed for randomness
}

void Dungeon::generate() {
    // 1) Create the treasure room and keep it aside
    auto treasureRoom = RoomFactory::createRoom("Treasure");

    // 2) Build the list of other required rooms
    std::vector<std::shared_ptr<Room>> tempRooms;
    tempRooms.push_back(RoomFactory::createRoom("Empty"));
    tempRooms.push_back(RoomFactory::createRoom("Upgrade"));
    tempRooms.push_back(RoomFactory::createRoom("Monster"));
    tempRooms.push_back(RoomFactory::createRoom("Monster"));

    // Optional extra rooms
    std::vector<std::string> extraTypes = { "Empty", "Monster", "Upgrade" };
    int extraCount = std::rand() % 3;  // 0–2 extra rooms
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

    // 4) Add the rooms to the dungeon
    rooms = std::move(tempRooms);

    // Append the treasure room at the end
    rooms.push_back(treasureRoom);

    // 5) Connect them in sequence
    connectRooms();

    // 6) Set the start room
    startingRoom = rooms[0];
}

void Dungeon::connectRooms() {
    for (size_t i = 0; i + 1 < rooms.size(); ++i) {
        rooms[i]->addConnection(rooms[i + 1]);
    }
}

void Dungeon::explore(std::shared_ptr<Monk> monk) {
    // Set up HUD and attach it as an observer
    hud = std::make_shared<HUD>(monk);

    auto currentRoom = startingRoom;

    while (true) {
        // Check if Monk is still alive before continuing
        if (!monk->isAlive()) {
            std::cout << monk->getName() << " has died. Game over!\n";
            break;
        }

        // HUD updates automatically via observer, no need for manual display

        // Enter the current room and perform the action
        currentRoom->onEnter(*monk);

        // If there are no more connections, the game ends
        const auto& connections = currentRoom->getConnectedRooms();
        if (connections.empty()) {
            std::cout << "\nNo more rooms to explore. Game over!\n";
            break;
        }

        // Show connected rooms for navigation
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
