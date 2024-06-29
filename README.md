# WEMORSE
**Centralized Morse Code Communication**  
Group 3 | 4 ISA 3 | IoT project

![image](https://github.com/Qyuzet/Centralized-Morse-Code-Com.--WEMORSE/assets/93258081/cee3f852-7fd8-40a6-b2cf-9182426295ca)


## Team

- **Riki Awal Syahputra** (2120010136)
- **Faza Rama Nugraha** (2120010291)

## Table of Contents

1. [Project Overview](#project-overview)
2. [System Analysis](#system-analysis)
3. [Design Interface](#design-interface)
4. [Database Design](#database-design)
5. [Table Design](#table-design)
6. [Flow Diagram](#flow-diagram)
7. [Code Configuration](#code-configuration)
8. [Installation](#installation)
9. [Usage](#usage)
10. [Minimum Configuration](#minimum-configuration)
11. [Contribution Guidelines](#contribution-guidelines)
12. [License](#license)
13. [Acknowledgements](#acknowledgements)

## Project Overview

WEMORSE is a Java-based Android application built using the Kotlin framework, designed for secure and efficient Morse code communication. The system leverages the ESP8266 microcontroller to enable communication from anywhere with an internet connection, providing a scalable solution for secret reporting and secure messaging.

![image](https://github.com/Qyuzet/Centralized-Morse-Code-Com.--WEMORSE/assets/93258081/c2cb53a2-6df2-4c99-add4-420705a40ce3)

## System Analysis

### Overview

WEMORSE ensures secure communication through Morse code, ideal for secret reporting. Key features include:

- **Secret Reporting Communication:** Ensures messages are transmitted securely.
- **Scalable Security:** The system is flexible to upscale the security of communication as needed.
- **Powered by ESP8266:** Utilizes the ESP8266 microcontroller to enable communication from anywhere.

## Design Interface

### Main Node

The main node in the WEMORSE system acts as the central hub for communication, processing incoming Morse code signals, and relaying them to the appropriate recipients. The main node interface is designed to be user-friendly, providing clear and concise controls for sending and receiving messages.

## Database Design

### Structure

The database is structured to efficiently store user messages, including sender information, the message content, timestamps, and read/unread status. The design prioritizes quick retrieval and updating of messages to ensure real-time communication.

## Table Design

The table design is as follows:

| NO | Field Name | Data Type | Length | Description                     |
|----|-------------|-----------|--------|---------------------------------|
| 1  | id          | int       | -      | Unique identifier (primary key) |
| 2  | sender      | varchar   | 8      | Sender's name                   |
| 3  | msg         | varchar   | 40     | Message content                 |
| 4  | timestamp   | varchar   | 100    | Message timestamp               |
| 5  | flag        | int       | -      | Message status (0: unread, 1: read) |

## Flow Diagram

### General Flowchart

The general flowchart outlines the high-level processes of the WEMORSE system, including message input, processing, and output. It provides a visual representation of how messages flow through the system.

![image](https://github.com/Qyuzet/Centralized-Morse-Code-Com.--WEMORSE/assets/93258081/03a53468-6c35-447f-af70-d6bec17c38ba)

### Detailed Flowchart

The detailed flowchart breaks down each step of the process, including:

1. **Message Input:** User inputs a Morse code message.
2. **Message Processing:** The system decodes the Morse code, verifies the sender, and logs the message.
3. **Message Output:** The decoded message is sent to the intended recipient, and the status is updated.

![image](https://github.com/Qyuzet/Centralized-Morse-Code-Com.--WEMORSE/assets/93258081/87b5786c-9e2a-4f8e-a2f5-74e37268951d)

## Code Configuration

### ESP Code

The ESP8266 microcontroller handles the hardware aspect of WEMORSE. Key components include:

#### Initialize

- **Dictionary of Conversion:** Initializes Morse code conversion dictionaries and variables.

#### Init & Wifi Connect

- **WiFi Connection:** Connects the ESP8266 to the internet to enable communication.

#### Main Part

- **API Connection:** Manages the connection to the WEMORSE API for message transmission.
- **Actuator Action:** Executes any required actions based on received messages.

#### Function

- **Conversion Function:** Converts Morse code signals to readable text.
- **updateFlag Function:** Updates the message status flag (read/unread).

### Kotlin Code

The Kotlin code is responsible for the Android application's user interface and core functionality. Key activities include:

#### Main Activity

- **Main Interface:** Handles the main user interface, including message input and settings.

#### Activity WeMorse

- **Main Menu Creation:** Manages the creation of the main menu, providing access to different features of the app.

#### WeMorse Activity

- **Show Data Menu:** Displays received messages and their statuses, allowing users to review communication history.

## Installation

### Prerequisites

- **Android Studio:** Ensure you have Android Studio installed on your development machine.
- **ESP8266:** Ensure you have an ESP8266 microcontroller with the necessary firmware.

### Steps

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/yourusername/WEMORSE.git
   ```
2. **Open the Project in Android Studio:**
   - Navigate to the cloned repository and open the project in Android Studio.
3. **Configure the ESP8266:**
   - Follow the ESP8266 setup instructions in the `esp8266/` directory.
4. **Build and Run the Project:**
   - Build the project in Android Studio and deploy it to your Android device.

## Usage

1. **Launch the App:**
   - Open the WEMORSE app on your Android device.
2. **Connect to WiFi:**
   - Ensure the ESP8266 is connected to a WiFi network.
3. **Send a Message:**
   - Use the app interface to input and send a Morse code message.
4. **Receive a Message:**
   - Check the received messages in the app's message history.

## Minimum Configuration

### Hardware

- **Smartphone:** A smartphone capable of running Android applications.
- **ESP8266 Microcontroller:** For handling Morse code communication.

### Operating System

- **Android:** The app is compatible with Android operating systems.

### Software

- **WEMORSE Application:** The WEMORSE app must be installed on the smartphone.

## Contribution Guidelines

We welcome contributions from the community! To contribute:

1. **Fork the Repository:**
   - Click the 'Fork' button on the top right of the repository page.
2. **Clone Your Fork:**
   ```bash
   git clone https://github.com/Qyuzet/Centralized-Morse-Code-Com.--WEMORSE.git
   ```
3. **Create a Branch:**
   ```bash
   git checkout -b feature-branch
   ```
4. **Make Your Changes:**
   - Implement your feature or fix.
5. **Commit Your Changes:**
   ```bash
   git commit -m "Description of changes"
   ```
6. **Push to Your Fork:**
   ```bash
   git push origin feature-branch
   ```
7. **Create a Pull Request:**
   - Go to the original repository and create a pull request from your fork.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

We would like to thank our team members and supporters who contributed to the development of WEMORSE. Special thanks to our instructors and peers who provided valuable feedback and guidance throughout the project.
